#include "../../include/ast_types/ASTWhile.h"

using namespace std;


ASTWhile::ASTWhile(size_t lineno)
    : ASTNode(lineno)
{
}


void ASTWhile::AddCondition(std::unique_ptr<ASTNode> condition_node_) {
    condition_node = move(condition_node_);
}

void ASTWhile::AddStatements(Statements statements_) {
    statements = move(statements_);
}


void ASTWhile::EvaluateStatements() const {
    for (auto& node : statements) {
        node->Evaluate();
    }
}


Type ASTWhile::Evaluate() const {
    while (condition_node->Evaluate()) {
        EvaluateStatements();
    }

    return Type();
}