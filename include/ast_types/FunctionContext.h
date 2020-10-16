#pragma once

#include "type.h"
#include "ast.h"

#include <map>
#include <vector>
#include <memory>
#include <functional>


class FunctionContext {
public:
    using SymTablePtr = std::unique_ptr<SymTable>;
    using TFuncTable = std::map<std::string, std::unique_ptr<ASTNode>>;
    using TBuiltInFunc = std::function<Type(const std::vector<Type>&)>;
    using TBuiltinFuncTable = std::map<std::string, std::pair<TBuiltInFunc, int>>;
    using TBordersStack = std::vector<size_t>;
    using TArgumentsStack = std::vector<Type>;

    static FunctionContext& GetContext();

    std::vector<SymTablePtr>& SymtableFuncStack();
    TBuiltinFuncTable& BuiltinFuncTable();
    TFuncTable& FuncTable();
    TBordersStack& BordersStack();
    TArgumentsStack& ArgumentsStack();
    size_t& LeftArgument();
    size_t& RightArgument();

    FunctionContext(const FunctionContext&) = delete;
    FunctionContext& operator=(const FunctionContext&) = delete;
    FunctionContext& operator=(FunctionContext&&) = delete;

private:
    // init func_table and etc.
    FunctionContext();

    std::vector<SymTablePtr> symtable_func_stack;

    TBuiltinFuncTable builtin_func_table;
    TFuncTable func_table;

    TBordersStack borders_stack;
    TArgumentsStack arguments_stack;
    size_t left_argument = 0;
    size_t right_argument = 0;
};