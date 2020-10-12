#include "../../include/ast_types/ASTAssignment.h"

using namespace std;


ASTAssignment::ASTAssignment(bool declaration_, string var_id_, string var_type_, size_t lineno_)
        : ASTNode(lineno_),
          declaration(declaration_),
          var_id(move(var_id_)),
          var_type(move(var_type_))
{
}


void ASTAssignment::UpdateSymTable(const string& id, const Type& type) const {
    if (!declaration && !symtable->AlreadyDefined(id)) {
        ThrowSemanticError(id + " was not declared yet");
    }
    if (declaration && symtable->AlreadyDefined(id)) {
        ThrowSemanticError(id + " has been defined already (ASTAssignment 20)");
    }
    if (declaration && var_type != type.GetStringTypeName()) {
        ThrowSemanticError("declaration type and evaluated type have different names: "
                            + var_type + " and " + type.GetStringTypeName());
    }

    symtable->UpdateTable(id, type);
}

Type ASTAssignment::Evaluate() const {
    UpdateSymTable(var_id, children[1]->Evaluate());
    return Type();
}