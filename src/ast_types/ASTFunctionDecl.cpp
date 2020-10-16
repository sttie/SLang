#include "../../include/ast_types/ASTFunctionDecl.h"
#include "../../include/ast_types/ASTReturn.h"
#include <algorithm>

using namespace std;


ASTFunctionDecl::ASTFunctionDecl(string func_id_, string return_type_, size_t lineno_)
        : ASTNode(lineno_),
          func_id(move(func_id_)),
          return_type(move(return_type_)),
          func_context(FunctionContext::GetContext())
{
    // If the <func_id> function is already defined
    if (func_context.FuncTable().count(func_id)) {
        ThrowSemanticError(func_id + " function is already defined");
    }
}

void ASTFunctionDecl::AddParameters(vector<ParameterByPair> parameters_) {
    for (auto& pair_parameter : parameters_) {
        parameters.push_back({
            move(pair_parameter.first), move(pair_parameter.second)
        });
    }
}

void ASTFunctionDecl::AddStatements(Statements statements_) {
    statements = move(statements_);
}

Type ASTFunctionDecl::Evaluate() const {
    InitializeParameters();

    for (const auto& node : statements) {
        try {
            node->Evaluate();
        } catch (const ReturnException& return_exception) {
            ThrowIfReturnTypeMismatch(return_exception.returned_value);
            // Restoration of the old symtable
            RestoreSymtable();
            return return_exception.returned_value;
        }
    } // make EvaluateStatements func

    // If we didnt get a return statement
    ThrowIfNotVoid();
    RestoreSymtable();
    // Just void
    return Type();
}


// в func_stack должны находиться объекты Type!
void ASTFunctionDecl::InitializeParameters() const {
    SaveSymtableOnStack();
    auto& arguments_stack = func_context.ArgumentsStack();
    auto& borders_stack = func_context.BordersStack();
    size_t& left_argument = func_context.LeftArgument();
    size_t& right_argument = func_context.RightArgument();

    if (right_argument - left_argument > parameters.size()) {
        ThrowSemanticError("too much arguments for " + func_id + " function");
    }
    if (right_argument - left_argument < parameters.size()) {
        ThrowSemanticError("too few arguments for " + func_id + " function");
    }

    for (size_t i = left_argument; i < right_argument; i++) {
        ThrowIfArgTypeMismatch(
                arguments_stack[i].GetStringTypeName(),
                parameters[i].type,
                i);

        symtable->UpdateTable(parameters[i].name,
                              arguments_stack[i]);
    }

    // Восстанавливаем состояние стека
    right_argument = left_argument;
    left_argument = borders_stack.empty() ? 0 : borders_stack.back();
    borders_stack.pop_back();
    arguments_stack.erase(arguments_stack.end() - parameters.size(), arguments_stack.end());
}

void ASTFunctionDecl::RestoreSymtable() const {
    auto& symtable_func_table = func_context.SymtableFuncStack();
    symtable = move(symtable_func_table.back());
    symtable_func_table.pop_back();
}

void ASTFunctionDecl::SaveSymtableOnStack() const {
    // Saving old symtable
    func_context.SymtableFuncStack().push_back(move(symtable));
    // Function will see only its arguments
    symtable = MakeNewSymTable();
}

void ASTFunctionDecl::ThrowIfReturnTypeMismatch(const Type& returned_value) const {
    string returned_typename = returned_value.GetStringTypeName();
    if (returned_typename != return_type) {
        ThrowSemanticError("\"" + func_id + "\" returns \"" + return_type +
                           "\", but \"" +
                           returned_typename +
                           "\" is returning");
    }
}

void ASTFunctionDecl::ThrowIfNotVoid() const {
    if (return_type != "void") {
        ThrowSemanticError("No return statement with \"" +
                           return_type + "\" return type of the \"" +
                           func_id + "\" function");
    }
}


void ASTFunctionDecl::ThrowIfArgTypeMismatch(
        const string& top_arg_typename,
        const string& current_parameter_typename,
        size_t i) const {
    if (top_arg_typename != parameters[i].type) {
        ThrowSemanticError("Type mismatch for " +
                           to_string(i) + "th parameter: got \""
                           + top_arg_typename
                           + ", but expected " + current_parameter_typename);
    }
}