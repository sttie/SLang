#include "../include/lexer.h"
#include "../include/token.h"

#include <algorithm>

using namespace std;


Lexer::Lexer(std::istream& input_)
        : input(input_)
{
    LoadBuffer();
}

void Lexer::LoadBuffer() {
    if (!getline(input, buffer)) {
        end = true;
    }
    current_sym = 0;
}

Token Lexer::LoadWithNewline() {
    prev_buffer = move(buffer);
    LoadBuffer();
    return Token{"\n", TokenType::NEWLINE, buffer.size()};
}

Token Lexer::GetAhead() {
    size_t old_current = current_sym;
    bool old_last_quote = last_quote;

    Token token = GetToken(false);

    current_sym = old_current;
    last_quote = old_last_quote;

    return token;
}

const string& Lexer::GetCurrentLine() const {
    return buffer;
}

const std::string& Lexer::GetPrevLine() const {
    return prev_buffer;
}


// TODO: use some string_view?
Token Lexer::GetToken(bool reset) {
    if (end) {
        return Token{"", TokenType::EMPTY, 0};
    }
    else if (reset && current_sym >= buffer.size()) {
        return LoadWithNewline();
    }
    else if (!reset && current_sym >= buffer.size()) {
        last_quote = false;
        return Token{"\n", TokenType::NEWLINE, buffer.size()};
    }

    string current_lexeme;
    TokenType token_type;

    while (current_sym < buffer.size() && isspace(buffer[current_sym]) && !last_quote) {
        current_sym++;
    }

    size_t forward = current_sym;
    while (forward < buffer.size() && (IsOkayForId(buffer[forward])
                    || last_quote && buffer[forward] != '\"')) {
        current_lexeme += buffer[forward++];
    }

    if (forward == current_sym) {
        if (buffer[forward] == '\"') {
            current_lexeme += buffer[forward++];
            last_quote = !last_quote;
        }

        else if (buffer[forward] == ',' || IsOperation(buffer[forward])
                    || IsBracket(buffer[forward])) {
            current_lexeme += buffer[forward++];
        }

        else if (IsComparison(buffer[forward])) {
            current_lexeme += buffer[forward++];
            if (buffer[forward] == '=') {
                current_lexeme += buffer[forward++];
            }
        }

        token_type = GetType(current_lexeme);
    }
    else {
        token_type = last_quote ?
                     TokenType::LITERAL : GetType(current_lexeme);
    }

    size_t lexeme_start = current_sym;
    current_sym = forward;
    return Token{move(current_lexeme), token_type, lexeme_start};
}



TokenType Lexer::GetType(const std::string& lexeme) {
    if (lexeme == "\n")
        return TokenType::NEWLINE;
    if (lexeme == ",")
        return TokenType::COMMA;
    if (IsLongOperation(lexeme))
        return TokenType::OPERATION;
    if (IsLogical(lexeme))
        return TokenType::LOGICAL;
    if (IsNumber(lexeme))
        return TokenType::NUMBER;
    if (lexeme == "(")
        return TokenType::LBRACKET;
    if (lexeme == ")")
        return TokenType::RBRACKET;
    if (lexeme == "{")
        return TokenType::LBRACE;
    if (lexeme == "}")
        return TokenType::RBRACE;
    if (lexeme == "\"")
        return TokenType::QUOTE;
    if (IsName(lexeme))
        return TokenType::NAME;

    return TokenType::LITERAL;
}


bool Lexer::IsName(const std::string& lexeme)
{
    if (isdigit(lexeme[0]) || lexeme.empty())
        return false;

    return all_of(lexeme.begin(), lexeme.end(), [](char sym) {
        return isalnum(sym) || sym == '_';
    });
}

bool Lexer::IsNumber(const string& lexeme)
{
    if (lexeme.empty() || lexeme[0] == '-' && lexeme.size() == 1)
        return false;

    size_t start = lexeme[0] == '-' ? 1 : 0;
    return all_of(lexeme.begin() + start, lexeme.end(), [](char ch) {
        return isdigit(ch);
    });
}

bool Lexer::IsLogical(const std::string& lexeme) {
    return lexeme == "and" || lexeme == "or"
           || lexeme == "not";
}

bool Lexer::IsOperation(char symbol) {
    return symbol == '+' || symbol == '-'
           || symbol == '*' || symbol == '/';
}

bool Lexer::IsLongOperation(const string& lexeme) {
    return lexeme == "<"  || lexeme == ">"
           || lexeme == "<=" || lexeme == ">="
           || lexeme == "==" || lexeme == "!="
           || lexeme == "="  || lexeme == "+"
           || lexeme == "-"  || lexeme == "*"
           || lexeme == "/";
}

bool Lexer::IsComparison(char symbol) {
    return symbol == '<'  || symbol == '>'
           || symbol == '='  || symbol == '!';
}

bool Lexer::IsBracket(char symbol) {
    return symbol == '(' || symbol == ')'
           || symbol == '{' || symbol == '}';
}

bool Lexer::IsOkayForId(char symbol) {
    return isalpha(symbol) || isdigit(symbol)
           || symbol == '_';
}