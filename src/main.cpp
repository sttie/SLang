#include <iostream>
#include <fstream>

#include "../include/parse.h"

using namespace std;


ASTNode::SymTablePtr ASTNode::symtable = MakeNewSymTable();
std::vector<ASTNode::SymTablePtr> ASTNode::symtable_func_stack = std::vector<ASTNode::SymTablePtr>();
ASTNode::FuncTable ASTNode::func_table = ASTNode::FuncTable();
ASTNode::ArgumentsStack ASTNode::func_stack = ASTNode::ArgumentsStack();
size_t ASTNode::left_argument = 0;
size_t ASTNode::right_argument = 0;
vector<size_t> ASTNode::call_stack = vector<size_t>();


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
