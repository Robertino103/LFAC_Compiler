%{
#include <stdio.h>
#define MAX_EL_ARRAY 1000
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *key;
     int value;
} map;
map variable[100];

typedef struct{
     char *key;
     int size;
     int value[MAX_EL_ARRAY];
} vmap;
vmap array[100];

int getValue(map *m, int size, char *key);
void assignValue(map*m, int size, char *key, int value);
void assignArrValue(vmap*m, int size, char *key, int pos, int value);
void printAll();
int nr_vars = 0;
int nr_arrays = 0;
%}
%union {
     char* id;
     int int_val;
     char* str_val;
}

%token <int_val> NR
%token <str_val> STRING
%token <id> ID
%token <id> VID
%token TIP BGIN END ASSIGN PRINT BGINGLOBAL ENDGLOBAL BGINFNCT ENDFNCT
%start progr
%%
progr: global function declaratii bloc {printf("program corect sintactic\n");}
     ;

global : /* empty */ 
       | BGINGLOBAL global_defs ENDGLOBAL
       ;

global_defs : declaratie ';'
            | declaratii declaratie ';'
            ;

function : /* empty */
         | BGINFNCT functions ENDFNCT
         ;

functions : TIP ID '(' lista_param ')'
          | TIP ID '(' ')'
          ;

declaratii : /* empty */
           | declaratie ';'
	      | declaratii declaratie ';'
	   ;
declaratie : TIP ID { assignValue(variable, nr_vars, $2, 0);
                      nr_vars++; }
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           | TIP VID'['NR']' {for(int i=0; i<$4; i++)
                                   assignArrValue(array, nr_arrays, $2, i, 0);
                              array[nr_arrays].size = $4;
                              nr_arrays++;     
                              }
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
list : /* empty */ 
     | statement ';' 
     | list statement ';'
     ;

/* instructiune */
statement: ID ASSIGN ID
         | ID ASSIGN NR { assignValue(variable, nr_vars, $1, $3);}
         | PRINT ID {    char *current_id = $2;
                         printf("%d\n", getValue(variable, nr_vars, current_id));}
         | PRINT {printAll(variable, nr_vars);}
         | ID '(' lista_apel ')'
         | VID'['NR']' ASSIGN ID {assignArrValue(array, nr_arrays, $1, $3, getValue(variable, nr_vars, $6));}
         | VID'['NR']' ASSIGN NR {assignArrValue(array, nr_arrays, $1, $3, $6);}
         | VID ASSIGN VID
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
     m[nr_vars].key = key;
     m[nr_vars].value = value;
     //nr_vars++;
}

void printAll()
{
     for(int i=0; i<nr_vars; i++)
     {
          printf("%s -> %d\n", variable[i].key, variable[i].value);
     }
     for(int i=0; i<nr_arrays; i++)
     {
          for(int j=0; j<array[i].size; j++)
               printf("%s[%d] -> %d\n", array[i].key, j, array[i].value[j]);
     }
}

void assignArrValue(vmap*m, int size, char *key, int pos, int value)
{
     for(int i=0;i<size;i++)
     {
          if (strcmp(m[i].key, key) == 0)
          {
               m[i].value[pos] = value;
               return;
          }
     }
     m[size].key = key;
     m[size].value[0] = 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 