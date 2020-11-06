#pragma once

#include "ast.h"
#include "ast_types/ASTAssignment.h"
#include "ast_types/ASTFunctionDecl.h"
#include "ast_types/ASTIf.h"
#include "ast_types/ASTOperation.h"
#include "ast_types/ASTPrint.h"
#include "ast_types/ASTReturn.h"
#include "ast_types/ASTVariable.h"
#include "ast_types/ASTWhile.h"
#include "ast_types/ASTFunCall.h"
#include "ast_types/ASTInput.h"

#include "token.h"
#include "lexer.h"

#include <string>
#include <vector>
#include <memory>
#include <list>


class Parser {
public:
    using ASTNodePtr = std::unique_ptr<ASTNode>;
    using Statements = std::list<ASTNodePtr>;
    using Arguments = std::vector<ASTNodePtr>;
    using FuncParameters = std::vector<std::pair<std::string, std::string>>;

    Parser(std::istream& input_stream);

    Statements ParseStatements(const std::string& stop_string = "$");

private:
    ASTNodePtr ParseStatement();

    ASTNodePtr ParsePrintStmt();
    ASTNodePtr ParseInputStmt();
    ASTNodePtr ParseIfStmt();
    ASTNodePtr ParseElifStmt();
    Statements ParseElseStmt();
    ASTNodePtr ParseWhileStmt();

    ASTNodePtr ParseSimpleOrFunc();
    ASTNodePtr ParseReturnStatement();

    Arguments ParseArgs();
    ASTNodePtr ParseAssignmentStmt(std::string type, bool declaration);

    template <typename Func, typename WhileFunc>
    ASTNodePtr ParseTemplateExpr(Func ParseSubExpr, WhileFunc CheckStopSymbol);
    ASTNodePtr ParseExpr();
    ASTNodePtr ParseLogicalExpr();
    ASTNodePtr ParseLogicalTerm();
    ASTNodePtr ParseCompareTerm();
    ASTNodePtr ParseAddTerm();
    ASTNodePtr ParseMultTerm();

    ASTNodePtr ParseFuncDeclaration(std::string type);
    ASTNodePtr ParseFuncCall();

    ASTNodePtr ParseVariable();
    ASTNodePtr ParseNumber();
    FuncParameters ParseFuncParameters();

    void ThrowParseError(const std::string& error_message) const;
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

    const std::vector<std::string> reserved = {
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
    const std::vector<std::string> available_types = {
            "string",
            "bool",
            "int",
            "void"
    };
};