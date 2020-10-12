#pragma once

#include "../ast.h"


// The first constructor is for vars, the second one is for constants
class ASTVariable : public ASTNode {
public:
    ASTVariable(std::string id_, size_t lineno_);
    ASTVariable(Type value_, size_t lineno_);
    ~ASTVariable() = default;

    Type Evaluate() const override;

private:
    std::string id;
    Type value;
};