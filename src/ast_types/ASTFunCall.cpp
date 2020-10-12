#include "../../include/ast_types/ASTFunCall.h"
#include "../../include/ast_types/ASTFunction.h"

using namespace std;


ASTFunCall::ASTFunCall(string func_id_, size_t lineno_)
    : ASTNode(lineno_), func_id(move(func_id_))
{
}

void ASTFunCall::AddArgs(vector<unique_ptr<ASTNode>> args_) {
    args = move(args_);
}

Type ASTFunCall::Evaluate() const {
    // If the func_id function is not defined
    if (!func_table.count(func_id)) {
        ThrowSemanticError(func_id + " is not defined");
    }

    // Load arguments to arguments stack
    call_stack.push_back(left_argument);
    left_argument = right_argument;
    right_argument += args.size();

    for (const auto& argument : args) {
        func_stack.push_back(argument->Evaluate());
    }

    // call ASTFunction from function's table
    return func_table[func_id]->Evaluate();
}