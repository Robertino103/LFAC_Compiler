%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {return TIP;}
"begin_globaldef" {return BGINGLOBAL;}
"end_globaldef" {return ENDGLOBAL;}
"begin_fnct" {return BGINFNCT;}
"end_fnct" {return ENDFNCT;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
@[_a-zA-Z][_a-zA-Z0-9]* {   yylval.id = strdup(yytext);
                            return ID;}
"=" {return ASSIGN;}
"print" {return PRINT;}
[0-9]+ {
    yylval.int_val = atoi(yytext);
    return NR;
}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
