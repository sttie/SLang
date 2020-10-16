#pragma once

#include <vector>
#include <map>
#include <memory>
#include <list>
#include <functional>
#include <iostream>

#include "type.h"
#include "symtable.h"


class FuncTable;

// Base node class
class ASTNode {
public:
    using SymTablePtr = std::unique_ptr<SymTable>;
    using Statements = std::list<std::unique_ptr<ASTNode>>;

    ASTNode(size_t lineno_);
    virtual ~ASTNode() = default;

    void AddChild(std::unique_ptr<ASTNode> child);
    void AddChildren(std::vector<std::unique_ptr<ASTNode>> children);

    std::unique_ptr<ASTNode>& GetChild(size_t index);
    size_t GetLine() const;

    virtual Type Evaluate() const = 0;

    static SymTablePtr symtable;

protected:
    void ThrowSemanticError(const std::string& error_message) const;

    std::vector<std::unique_ptr<ASTNode>> children;
    size_t lineno;
};


class ASTAssignment;
class ASTFunctionDecl;
class ASTFunCall;
class ASTIf;
class ASTOperation;
class ASTPrint;
class ASTReturn;
class ASTVariable;
class ASTWhile;