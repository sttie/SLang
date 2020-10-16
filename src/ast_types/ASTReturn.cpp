#include "../../include/ast_types/ASTReturn.h"

using namespace std;


ReturnException::ReturnException(Type returned_value_)
    : returned_value(move(returned_value_))
{
}

ASTReturn::ASTReturn(unique_ptr<ASTNode> return_expr_, size_t lineno_)
        : ASTNode(lineno_), return_expr(move(return_expr_)) {}

Type ASTReturn::Evaluate() const {
    throw ReturnException{return_expr->Evaluate()};
}