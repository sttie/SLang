#pragma once

#include <string>
#include <ostream>

enum class TokenType
{
    LOGICAL,        // and, or, not
    OPERATION,      // +, -, *, /, >, <, >=, <=, ==, !=, =

    NAME,           // correct ids
    LITERAL,        // just a sequence of symbols
    NUMBER,

    NEWLINE,        // \n

    QUOTE,          // "

    LBRACKET,       // (
    RBRACKET,       // )
    LBRACE,         // {
    RBRACE,         // }
    COMMA,          // ,

    EMPTY
};


struct Token
{
    std::string lexeme;
    TokenType type;
    size_t start;
};

std::string TypeToString(const TokenType& type);
std::ostream& operator<<(std::ostream& out, const Token& token);
std::ostream& operator<<(std::ostream& out, const TokenType& type);