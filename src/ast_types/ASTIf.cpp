#include "../../include/ast_types/ASTIf.h"

using namespace std;


ASTIf::ASTIf(size_t lineno_, bool is_main_if_)
    : ASTNode(lineno_), is_main_if(is_main_if_)
{
}

void ASTIf::AddCondition(std::unique_ptr<ASTNode> condition_node_) {
    condition_node = move(condition_node_);
}

void ASTIf::AddElif(std::unique_ptr<ASTNode> elif_node_) {
    elif_nodes.push_back(move(elif_node_));
}

void ASTIf::AddElseStatements(Statements else_statements_) {
    else_statements = move(else_statements_);
}

void ASTIf::AddStatements(Statements statements_) {
    statements = move(statements_);
}


void ASTIf::EvaluateStatements(const Statements& statements_) const {
    for (auto& node : statements_) {
        node->Evaluate();
    }
}


Type ASTIf::Evaluate() const {
    // New scope
    symtable = MakeNewSymTable(move(symtable));

    if (condition_node->Evaluate()) {
        EvaluateStatements(statements);
        if (!is_main_if)
            throw TrueIfException();
    }

    for (const auto& elif_node : elif_nodes) {
        try {
            elif_node->Evaluate();
        }
        catch (const TrueIfException& if_exception) {
            return Type();
        }
    }

    EvaluateStatements(else_statements);
    return Type();
}