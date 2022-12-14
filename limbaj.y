%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%union {
     int intval;
}
%token <intval> NR
%type <intval> statement
%token TIP BGIN END ASSIGN PRINT ID
%start progr
%%
progr: declaratii list {printf("program corect sintactic\n");}
     ;

declaratii : declaratie ';'
	      | declaratii declaratie ';'
	   ;
declaratie : TIP ID 
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           ;
lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
      
/* bloc */
bloc : BGIN list END
     ;
     
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     ;

/* instructiune */
statement: ID ASSIGN ID
         | ID ASSIGN NR {$1 = $3; }
         | PRINT ID {printf("%d\n", $2);}
         | ID '(' lista_apel ')'
         ;
        
lista_apel : NR
           | lista_apel ',' NR
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 