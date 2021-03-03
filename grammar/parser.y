%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "visitors/elements.h"
    #include "Program.h"

    #include <iostream>

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LBRACKET "("
    RBRACKET ")"
    VAR "var"
    LEFTSCOPE "{"
    RIGHTSCOPE "}"
    COMMA ","
    FUNC "func"
    RETURN "return"
    IF "if"
    ELSE "else"
    LT "<"
    GT ">"
    GE ">="
    LE "<="
    EQ "=="
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

