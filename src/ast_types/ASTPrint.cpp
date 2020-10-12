#include "../../include/ast_types/ASTPrint.h"
#include "../../include/ast_types/ASTVariable.h"

#include <iostream>

using namespace std;


ASTPrint::ASTPrint(size_t lineno_)
        : ASTNode(lineno_)
{
}

Type ASTPrint::Evaluate() const {
    for (auto& child : children) {
        Type type = child->Evaluate();

        if (type.GetTypeName() == TypeName::INT) {
            cout << get<int>(type.Value());
        }
        else if (type.GetTypeName() == TypeName::STRING) {
            cout << get<string>(type.Value());
        }
        else if (type.GetTypeName() == TypeName::BOOL) {
            cout << get<bool>(type.Value());
        }
        cout << " ";
    }
    cout << endl;

    return Type();
}