#include "../../include/ast_types/ASTVariable.h"

using namespace std;


ASTVariable::ASTVariable(string id_, size_t lineno_)
        : ASTNode(lineno_), id(move(id_))
{
}

ASTVariable::ASTVariable(Type value_, size_t lineno_)
        : ASTNode(lineno_), value(move(value_))
{
}

Type ASTVariable::Evaluate() const {
    try {
        return id.empty() ? value : (*symtable)[id];
    }
    catch (const logic_error& undefined_exception) {
        ThrowSemanticError(undefined_exception.what());
    }

    // Making a compiler happy
    return Type();
}