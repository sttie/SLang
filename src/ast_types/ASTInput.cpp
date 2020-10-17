#include "../../include/ast_types/ASTInput.h"

#include <iostream>

using namespace std;


ASTInput::ASTInput(std::string input_id_, size_t lineno_)
    : ASTNode(lineno_), input_id(move(input_id_))
{
}

Type ASTInput::Evaluate() const {
    string input; cin >> input;
    Type& to_input = (*symtable)[input_id];

    if (to_input.GetTypeName() != TypeName::STRING) {
        ThrowSemanticError("input command's argument must have a \"string\" type");
    }

    to_input = Type(TypeName::STRING, move(input));
    return Type();
}