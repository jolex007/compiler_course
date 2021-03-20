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

    class Assignment;
    class AssignmentList;

    class Program;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "visitors/elements.h"
    #include "program.h"

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
    EOF 0 "end of file"
    ENDL "\n"
    ARROW "->"
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LBRACKET "("
    RBRACKET ")"
    LEFTSCOPE "{"
    RIGHTSCOPE "}"
    LARRAYBRACKET "["
    RARRAYBRACKET "]"
    COLON ":"
    DOT "."
    GT ">"
    LT "<"
    GE ">="
    LE "<="
    EQ "=="
    ASSIGN "="
    COMMA ","
    IF "if"
    ELSE "else"
    RETURN "return"
    VAR "var"
    LET "let"
    FUNC "func"
    CLASS "class"
    INT "Int"
    STRING "String"
    BOOL "Bool"
    FOR "for"
    IN "in"
    RANGE "range"
    WHILE "while"
    SELF "self"
    AND "and"
    OR "or"
    NOT "not"
    PRINT "print"
    INIT "init"
    DEINIT "deinit"
    EXTENSION "extension"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
// TODO:
//   Add nterms



%%

%start unit;

unit:
    global_list
    ;

global_list:
    global_declaration
    | global_declaration global_list
    ;

global_declaration:
    class_declaration
    | function_declaration
    | variable_declaration
    | constant_declaration
    | extension_declaration
    ;

class_declaration:
    "class" "identifier" class_body
    | "class" "identifier" type_inheritance_clause class_body
    ;

type_inheritance_clause:
    ":" type_inheritance_list
    ;

type_inheritance_list:
    type_identifier
    | type_identifier "," type_inheritance_list
    ;

class_body:
    "{" class_members "}"
    ;

class_members:
    %empty
    | class_member class_members
    ;

class_member:
    declaration
    ;

extension_declaration:
    "extension" type_identifier extension_body
    | "extension" type_identifier type_inheritance_clause extension_body
    ;

extension_body:
    "{" class_members "}"
    ;

type:
    type_identifier
    | "[" type_identifier "]"
    ;

type_identifier:
    type_name
    ;

type_name:
    "identifier"
    | "String"
    | "Int"
    | "Bool"
    ;

declarations:
    declaration
    | declaration declarations
    ;

declaration:
    constant_declaration
    | variable_declaration
    | function_declaration
    | class_declaration
    | initializer_declaration
    | deinitializer_declaration
    ;

deinitializer_declaration:
    "deinit" code_block
    ;

constant_declaration:
    "let" pattern initializer
    ;

pattern_initializer:
    pattern
    | pattern initializer
    ;

initializer:
    "=" expression
    ;

pattern:
    "_"
    | "_" type_annotation
    | "identifier"
    | "identifier" type_annotation
    ;

type_annotation:
    ":" type
    ;

variable_declaration:
    "var" pattern_initializer
    ;

function_declaration:
    "func" "identifier" function_declaration_argument_clause code_block
    | "func" "identifier" function_declaration_argument_clause function_return_type code_block
    ;

function_declaration_argument_clause:
    "(" pattern_list ")"
    ;

pattern_list:
    %empty
    | pattern pattern_list
    ;

function_return_type:
    "->" type
    ;

initializer_declaration:
    "init" function_declaration_argument_clause code_block
    ;

code_block:
    "{" statements "}"
    ;

statements:
    %empty
    | statement
    | statement statements
    ;

statement:
    expression
    | declaration
    | for_in_statement
    | while_statement
    | if_statement
    | control_transfer_statement
    ;

for_in_statement:
    "for" pattern "in" "range" "(" expression ")" code_block
    ;

while_statement:
    "while" expression code_block
    ;

if_statement:
    "if" expression code_block
    | "if" expression code_block else_clause
    ;

else_clause:
    "else" code_block
    | "else" if_statement
    ;

control_transfer_statement:
    "break"
    | "continue"
    | return_statement
    ;

return_statement:
    "return"
    | "return" expression
    ;

expression:
    primary_expression
    | function_call_expression
    | explicit_member_expression
    | subcript_expression
    | prefix_operator expression
    | expression infix_operator expression
    | array_expression
    | "number"
    ;

expressions:
    %empty
    | expression expressions
    ;

array_expression:
    "[" expressions "]"
    ;

prefix_operator:
    "-"
    | "not"
    ;

infix_operator:
    "+"
    | "*"
    | "/"
    | "-"
    | "and"
    | "or"
    | "="
    | ">"
    | ">="
    | "<"
    | "<="
    ;

primary_expression:
    "identifier"
    | "self"
    | "(" expression ")"
    ;

function_call_expression:
    "identifier" function_call_argument_clause
    ;

function_call_argument_clause:
    "(" ")"
    | "(" function_call_argument_list ")"
    ;

function_call_argument_list:
    function_call_argument
    | function_call_argument "," function_call_argument_list
    ;

function_call_argument:
    expression
    ;

explicit_member_expression:
    expression "." explicit_member_argument
    ;

explicit_member_argument:
    "identifier"
    | function_call_expression
    ;

subcript_expression:
    expression "[" expression "]"
    ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << " : " << m << "\n";
}
