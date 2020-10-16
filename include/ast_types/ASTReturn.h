#pragma once

#include "../ast.h"

// We can use ReturnException to stop evaluating statements from ASTFunctionDecl
class ReturnException : public std::exception {
public:
    ReturnException(Type returned_value_);
    Type returned_value;
};

class ASTReturn : public ASTNode {
public:
    ASTReturn(std::unique_ptr<ASTNode> return_expr_, size_t lineno_);
    ~ASTReturn() = default;

    Type Evaluate() const override;

private:
    std::unique_ptr<ASTNode> return_expr;
};