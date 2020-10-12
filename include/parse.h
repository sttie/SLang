#pragma once

#include "ast.h"
#include "ast_types/ASTAssignment.h"
#include "ast_types/ASTFunction.h"
#include "ast_types/ASTIf.h"
#include "ast_types/ASTOperation.h"
#include "ast_types/ASTPrint.h"
#include "ast_types/ASTReturn.h"
#include "ast_types/ASTVariable.h"
#include "ast_types/ASTWhile.h"
#include "ast_types/ASTFunCall.h"

#include "token.h"
#include "lexer.h"

#include <string>
#include <vector>
#include <memory>
#include <list>


class Parser {
public:
    Parser(std::istream& input_stream);

    std::list<std::unique_ptr<ASTNode>> ParseStatements(const std::string& stop_string = "$");

private:
    std::unique_ptr<ASTNode> ParseStatement();

    std::unique_ptr<ASTNode> ParsePrintStmt();
    std::unique_ptr<ASTNode> ParseIfStmt();
    std::unique_ptr<ASTNode> ParseElifStmt();
    std::list<std::unique_ptr<ASTNode>>  ParseElseStmt();
    std::unique_ptr<ASTNode> ParseWhileStmt();

    std::unique_ptr<ASTNode> ParseSimpleOrFunc();
    std::unique_ptr<ASTNode> ParseReturnStatement();

    std::vector<std::unique_ptr<ASTNode>> ParseArgs();
    std::unique_ptr<ASTNode> ParseAssignmentStmt(std::string type, bool declaration);

    template <typename Func, typename WhileFunc>
    std::unique_ptr<ASTNode> ParseTemplateExpr(Func ParseSubExpr, WhileFunc CheckStopSymbol);
    std::unique_ptr<ASTNode> ParseExpr();
    std::unique_ptr<ASTNode> ParseLogicalExpr();
    std::unique_ptr<ASTNode> ParseLogicalTerm();
    std::unique_ptr<ASTNode> ParseCompareTerm();
    std::unique_ptr<ASTNode> ParseAddTerm();
    std::unique_ptr<ASTNode> ParseMultTerm();

    std::unique_ptr<ASTNode> ParseFuncDeclaration(std::string type);
    std::unique_ptr<ASTNode> ParseFuncCall();

    std::unique_ptr<ASTNode> ParseVariable();
    std::unique_ptr<ASTNode> ParseNumber();
    std::vector<std::pair<std::string, std::string>> ParseFuncParameters();

    void ThrowParseError(std::string&& error_message) const;
    void Match(const TokenType& right) const;
    void Match(const std::string& right) const;
    bool IsReserved(const std::string& lexeme) const;
    bool IsAvailableType(const std::string& lexeme) const;
    const std::string& GetCurrentLine() const;

    void SkipWhitespaces();
    void GetNewToken();
    Token GetNewAhead();

    Lexer lexer;
    Token current_token;
    size_t lineno = 1;

    std::vector<std::string> reserved = {
            "if",
            "while",
            "true",
            "false",
            "print",
            "string",
            "bool",
            "int",
            "void",
            "if",
            "elif",
            "else"
    };
    std::vector<std::string> available_types = {
            "string",
            "bool",
            "int",
            "void"
    };
};