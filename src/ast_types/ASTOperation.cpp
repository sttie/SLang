#include "../../include/ast_types/ASTOperation.h"

#include <stdexcept>

using namespace std;


ASTOperation::ASTOperation(string operation_, size_t lineno_)
        : ASTNode(lineno_), operation(move(operation_))
{
}

ASTOperation::ASTOperation(size_t lineno_)
        : ASTNode(lineno_)
{
}

string ASTOperation::Operation() const {
    return operation;
}

void ASTOperation::SetOperation(string operation_) {
    operation = move(operation_);
}

Type ASTOperation::Evaluate() const {
    Type left = children[0]->Evaluate();
    Type right = children.size() > 1 ? children[1]->Evaluate() : Type();

    if (operation == "+") {
        return left + right;
    }
    if (operation == "-") {
        return left - right;
    }
    if (operation == "*") {
        return left * right;
    }
    if (operation == "/") {
        return left / right;
    }
    if (operation == "<") {
        return left < right;
    }
    if (operation == ">") {
        return left > right;
    }
    if (operation == "<=") {
        return left <= right;
    }
    if (operation == ">=") {
        return left >= right;
    }
    if (operation == "==") {
        return left == right;
    }
    if (operation == "!=") {
        return left != right;
    }
    if (operation == "and") {
        return left && right;
    }
    if (operation == "or") {
        return left || right;
    }
    if (operation == "not") {
        return !left;
    }

    throw logic_error("Unexpected operation: " + operation);
}