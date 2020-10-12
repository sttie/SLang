#pragma once

#include "../ast.h"


class TrueIfException : public std::exception {};

class ASTIf : public ASTNode {
public:
    using Statements = ASTNode::Statements;

    ASTIf(size_t lineno_, bool is_main_if_ = false);
    ~ASTIf() = default;

    void AddCondition(std::unique_ptr<ASTNode> condition_node_);
    void AddElif(std::unique_ptr<ASTNode> elif_node_);
    void AddElseStatements(Statements else_statements_);
    void AddStatements(Statements statements_);

    Type Evaluate() const override;

private:
    void EvaluateStatements(const Statements& statements_) const;

    std::unique_ptr<ASTNode> condition_node;
    Statements statements;
    Statements elif_nodes;
    Statements else_statements;
    bool is_main_if;
};