#pragma once

#include "../ast.h"

// ASTFunCall's children is its arguments (ASTVariable)
class ASTFunCall : public ASTNode {
public:
    ASTFunCall(std::string func_id_, size_t lineno_);
    ~ASTFunCall() = default;

    void AddArgs(std::vector<std::unique_ptr<ASTNode>> args_);

    Type Evaluate() const;

private:
    std::string func_id;
    mutable std::vector<std::unique_ptr<ASTNode>> args;
};