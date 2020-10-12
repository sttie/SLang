#pragma once

#include "../ast.h"


class ASTPrint : public ASTNode {
public:
    ASTPrint(size_t lineno);
    ~ASTPrint() = default;

    Type Evaluate() const override;
};