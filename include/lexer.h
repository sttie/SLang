#pragma once

#include "token.h"

#include <string>
#include <istream>


class Lexer {
public:
    explicit Lexer(std::istream& input);

    Lexer(const Lexer& lexer) = delete;
    Lexer(Lexer&& lexer) = delete;
    Lexer& operator=(const Lexer& lexer) = delete;
    Lexer& operator=(Lexer&& lexer) = delete;

    Token GetToken(bool reset = true);
    Token GetAhead();

    const std::string& GetCurrentLine() const;
    const std::string& GetPrevLine() const;

private:
    void LoadBuffer();
    Token LoadWithNewline();

    static TokenType GetType(const std::string& lexeme);
    static bool IsLogical(const std::string& lexeme);
    static bool IsName(const std::string& lexeme);
    static bool IsNumber(const std::string& lexeme);
    static bool IsLongOperation(const std::string& lexeme);
    static bool IsOperation(char symbol);
    static bool IsComparison(char symbol);
    static bool IsBracket(char symbol);
    static bool IsOkayForId(char symbol);

    std::istream& input;
    std::string prev_buffer;
    std::string buffer;
    size_t current_sym = 0;
    bool last_quote = false;
    bool end = false;
};