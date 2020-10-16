#include "../include/ast_types/FunctionContext.h"
#include "../include/builtin_functions.h"

using SymTablePtr = FunctionContext::SymTablePtr;
using TFuncTable = FunctionContext::TFuncTable;
using TBuiltInFunc = FunctionContext::TBuiltInFunc;
using TBuiltinFuncTable = FunctionContext::TBuiltinFuncTable;
using TBordersStack = FunctionContext::TBordersStack;
using TArgumentsStack = FunctionContext::TArgumentsStack;

FunctionContext::FunctionContext()
    : builtin_func_table({
          {"toInt", {BuiltinInt, 1}},
          {"toBool", {BuiltinBool, 1}},
          {"toString", {BuiltinString, 1}}
    })
{
}

FunctionContext& FunctionContext::GetContext() {
    static FunctionContext context_instance;
    return context_instance;
}

std::vector<SymTablePtr>& FunctionContext::SymtableFuncStack() {
    return symtable_func_stack;
}

TBuiltinFuncTable& FunctionContext::BuiltinFuncTable() {
    return builtin_func_table;
}

TFuncTable& FunctionContext::FuncTable() {
    return func_table;
}

TBordersStack& FunctionContext::BordersStack() {
    return borders_stack;
}

TArgumentsStack& FunctionContext::ArgumentsStack() {
    return arguments_stack;
}

size_t& FunctionContext::LeftArgument() {
    return left_argument;
}

size_t& FunctionContext::RightArgument() {
    return right_argument;
}