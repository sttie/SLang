#pragma once

#include "../ast.h"


class ASTOperation : public ASTNode {
public:
    ASTOperation(std::string operation_, size_t lineno_);
    explicit ASTOperation(size_t lineno_);
    ~ASTOperation() = default;

    std::string Operation() const;
    void SetOperation(std::string operation_);

    Type Evaluate() const override;

private:
    std::string operation;
};