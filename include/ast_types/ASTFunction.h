#pragma once

#include "../ast.h"


class ASTFunction : public ASTNode {
public:
    using ParameterByPair = std::pair<std::string, std::string>;
    using ASTNode::Statements;

    struct Parameter {
        std::string type;
        std::string name;
    };

    ASTFunction(std::string func_id_, std::string return_type_, size_t lineno_);
    ~ASTFunction() = default;

    void AddParameters(std::vector<ParameterByPair> parameters_);
    void AddStatements(Statements statements_);

    Type Evaluate() const override;

private:
    // This function gets ASTVariables from ASTNode::func_stack
    void InitializeParameters() const;
    static void RestoreSymtable();
    static void SaveSymtableOnStack();
    void ThrowIfReturnTypeMismatch(const Type& returned_value) const;
    void ThrowIfArgTypeMismatch(const std::string& top_arg_typename,
                                const std::string& current_parameter_typename,
                                size_t i) const;
    void ThrowIfNotVoid() const;


    std::string func_id;
    std::string return_type;
    std::vector<Parameter> parameters;
    Statements statements;

    mutable SymTablePtr old_symtable;
};