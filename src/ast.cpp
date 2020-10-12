#include "../include/ast.h"

#include <iostream>

using namespace std;

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