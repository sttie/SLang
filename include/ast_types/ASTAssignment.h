#pragma once

#include "../ast.h"


class ASTAssignment : public ASTNode {
public:
    ASTAssignment(bool declaration_, std::string var_id_, std::string var_type_, size_t lineno_);
    ~ASTAssignment() = default;

    Type Evaluate() const override;

private:
    void UpdateSymTable(const std::string& id, const Type& type) const;

    bool declaration;
    std::string var_id;
    std::string var_type;
};
