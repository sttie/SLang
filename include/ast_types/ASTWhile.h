#pragma once

#include "../ast.h"


class ASTWhile : public ASTNode {
public:
    using ASTNode::Statements;

    ASTWhile(size_t lineno);
    ~ASTWhile() = default;

    void AddCondition(std::unique_ptr<ASTNode> condition_node_);
    void AddStatements(Statements statements_);

    Type Evaluate() const override;

private:
    void EvaluateStatements() const;

    std::unique_ptr<ASTNode> condition_node;
    Statements statements;
};