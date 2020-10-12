cmake_minimum_required(VERSION 3.17)
project(lang2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(lang2_0
        src/main.cpp src/parse.cpp src/ast.cpp src/lexer.cpp
        include/lexer.h include/ast.h include/parse.h
        include/symtable.h include/type.h include/token.h
        unity_tests/unit_tests.h include/ast_types/ASTFunction.h
        include/ast_types/ASTVariable.h include/ast_types/ASTOperation.h
        include/ast_types/ASTAssignment.h include/ast_types/ASTPrint.h
        include/ast_types/ASTIf.h include/ast_types/ASTWhile.h
        include/ast_types/ASTReturn.h src/ast_types/ASTAssignment.cpp
        src/ast_types/ASTFunction.cpp src/ast_types/ASTIf.cpp
        src/ast_types/ASTOperation.cpp src/ast_types/ASTPrint.cpp
        src/ast_types/ASTReturn.cpp src/ast_types/ASTVariable.cpp
        src/ast_types/ASTWhile.cpp src/type.cpp src/symtable.cpp
        include/ast_types/ASTFunCall.h src/ast_types/ASTFunCall.cpp
        src/token.cpp)
