%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *key;
     int value;
} map;
map symbol[100];
int getValue(map *m, int size, char *key);
void assignValue(map*m, int size, char *key, int value);
int nr_symbols = 0;
%}
%union {
     char* id;
     int int_val;
     char* str_val;
}

%token <int_val> NR
%token <str_val> STRING
%token <id> ID
%token TIP BGIN END ASSIGN PRINT
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
         | ID ASSIGN NR { assignValue(symbol, nr_symbols, $1, $3);}
         | PRINT ID {    char *current_id = $2;
                         printf("%d\n", getValue(symbol, nr_symbols, current_id));}
         | ID '(' lista_apel ')'
         ;
        
lista_apel : NR
           | lista_apel ',' NR
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int getValue(map *m, int size, char *key) {
    for (int i = 0; i < size ; i++) {
        if (strcmp(m[i].key, key) == 0) {
            return m[i].value;
        }
    }
    return -1;
}

void assignValue(map *m, int size, char *key, int value)
{
     for (int i = 0; i < size ; i++) {
        if (strcmp(m[i].key, key) == 0) {
               m[i].value = value;
               return;
        }
     }
     m[nr_symbols].key = key;
     m[nr_symbols].value = value;
     nr_symbols++;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 