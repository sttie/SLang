#pragma once

#include <vector>
#include <map>
#include <memory>
#include <list>
#include <iostream>

#include "type.h"
#include "symtable.h"

class FuncTable;

// Base node class
class ASTNode {
public:
    using SymTablePtr = std::unique_ptr<SymTable>;
    using FuncTable = std::map<std::string, std::unique_ptr<ASTNode>>;
    using ArgumentsStack = std::vector<Type>;
    using Statements = std::list<std::unique_ptr<ASTNode>>;

    ASTNode(size_t lineno_);
    virtual ~ASTNode() = default;

    void AddChild(std::unique_ptr<ASTNode> child);
    void AddChildren(std::vector<std::unique_ptr<ASTNode>> children);

    std::unique_ptr<ASTNode>& GetChild(size_t index);
    size_t GetLine() const;

    virtual Type Evaluate() const = 0;

    static SymTablePtr symtable;
    static std::vector<SymTablePtr> symtable_func_stack;
    static FuncTable func_table;
    static ArgumentsStack func_stack;
    static size_t left_argument;
    static size_t right_argument;
    static std::vector<size_t> call_stack;

    static void InitStaticValues();

protected:
    void ThrowSemanticError(const std::string& error_message) const;

    std::vector<std::unique_ptr<ASTNode>> children;
    size_t lineno;
};


class ASTAssignment;
class ASTFunction;
class ASTFunCall;
class ASTIf;
class ASTOperation;
class ASTPrint;
class ASTReturn;
class ASTVariable;
class ASTWhile;