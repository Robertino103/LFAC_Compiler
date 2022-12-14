%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {return TIP;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
@[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
"=" {return ASSIGN;}
"print" {return PRINT;}
[0-9]+ {
    //yylval.intval = atoi(yytext);
    return NR;
}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
