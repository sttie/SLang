#include "../include/ast.h"

#include <iostream>

using namespace std;

ASTNode::SymTablePtr ASTNode::symtable = MakeNewSymTable();
std::vector<ASTNode::SymTablePtr> ASTNode::symtable_func_stack = std::vector<ASTNode::SymTablePtr>();
ASTNode::FuncTable ASTNode::func_table = ASTNode::FuncTable();
ASTNode::ArgumentsStack ASTNode::func_stack = ASTNode::ArgumentsStack();
size_t ASTNode::left_argument = 0;
size_t ASTNode::right_argument = 0;
vector<size_t> ASTNode::call_stack = vector<size_t>();



ASTNode::ASTNode(size_t lineno_)
    : lineno(lineno_)
{
}

void ASTNode::AddChild(unique_ptr<ASTNode> child) {
    children.push_back(move(child));
}

void ASTNode::AddChildren(vector<unique_ptr<ASTNode>> children_) {
    for (auto& node : children_)
        children.push_back(move(node));
}

void ASTNode::ThrowSemanticError(const string& error_message) const {
    throw logic_error("line " + to_string(lineno) + ": " + error_message);
}

std::unique_ptr<ASTNode>& ASTNode::GetChild(size_t index) {
    return children[index];
}

size_t ASTNode::GetLine() const {
    return lineno;
}