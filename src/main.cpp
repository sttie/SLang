#include <iostream>
#include <fstream>

#include "../include/parse.h"

using namespace std;


void EvaluateProgram(list<unique_ptr<ASTNode>>& stmts)
{
    for (unique_ptr<ASTNode>& node : stmts) {
        if (node != nullptr) {
            node->Evaluate();
            node.reset();
        }
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << argc << endl;
        cout << "You have to specify a .txt file!" << endl;
        return 0;
    }

    ifstream file(argv[1]);
    Parser parser(file);

    try {
        list<unique_ptr<ASTNode>> stmts = parser.ParseStatements();
        EvaluateProgram(stmts);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
