#include "../../include/ast_types/ASTFunction.h"
#include "../../include/ast_types/ASTReturn.h"
#include <algorithm>

using namespace std;


ASTFunction::ASTFunction(string func_id_, string return_type_, size_t lineno_)
        : ASTNode(lineno_),
          func_id(move(func_id_)),
          return_type(move(return_type_))
{
    // If the <func_id> function is already defined
    if (func_table.count(func_id)) {
        ThrowSemanticError(func_id + " function is already defined");
    }
}

void ASTFunction::AddParameters(vector<ParameterByPair> parameters_) {
    for (auto& pair_parameter : parameters_) {
        parameters.push_back({
            move(pair_parameter.first), move(pair_parameter.second)
        });
    }
}

void ASTFunction::AddStatements(Statements statements_) {
    statements = move(statements_);
}

Type ASTFunction::Evaluate() const {
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
void ASTFunction::InitializeParameters() const {
    SaveSymtableOnStack();

    if (right_argument - left_argument > parameters.size()) {
        ThrowSemanticError("too much arguments for " + func_id + " function");
    }
    if (right_argument - left_argument < parameters.size()) {
        ThrowSemanticError("too few arguments for " + func_id + " function");
    }

    for (size_t i = left_argument; i < right_argument; i++) {
        ThrowIfArgTypeMismatch(
                func_stack[i].GetStringTypeName(),
                parameters[i].type,
                i);

        symtable->UpdateTable(parameters[i].name,
                              func_stack[i]);
    }

    // Восстанавливаем состояние стека
    right_argument = left_argument;
    left_argument = call_stack.empty() ? 0 : call_stack.back();
    call_stack.pop_back();
    func_stack.erase(func_stack.end() - parameters.size(), func_stack.end());
}

void ASTFunction::RestoreSymtable() {
    symtable = move(symtable_func_stack.back());
    symtable_func_stack.pop_back();
}

void ASTFunction::SaveSymtableOnStack() {
    // Saving old symtable
    symtable_func_stack.push_back(move(symtable));
    // Function will see only its arguments
    symtable = MakeNewSymTable();
}

void ASTFunction::ThrowIfReturnTypeMismatch(const Type& returned_value) const {
    string returned_typename = returned_value.GetStringTypeName();
    if (returned_typename != return_type) {
        ThrowSemanticError("\"" + func_id + "\" returns \"" + return_type +
                           "\", but \"" +
                           returned_typename +
                           "\" is returning");
    }
}

void ASTFunction::ThrowIfNotVoid() const {
    if (return_type != "void") {
        ThrowSemanticError("No return statement with \"" +
                           return_type + "\" return type of the \"" +
                           func_id + "\" function");
    }
}


void ASTFunction::ThrowIfArgTypeMismatch(
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