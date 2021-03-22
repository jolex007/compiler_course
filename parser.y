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

    class Statement;
    class StatementList;

    class Declaration;
    class DeclarationList;

    class Expression;
    class ExpressionList;

    class SubscriptExpression;
    class FunctionCallExpression;
    class ArrayExpression;

    class Program;

    class FunctionDeclaration;
    class PatternList;
    class Pattern;
    class CodeBlock;

    enum class InfixOperator;
    enum class PrefixOperator;
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
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    GT ">"
    LT "<"
    GE ">="
    LE "<="
    EQ "=="
    NE "!="
    ASSIGN "="
    AND "and"
    OR "or"
    NOT "not"

%token
    EOF 0 "end of file"
    ENDL "\n"
    ARROW "->"
    LBRACKET "("
    RBRACKET ")"
    LEFTSCOPE "{"
    RIGHTSCOPE "}"
    LARRAYBRACKET "["
    RARRAYBRACKET "]"
    COLON ":"
    DOT "."
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
    PRINT "print"
    INIT "init"
    DEINIT "deinit"
    EXTENSION "extension"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <std::string> WILDCARD "_"

// TODO:
//   Add nterms

%nterm <Expression*> expression
%nterm <ExpressionList*> expressions
%nterm <SubscriptExpression*> subscript_expression
%nterm <FunctionCallExpression*> function_call_expression
%nterm <ExpressionList*> function_call_argument_clause
%nterm <ArrayExpression*> array_expression
%nterm <Program*> program
%nterm <DeclarationList*> global_list
%nterm <Declaration*> global_declaration
%nterm <DeclarationList*> declarations
%nterm <Declaration*> declaration
%nterm <FunctionDeclaration*> function_declaration
%nterm <FunctionDeclaration*> initializer_declaration
%nterm <FunctionDeclaration*> deinitializer_declaration
%nterm <PatternList*> function_declaration_argument_clause
%nterm <PatternList*> pattern_list
%nterm <Pattern*> pattern
%nterm <CodeBlock*> code_block
%nterm <StatementList*> statements
%nterm <Statement*> statement
%nterm <Expression*> primary_expression
%nterm <PrefixOperator> prefix_operator
%nterm <InfixOperator> infix_operator


%right "="
%left "+" "-" "or"
%left "*" "/" "and"
%nonassoc UMINUS
%nonassoc "not"

%%

%start program;

program:
    global_list { $$ = new Program($1); driver.program = $$; }
    ;

global_list:
    %empty { $$ = new DeclarationList(@$); }
    | global_declaration global_list { $2->AddDeclaration($1); $$ = $2; }
    ;

global_declaration:
    class_declaration
    | function_declaration { $$ = $1; }
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
    "String"
    | "Int"
    | "Bool"
    | "identifier"
    ;

declarations:
    %empty { $$ = new DeclarationList(@$); }
    | declaration declarations { $2->AddDeclaration($1); $$ = $2; }
    ;

declaration:
    constant_declaration
    | variable_declaration
    | function_declaration { $$ = $1; }
    | class_declaration
    | initializer_declaration { $$ = $1; }
    | deinitializer_declaration { $$ = $1; }
    ;

deinitializer_declaration:
    "deinit" code_block {} { $$ = new FunctionDeclaration(new PatternList(@$), $2, @$); }
    ;

constant_declaration:
    "let" pattern initializer
    ;

pattern_initializer:
    pattern
    | pattern initializer // TODO: Add "," separator
    ;

initializer:
    "=" expression // { $$ = $2; }
    ;

pattern:
    "_" { $$ = new Pattern($1, @$); }
    | "_" type_annotation // { $$ = new Pattern($1, $2, @$); }
    | "identifier" { $$ = new Pattern($1, @$); }
    | "identifier" type_annotation // { $$ = new Pattern($1, $2, @$); }
    ;

type_annotation:
    ":" type // { $$ = $2; }
    ;

variable_declaration:
    "var" pattern_initializer
    ;

function_declaration:
    "func" "identifier" function_declaration_argument_clause code_block { $$ = new FunctionDeclaration($3, $4, @$); }
    | "func" "identifier" function_declaration_argument_clause function_return_type code_block
    ;

function_declaration_argument_clause:
    "(" pattern_list ")" { $$ = $2; }
    ;

pattern_list:
    %empty { $$ = new PatternList(@$); }
    | pattern pattern_list { $2->AddPattern($1); $$ = $2; } // TODO: add "," separator
    ;

function_return_type:
    "->" type
    ;

initializer_declaration:
    "init" function_declaration_argument_clause code_block { $$ = new FunctionDeclaration($2, $3, @$); }
    ;

code_block:
    "{" statements "}" { $$ = new CodeBlock($2, @$); }
    ;

statements:
    %empty { $$ = new StatementList(@$); }
    | statement statements { $2->AddStatement($1); $$ = $2; } // TODO: fix '\n' separator
    ;

statement:
    expression { $$ = $1; }
    | declaration { $$ = $1; }
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
    primary_expression { $$ = $1; }
    | function_call_expression { $$ = $1; }
    | explicit_member_expression
    | subscript_expression { $$ = $1; }
    | prefix_operator expression { $$ = new UnaryExpression($2, $1, @$); }
    | expression infix_operator expression { $$ = new BinaryExpression($1, $3, $2, @$); }
    | array_expression { $$ = $1; }
    | "number" { $$ = new ObjectExpression($1, @$); }
    ;

expressions:
    %empty { $$ = new ExpressionList(@$); }
    | expression "," expressions { $3->AddExpression($1); $$ = $3; } // TODO: fix "," comma
    ;

array_expression:
    "[" expressions "]" { $$ = new ArrayExpression($2, @$); }
    ;

prefix_operator:
    "-" %prec UMINUS { $$ = PrefixOperator::PRMINUS; }
    | "not" { $$ = PrefixOperator::NOT; }
    ;

infix_operator:
    "+" { $$ = InfixOperator::PLUS; }
    | "*" { $$ = InfixOperator::MUL; }
    | "/" { $$ = InfixOperator::DIV; }
    | "-" { $$ = InfixOperator::MINUS; }
    | "and" { $$ = InfixOperator::AND; }
    | "or" { $$ = InfixOperator::OR; }
    | "=" { $$ = InfixOperator::ASSIGN; }
    | ">" { $$ = InfixOperator::GREATER; }
    | ">=" { $$ = InfixOperator::GREATEREQUAL; }
    | "<" { $$ = InfixOperator::LESS; }
    | "<=" { $$ = InfixOperator::LESSEQUAL; }
    | "==" { $$ = InfixOperator::EQUAL; }
    | "!=" { $$ = InfixOperator::NOTEQUAL; }
    ;

primary_expression:
    "identifier" { $$ = new IdentExpression($1, @$); }
    | "self"
    | "(" expression ")" { $$ = $2; }
    ;

function_call_expression:
    "identifier" function_call_argument_clause { $$ = new FunctionCallExpression($1, $2, @$); }
    ;

function_call_argument_clause:
    "(" ")" { $$ = new ExpressionList(@$); }
    | "(" expressions ")" { $$ = $2; }
    ;

explicit_member_expression:
    expression "." explicit_member_argument
    ;

explicit_member_argument:
    "identifier"
    | function_call_expression
    ;

subscript_expression:
    expression "[" expression "]" { $$ = new SubscriptExpression($1, $3, @$); }
    ;

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << " : " << m << "\n";
}
