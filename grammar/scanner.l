%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
}%

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
    yy::parser::symbol_type make_NUMBER(
        const std::string& s,
        const yy::parser::location_type& loc
    );
}%

id      [a-zA-Z_][a-zA-Z_0-9]*
int     [0-9]+
blank   [ \t\r]

%{
}%

%%

%{
    yy::location_type& loc = driver.location;

    loc.step();
}%

{blank}+    loc.step();
\n+         loc.lines(yyleng); loc.step();

"-"         {
                std::cout << loc.begin.line << " " << loc.end.line << std::endl;
                return yy::parser::make_MINUS(loc);
            }
"+"         return yy::parser::make_PLUS(loc);
"*"         return yy::parser::make_STAR(loc);
"/"         return yy::parser::make_SLASH(loc);
"("         return yy::parser::make_LBRACKET(loc);
")"         return yy::parser::make_RBRACKET(loc);
"{"         return yy::parser::make_LEFTSCOPE(loc);
"}"         return yy::parser::make_RIGHTSCOPE(loc);
">"         return yy::parser::make_GT(loc);
"<"         return yy::parser::make_LT(loc);
">="        return yy::parser::make_GE(loc);
"<="        return yy::parser::make_LE(loc);
"=="        return yy::parser::make_EQ(loc);
"="         return yy::parser::make_EQUAL(loc);
","         return yy::parser::make_COMMA(loc);
"if"        return yy::parser::make_IF(loc);
"else"      return yy::parser::make_ELSE(loc);
"return"    return yy::parser::make_RETURN(loc);
"var"       return yy::parser::make_VAR(loc);
"func"      return yy::parser::make_FUNC(loc);

{int}       return yy::parser::make_NUMBER(yytext, loc);
{id}        return yy::parser::make_IDENTIFIER(yytext, loc);
.           {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
            }
<<EOF>>     return yy::parser::make_END(loc);

%%

yy::parser::symbol_type make_NUMBER(
    const std::string& s,
    const yy::parser::location_type& loc
) {
    errno = 0;
    long n = strtol(s.c_str(), NULL, 10);
    if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE)) {
        throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
    }
    return yy::parser::make_NUMBER((int) n, loc);
}
