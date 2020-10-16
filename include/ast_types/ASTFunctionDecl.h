#pragma once

#include "../ast.h"
#include "../../include/ast_types/FunctionContext.h"


class ASTFunctionDecl : public ASTNode {
public:
    using ParameterByPair = std::pair<std::string, std::string>;
    using ASTNode::Statements;

    struct Parameter {
        std::string type;
        std::string name;
    };

    ASTFunctionDecl(std::string func_id_, std::string return_type_, size_t lineno_);
    ~ASTFunctionDecl() = default;

    void AddParameters(std::vector<ParameterByPair> parameters_);
    void AddStatements(Statements statements_);

    Type Evaluate() const override;

private:
    // This function gets ASTVariables from ASTNode::func_stack
    void InitializeParameters() const;
    void RestoreSymtable() const;
    void SaveSymtableOnStack() const;
    void ThrowIfReturnTypeMismatch(const Type& returned_value) const;
    void ThrowIfArgTypeMismatch(const std::string& top_arg_typename,
                                const std::string& current_parameter_typename,
                                size_t i) const;
    void ThrowIfNotVoid() const;

    FunctionContext& func_context;

    std::string func_id;
    std::string return_type;
    std::vector<Parameter> parameters;
    Statements statements;

    mutable SymTablePtr old_symtable;
};