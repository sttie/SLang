#include "../../include/ast_types/ASTFunCall.h"
#include "../../include/ast_types/FunctionContext.h"

using namespace std;


ASTFunCall::ASTFunCall(string func_id_, size_t lineno_)
    : ASTNode(lineno_), func_id(move(func_id_))
{
}

void ASTFunCall::AddArgs(vector<unique_ptr<ASTNode>> args_) {
    args = move(args_);
}

Type ASTFunCall::Evaluate() const {
    auto& func_context = FunctionContext::GetContext();

    if (func_context.BuiltinFuncTable().count(func_id)
                && func_context.BuiltinFuncTable()[func_id].second == args.size()) {
        // TODO: init with lambda?
        vector<Type> type_arguments;
        for (const auto& arg : args) {
            type_arguments.push_back(arg->Evaluate());
        }
        return func_context.BuiltinFuncTable()[func_id].first(type_arguments);;
    }

    // If the func_id function is not defined
    if (!func_context.FuncTable().count(func_id)) {
        ThrowSemanticError(func_id + " is not defined");
    }

    // Load arguments to arguments stack
    size_t& left_argument = func_context.LeftArgument();
    size_t& right_argument = func_context.RightArgument();
    func_context.BordersStack().push_back(left_argument);
    left_argument = right_argument;
    right_argument += args.size();

    for (const auto& argument : args) {
        func_context.ArgumentsStack().push_back(argument->Evaluate());
    }

    // call ASTFunctionDecl from function's table
    return func_context.FuncTable()[func_id]->Evaluate();
}