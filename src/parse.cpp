#include "../include/parse.h"

#include <algorithm>
#include <iostream>


using namespace std;
using ASTNodePtr = Parser::ASTNodePtr;


Parser::Parser(istream& input_stream) : lexer(input_stream) {
    GetNewToken();
}


Parser::Statements Parser::ParseStatements(const string& stop_string) {
    Statements AST_nodes;

    while (true)
    {
        SkipWhitespaces();
        if (current_token.type == TokenType::EMPTY || current_token.lexeme == stop_string)
            break;
        AST_nodes.push_back(ParseStatement());
    }

    return AST_nodes;
}


ASTNodePtr Parser::ParseStatement() {
    ASTNodePtr statement_node;
    bool not_if = true;

    if (current_token.lexeme == "return") {
        statement_node = ParseReturnStatement();
    }
    else if (current_token.lexeme == "print") {
        statement_node = ParsePrintStmt();
    }
    else if (current_token.lexeme == "input") {
        statement_node = ParseInputStmt();
    }
    else if (current_token.lexeme == "if") {
        statement_node = ParseIfStmt();
        not_if = false;
    }
    else if (current_token.lexeme == "while") {
        statement_node = ParseWhileStmt();
    }
    else if (current_token.type == TokenType::NAME) {
        statement_node = ParseSimpleOrFunc();
    }
    else {
        statement_node = ParseExpr();
    }

    if (not_if) {
        GetNewToken();
        Match("\n");
    }

    return statement_node;
}


ASTNodePtr Parser::ParseReturnStatement() {
    // Skip "return"
    GetNewToken();
    return make_unique<ASTReturn>(ParseExpr(), lineno);
}


// func_or_simple := func_declaration | assignment_expr | expr
ASTNodePtr Parser::ParseSimpleOrFunc() {
    // If so, here we have func_decl or assignment_expr
    if (IsAvailableType(current_token.lexeme)) {
        // The type of func/var
        string type = move(current_token.lexeme);

        GetNewToken();
        Match(TokenType::NAME);

        Token next_token = GetNewAhead();
        if (next_token.type == TokenType::LBRACKET) {
            return ParseFuncDeclaration(move(type));
        }
        if (next_token.lexeme == "=") {
            return ParseAssignmentStmt(move(type), true);
        }

        ThrowParseError("expected \"(\" or \"=\", but got \"" + current_token.lexeme + "\"");
    }

    // Else it is just a var's redefining or an expression
    if (GetNewAhead().lexeme == "=") {
        return ParseAssignmentStmt("", false);
    }

    return ParseExpr();
}


Parser::FuncParameters Parser::ParseFuncParameters() {
    FuncParameters result;
    if (GetNewAhead().lexeme == ")") {
        GetNewToken();
        return result;
    }

    do {
        GetNewToken();

        if (!IsAvailableType(current_token.lexeme)) {
            ThrowParseError("Expected type name, but got " + current_token.lexeme);
        }
        // Creating a parameter type and go ahead
        string type = move(current_token.lexeme);
        GetNewToken();

        // Creating a parameter name and go ahead
        Match(TokenType::NAME);
        string id = move(current_token.lexeme);
        GetNewToken();

        result.emplace_back(move(type), move(id));
    } while (current_token.lexeme == ",");

    return result;
}


// func_declaration := type id "(" (type id ("," type id)*)* ")" "{" statements "}"
ASTNodePtr Parser::ParseFuncDeclaration(string return_type) {
    // current_token.lexeme here is an id
    string func_id = move(current_token.lexeme);
    auto function_node = make_unique<ASTFunctionDecl>(
            func_id, move(return_type), lineno
    );

    // Skipping id
    GetNewToken();

    auto args = ParseFuncParameters();
    Match(TokenType::RBRACKET);
    function_node->AddParameters(move(args));

    // Skipping ")" and newlines
    GetNewToken();
    SkipWhitespaces();

    Match(TokenType::LBRACE);
    GetNewToken();
    SkipWhitespaces();

    // Adding statements
    function_node->AddStatements(ParseStatements("}"));

    Match(TokenType::RBRACE);

    // Updating FuncTable
    auto& func_table = FunctionContext::GetContext().FuncTable();
    func_table[func_id] = move(function_node);

    return nullptr;
}


// func_call := id "(" args ")"
ASTNodePtr Parser::ParseFuncCall() {
    // current_token.lexeme here is an id
    string func_id = move(current_token.lexeme);
    auto function_call_node = make_unique<ASTFunCall>(
            move(func_id), lineno
    );

    GetNewToken();
    Match(TokenType::LBRACKET);

    if (GetNewAhead().type != TokenType::RBRACKET) {
        GetNewToken();
        function_call_node->AddArgs(ParseArgs());
    }

    GetNewToken();
    Match(TokenType::RBRACKET);

    return function_call_node;
}


// assignment_expr := (type)? id "=" expr
ASTNodePtr Parser::ParseAssignmentStmt(string type, bool declaration) {
    if (IsReserved(current_token.lexeme)) {
        ThrowParseError(current_token.lexeme + " is a reserved keyword");
    }

    // current_token is id and next_token is =
    auto assignment_node = make_unique<ASTAssignment>(
            declaration, move(current_token.lexeme), move(type), lineno

    );
    assignment_node->AddChild(ParseVariable());

    // Skipping id and "="
    GetNewToken(); GetNewToken();

    assignment_node->AddChild(ParseExpr());

    return assignment_node;
}


// print_stmt := "print" args
ASTNodePtr Parser::ParsePrintStmt() {
    auto print_node = make_unique<ASTPrint>(lineno);

    // Skipping "print"
    GetNewToken();

    print_node->AddChildren(ParseArgs());

    return print_node;
}


// input_statement := "input" id
ASTNodePtr Parser::ParseInputStmt() {
    // Skip "input"
    GetNewToken();
    Match(TokenType::NAME);

    return make_unique<ASTInput>(move(current_token.lexeme), lineno);
}


// args := expr | ("," expr)*
Parser::Arguments Parser::ParseArgs() {
    vector<ASTNodePtr> arg_nodes;
    arg_nodes.push_back(ParseExpr());

    while (GetNewAhead().type == TokenType::COMMA) {
        // Skipping a comma
        GetNewToken(); GetNewToken();
        arg_nodes.push_back(ParseExpr());
    }

    return arg_nodes;
}


// if_statement    := "if" "(" expr ")" NEWLINE* "{" statements "}"
ASTNodePtr Parser::ParseIfStmt() {
   auto if_node = make_unique<ASTIf>(lineno, true);

    // Skipping if
    GetNewToken();
    Match(TokenType::LBRACKET);
    GetNewToken();

    if_node->AddCondition(ParseExpr());
    GetNewToken();

    Match(TokenType::RBRACKET);
    GetNewToken();
    SkipWhitespaces();
    Match(TokenType::LBRACE);
    GetNewToken();

    if_node->AddStatements(ParseStatements("}"));

    Match(TokenType::RBRACE);
    GetNewToken();
    SkipWhitespaces();

    while (current_token.lexeme == "elif") {
        if_node->AddElif(ParseElifStmt());
        GetNewToken();
        SkipWhitespaces();
    }

    if (current_token.lexeme == "else") {
        if_node->AddElseStatements(ParseElseStmt());
        // Skipping }
        GetNewToken();
    }

    SkipWhitespaces();

    return if_node;
}


ASTNodePtr Parser::ParseElifStmt() {
    auto elif_node = make_unique<ASTIf>(lineno);

    // Skipping elif
    GetNewToken();
    Match(TokenType::LBRACKET);
    GetNewToken();

    elif_node->AddCondition(ParseExpr());
    GetNewToken();

    Match(TokenType::RBRACKET);
    GetNewToken();
    SkipWhitespaces();
    Match(TokenType::LBRACE);
    GetNewToken();

    elif_node->AddStatements(ParseStatements("}"));

    Match(TokenType::RBRACE);

    return elif_node;
}


Parser::Statements Parser::ParseElseStmt() {
    // Skipping else and newlines
    GetNewToken();
    SkipWhitespaces();

    Match(TokenType::LBRACE);
    GetNewToken();

    auto else_statements = ParseStatements("}");

    Match(TokenType::RBRACE);

    return else_statements;
}



// while_statement := "while" "(" expr ")" NEWLINE* "{" statements "}"
ASTNodePtr Parser::ParseWhileStmt() {
    auto while_node = make_unique<ASTWhile>(lineno);

    // Skipping "while"
    GetNewToken();
    Match(TokenType::LBRACKET);
    GetNewToken();

    while_node->AddCondition(ParseExpr());

    GetNewToken();
    Match(TokenType::RBRACKET);

    // Skipping ) and newlines
    GetNewToken();
    SkipWhitespaces();
    Match(TokenType::LBRACE);
    GetNewToken();
    SkipWhitespaces();

    while_node->AddStatements(ParseStatements("}"));

    Match(TokenType::RBRACE);

    return while_node;
}



template <typename Func, typename WhileFunc>
ASTNodePtr Parser::ParseTemplateExpr(Func ParseSubExpr,  WhileFunc CheckStopSymbol) {
    auto template_expr_node = make_unique<ASTOperation>(lineno);
    template_expr_node->AddChild(ParseSubExpr());
    Token next_token = GetNewAhead();

    while (CheckStopSymbol(next_token.lexeme)) {
        GetNewToken();

        // If template_expr_node is a factor
        if (template_expr_node->Operation().empty())
        {
            template_expr_node->SetOperation(move(current_token.lexeme));
            GetNewToken();
            template_expr_node->AddChild(ParseSubExpr());
        }

        else
        {
            unique_ptr<ASTOperation> new_op_node =
                    make_unique<ASTOperation>(move(current_token.lexeme), lineno);
            GetNewToken();

            new_op_node->AddChild(move(template_expr_node));
            new_op_node->AddChild(ParseSubExpr());

            template_expr_node = move(new_op_node);
        }

        next_token = GetNewAhead();
    }

    if (template_expr_node->Operation().empty())
        return move(template_expr_node->GetChild(0));
    else
        return template_expr_node;
}


// expr := logical_expr ("and" logical_expr)*
ASTNodePtr Parser::ParseExpr() {
    return ParseTemplateExpr(
        [this]() {
            return ParseLogicalExpr();
        },
        [](const string& lexeme) {
            return lexeme == "and";
        }
    );
}


// logical_expr := logical_term (("or" | "not") logical term)*
ASTNodePtr Parser::ParseLogicalExpr() {
    return ParseTemplateExpr(
        [this]() {
            return ParseLogicalTerm();
        },
        [](const string& lexeme) {
            return lexeme == "or";
        }
    );
}


// logical_term := compare_term (comparison compare_term)*
ASTNodePtr Parser::ParseLogicalTerm() {
    return ParseTemplateExpr(
        [this]() {
            return ParseCompareTerm();
        },
        [](const string& lexeme) {
            return lexeme == "<"  || lexeme == ">"  ||
                   lexeme == "<=" || lexeme == ">=" ||
                   lexeme == "==" || lexeme == "!=";
        }
    );
}


// compare_term := add_term (("+" | "-") add_term)*
ASTNodePtr Parser::ParseCompareTerm() {
    return ParseTemplateExpr(
        [this]() {
            return ParseAddTerm();
        },
        [](const string& lexeme) {
            return lexeme == "+" || lexeme == "-";
        }
    );
}


// add_term := mult_term (("*" | "/") mult_term)*
ASTNodePtr Parser::ParseAddTerm() {
    return ParseTemplateExpr(
        [this]() {
            return ParseMultTerm();
        },
        [](const string& lexeme) {
            return lexeme == "*" || lexeme == "/";
        }
    );
}


/* mult_term    := "(" expr ")"
 *              | ("-" | "not") factor
 *              | number
 *              | id
 *              | func_call
 *              | literal
 *              | "true"
 *              | "false"
 */
ASTNodePtr Parser::ParseMultTerm() {
    ASTNodePtr mult_term_node;

    if (current_token.type == TokenType::LBRACKET) {
        GetNewToken();

        mult_term_node = ParseExpr();
        GetNewToken();

        Match(")");
    }

    else if (current_token.type == TokenType::QUOTE) {
        GetNewToken();

        if (current_token.type != TokenType::QUOTE) {
            mult_term_node = make_unique<ASTVariable>(
                    Type{"string", move(current_token.lexeme)}, lineno
            );
            GetNewToken();
        }
        else {
            mult_term_node = make_unique<ASTVariable>(
                    Type{"string", ""}, lineno
            );
        }

        Match("\"");
    }

    else if (current_token.lexeme == "-") {
        GetNewToken();
        mult_term_node = make_unique<ASTOperation>(
                "-", lineno
        );
        mult_term_node->AddChild(make_unique<ASTVariable>(
            Type("int", "0"), lineno
        ));
        mult_term_node->AddChild(ParseMultTerm());
    }

    else if (current_token.lexeme == "not") {
        GetNewToken();
        mult_term_node = make_unique<ASTOperation>(
            "not", lineno
        );
        mult_term_node->AddChild(ParseMultTerm());
    }

    else if (current_token.type == TokenType::NUMBER) {
        mult_term_node = ParseNumber();
    }

    else if (current_token.lexeme == "true" || current_token.lexeme == "false") {
        mult_term_node = make_unique<ASTVariable>(
                Type(TypeName::BOOL, move(current_token.lexeme)), lineno
        );
    }

    else if (current_token.type == TokenType::NAME) {
        mult_term_node = GetNewAhead().lexeme == "("
                         ? ParseFuncCall() : ParseVariable();
    }

    else {
        ThrowParseError("unexpected lexeme: " + current_token.lexeme);
    }

    return mult_term_node;
}


ASTNodePtr Parser::ParseVariable() {
    return make_unique<ASTVariable>(current_token.lexeme, lineno);
}

ASTNodePtr Parser::ParseNumber() {
    return make_unique<ASTVariable>(Type("int", current_token.lexeme), lineno);
}



void Parser::Match(const TokenType& right) const {
    if (current_token.type != right) {
        ThrowParseError("expected " + TypeToString(right)
                        + ", but got " +
                        TypeToString(current_token.type));
    }
}

void Parser::Match(const string& right) const {
    if (current_token.lexeme != right) {
        string new_right = current_token.lexeme == "\n"
                          ? "newline" : right;
        string new_left = right == "\n"
                          ? "newline" : current_token.lexeme;
        ThrowParseError("expected " + new_right + ", but got " + new_left);
    }
}

bool Parser::IsReserved(const string& lexeme) const {
    return find(reserved.begin(),
                reserved.end(), lexeme) != reserved.end();
}

bool Parser::IsAvailableType(const string& lexeme) const {
    return find(available_types.begin(),
                available_types.end(),
                lexeme) != available_types.end();
}

const string& Parser::GetCurrentLine() const {
    return lexer.GetCurrentLine();
}


void Parser::GetNewToken() {
    current_token = lexer.GetToken();
}

Token Parser::GetNewAhead() {
    return lexer.GetAhead();
}

void Parser::SkipWhitespaces() {
    while (current_token.type == TokenType::NEWLINE) {
        GetNewToken();
        lineno++;
    }
}

void Parser::ThrowParseError(const string& error_message) const {
    string current_line = current_token.type == TokenType::NEWLINE
                          ? lexer.GetPrevLine()
                          : lexer.GetCurrentLine();
    throw logic_error("line " + to_string(lineno) + ": " + current_line + "\n"
                      + string(7 + to_string(lineno).size() + current_token.start, ' ')
                      + "^\n" + error_message);
}