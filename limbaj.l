%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {  
    yylval.id = strdup(yytext);
    return TIP;}
"const int"|"const float"|"const char"|"const string" {  
    yylval.id = strdup(yytext);
    return CTIP;}
"TypeOf" {return TYPEOF;}
"begin_globaldef" {return BGINGLOBAL;}
"end_globaldef" {return ENDGLOBAL;}
"begin_fnct" {return BGINFNCT;}
"end_fnct" {return ENDFNCT;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
$[_a-zA-Z][_a-zA-Z0-9]* {   yylval.id = strdup(yytext);
                            return ID;}
@[_a-zA-Z][_a-zA-Z0-9]* {   yylval.id = strdup(yytext);
                            return VID;}
"FALSE"|"TRUE" {
    yylval.id = strdup(yytext);
    return BOOLVAL;
}
"Eval" {return EVAL;}
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return TIMES; }
"/" { return DIVIDE; }
"((" { return LPAREN; }
"))" { return RPAREN; }
"||" { return OR; }
"&&" { return AND; }
"if" {return IF;}
"for" {return FOR;}
"while" {return WHILE;}
"=" {return ASSIGN;}
":=" {return ASSIGNEXP;}
"==" {return CHECK;}
"<" {return LT;}
"<=" {return LE;}
">" {return GT;}
">=" {return GE;}
"." {return GROUP_ACCESS;}
"print" {return PRINT;}
"group" {return GROUP;}
"begin_fields" {return BGINFIELDS;}
"end_fields" {return ENDFIELDS;}
"begin_methods" {return BGINMETHODS;}
"end_methods" {return ENDMETHODS;}

\"[_a-zA-Z]\" {
    yylval.val = strdup(yytext);
    return CHAR;
}

\"(\\.|[^"\\])*\" {
    yylval.val = strdup(yytext);               
    return STRING;
}

[0-9]+ {
    yylval.val = strdup(yytext);
    return NR;
}
[0-9]+[.][0-9]+ {
    yylval.val = strdup(yytext);
    return FNR;
}

[_a-zA-Z][_a-zA-Z0-9]* {   yylval.id = strdup(yytext);
                            return GID;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
