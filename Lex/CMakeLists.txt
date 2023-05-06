cmake_minimum_required(VERSION 3.23)
project(Lex)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Lex
    ASTnodes.cpp
    ASTnodes.h
    Lexer.cpp
    Lexer.h
    lexical.cpp
    lexical.h
    LexRule.h
    main.cpp
    parseTree2AST.cpp
    pascalRul.cpp
    PascalRul.h
    semanticAnalyse.cpp
    symbolTable.cpp
    symbolTable.h
    test.cpp
    yacc.tab.cpp
    yacc.tab.h
    yyheader.h)
