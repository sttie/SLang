#include "../include/token.h"

using namespace std;


string TypeToString(const TokenType& type) {
    string result;

    switch (type)
    {
        case TokenType::OPERATION:
            result = "operator";
            break;
        case TokenType::NUMBER:
            result = "number";
            break;
        case TokenType::NAME:
            result = "name";
            break;
        case TokenType::LBRACKET:
            result = "(";
            break;
        case TokenType::RBRACKET:
            result = ")";
            break;
        case TokenType::COMMA:
            result = ",";
            break;
        case TokenType::NEWLINE:
            result = "newline";
            break;
        case TokenType::LOGICAL:
            result = "logical operator";
            break;
        case TokenType::LITERAL:
            result = "literal";
            break;
        case TokenType::QUOTE:
            result = "\"";
            break;
        case TokenType::LBRACE:
            result = "{";
            break;
        case TokenType::RBRACE:
            result = "}";
            break;
        default:
            result = "empty";
    }

    return result;
}

ostream& operator<<(ostream& out, const TokenType& type)
{
    out << TypeToString(type);
    return out;
}

ostream& operator<<(ostream& out, const Token& token) {
    out << "[" << token.lexeme << ", " << token.type << ", " << token.start << "]";
    return out;
}
