#pragma once

#include "../ast.h"
#include "../type.h"

#include <string>


class ASTInput : public ASTNode {
public:
    ASTInput(std::string input_id_, size_t lineno_);

    Type Evaluate() const;

private:
    std::string input_id;
};