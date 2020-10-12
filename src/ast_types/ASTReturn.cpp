#include "../../include/ast_types/ASTReturn.h"

using namespace std;


ReturnException::ReturnException(Type returned_value_)
    : returned_value(move(returned_value_))
{
}

ASTReturn::ASTReturn(string return_id_, size_t lineno_)
        : ASTNode(lineno_), return_id(move(return_id_)) {}

Type ASTReturn::Evaluate() const {
    throw ReturnException{(*symtable)[return_id]};
}