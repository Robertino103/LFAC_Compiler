%{
#include <stdio.h>
#include <stdbool.h>
#define MAX_EL_ARRAY 1000
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *type;
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

typedef struct{
     char *method_name;
     char *type;
     int group_id;
     int nr_params;
     map params[100];
} methodmap;
methodmap method[100];

typedef struct{
     char *name;
     int group_id;
     map group_vars[100];
     vmap group_arrays[100];
     methodmap group_methods[100];
} objectmap;

typedef struct{
     char *group_name;
     int nr_methods;
     int nr_vars;
     int nr_arrays;
     int nr_objects;
     map group_vars[100];
     vmap group_arrays[100];
     methodmap group_methods[100];
     objectmap object[100];
} groupmap;
groupmap group[100];


int getValue(map *m, int size, char *key);
void assignValue(map*m, int size, char *key, int value);
void assignArrValue(vmap*m, int size, char *key, int pos, int value);
void printAll();
int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;

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
%token <id> TIP
%token BGIN END ASSIGN PRINT BGINGLOBAL ENDGLOBAL BGINFNCT ENDFNCT GROUP GROUP_ACCESS
%token BGINFIELDS ENDFIELDS BGINMETHODS ENDMETHODS
%start progr
%%
progr: global function_def declaratii bloc {printf("program corect sintactic\n");}
     ;

global : /* empty */ 
       | BGINGLOBAL global_defs ENDGLOBAL
       ;

global_defs : declaratie ';'
            | declaratii declaratie ';'
            ;

function_def : /* empty */
         | BGINFNCT functions ENDFNCT
         ;

functions : function ';'
          | functions function ';'
          ;

function : TIP ID '(' lista_param ')'
          ;

methods : /* empty */
        | method ';'
        | methods method ';'
        ;
     

method : TIP ID'('method_list_param')' '{'group_statement_list'}'{
         group[nr_groups].group_methods[group[nr_groups].nr_methods].method_name = $2;
         group[nr_groups].group_methods[group[nr_groups].nr_methods].type = $1;
         group[nr_groups].group_methods[group[nr_groups].nr_methods].group_id = nr_groups;
         group[nr_groups].nr_methods++;
         }
        ;

fields : /* empty */
       | field ';'
       | fields field ';'
       ;

field : TIP ID { assignValue(group[nr_groups].group_vars, group[nr_groups].nr_vars, $2, 0);
                 group[nr_groups].nr_vars++; }
      | TIP VID'['NR']' { for(int i=0; i<$4; i++)
                              assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, $2, i, 0);
                          group[nr_groups].group_arrays[group[nr_groups].nr_arrays].size = $4;
                          group[nr_groups].nr_arrays++; 
                        }
      ;

declaratii : /* empty */
           | declaratie ';'
	      | declaratii declaratie ';'
	   ;
declaratie : TIP ID { assignValue(variable, nr_vars, $2, 0);
                      nr_vars++; } //TODO : Assign different type of values.
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           | TIP VID'['NR']' {for(int i=0; i<$4; i++)
                                   assignArrValue(array, nr_arrays, $2, i, 0);
                              array[nr_arrays].size = $4;
                              nr_arrays++;     
                              }
           | GROUP ID '{' BGINFIELDS fields ENDFIELDS BGINMETHODS methods ENDMETHODS '}' {
               group[nr_groups].group_name = $2;
               //group[nr_groups].nr_vars = 0;
               //group[nr_groups].nr_arrays = 0;
               //group[nr_groups].nr_methods = 0;
               for(int i=0; i<group[nr_groups].nr_methods; i++)
               {
                    for(int j=0; j<group[nr_groups].group_methods[i].nr_params; j++)
                    {
                         printf("%s : %s -- %s -> %s : %s = %d\n", group[nr_groups].group_methods[i].type, group[nr_groups].group_name, group[nr_groups].group_methods[i].method_name,
                         group[nr_groups].group_methods[i].params[j].type, group[nr_groups].group_methods[i].params[j].key, group[nr_groups].group_methods[i].params[j].value);
                    }
               }
               nr_groups++;
           }
           | TIP ID ':' ID'('method_check_list_param')'{
               bool found_class = 0;
               bool found_method = 0;
               for(int i=0; i<nr_groups; i++)
               {
                    if(strcmp($2, group[i].group_name) == 0)
                    {
                         found_class = 1;
                         for(int j=0; j<group[nr_groups].nr_methods; j++)
                         {
                              if(strcmp($4, group[i].group_methods[j].method_name) == 0)
                              {
                                   found_method = 1;
                                   break;
                              }
                         }
                         break;
                    }
               }
               if (found_class == 0) MyError("No such class found!");
               else if (found_method == 0) MyError("No such method found!");
           }
           ;
lista_param : /* empty */
            | param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ;

method_list_param : /* empty */
                  | method_param
                  | method_list_param ',' method_param
                  ;

method_param : TIP ID {
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].type = $1;
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].key = $2;
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].value = 0;
     group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params++;
}
             ;

method_check_list_param : /* empty */
                  | method_check_param
                  | method_check_list_param ',' method_check_param
                  ;

method_check_param : TIP ID {
     
}
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
         | ID ID {
               int group_id = getGroupId($1);
               if(group_id == -1)
               {
                    MyError("No such group defined!");
               }
               else
               {
                    group[group_id].object[group[group_id].nr_objects].name = $2;
                    group[group_id].object[group[group_id].nr_objects].group_id = group_id;
                    /*for(int i=0; i<group[group_id].nr_vars; i++)
                    {
                         group[group_id].object[group[group_id].nr_objects].group_vars[i].key = group[group_id].group_vars[i].key;
                         group[group_id].object[group[group_id].nr_objects].group_vars[i].value = 0;
                    }
                    for(int j=0; j<group[group_id].nr_arrays; j++)
                    {
                         group[group_id].object[group[group_id].nr_objects].group_arrays[i].key = group[group_id].group_arrays[i].key;
                         group[group_id].object[group[group_id].nr_objects].group_arrays[i].value = 0;
                    }
                    group[group_id].object[group[group_id].nr_objects].group_methods = group[group_id].group_methods;
                    */
                    group[group_id].nr_objects++;
               }
         }
         | ID GROUP_ACCESS ID ASSIGN ID
         | ID GROUP_ACCESS ID ASSIGN NR {
               int group_id = getObjType($1);
               int obj_id = getObjId($1);
               if(group_id == -1) MyError("No such object found!");
               int ok = IsMethod($3, group_id);
               if(ok==0)
               {
                    MyError("No such method found!");
               }
               else
               {
                    assignValue(group[group_id].object[obj_id].group_vars, group[group_id].nr_vars, $3, $5);
               }
         }
         ;
        
lista_apel : NR
           | lista_apel ',' NR
           ;

group_statement_list : /* empty */
                     | group_statement ';'
                     | group_statement_list group_statement ';'
                     ;

group_statement : ID ASSIGN ID
                | ID ASSIGN NR {   if(!assignValueMethod(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, $1, $3))
                                        if (!assignValueMethod(variable, nr_vars, $1, $3))
                                             MyError("Variable %s not found!", $1);
                               }
                | VID'['NR']' ASSIGN ID {assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, $1, $3, getValue(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, $6));}
                | VID'['NR']' ASSIGN NR {assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, $1, $3, $6);}
                | PRINT ID {    char *current_id = $2;
                                printf("%d\n", getValue(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, current_id));}
                | PRINT {printAll(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params);}
                ;


%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int MyError(char *s)
{
     printf("[line %d] -- %s\n", yylineno, s);
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

int assignValueMethod(map *m, int size, char *key, int value)
{
     for (int i = 0; i < size ; i++) {
        if (strcmp(m[i].key, key) == 0) {
               m[i].value = value;
               return 1;
        }
     }
     return 0;
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

int getGroupId(char *name)
{
     for(int i=0; i<nr_groups; i++)
     {
          if(strcmp(name, group[i].group_name) == 0)
               return i;
     }
     return -1;
}

int getObjType(char *object)
{
     for(int i=0; i<nr_groups; i++)
     {
          for(int j=0; j<group[i].nr_objects; j++)
          {
               if(strcmp(object, group[i].object[j].name)==0)
               {
                    return group[i].object[j].group_id;
               }
          }
     }
     return -1;
}

int getObjId(char *object)
{
     for(int i=0; i<nr_groups; i++)
     {
          for(int j=0; j<group[i].nr_objects; j++)
          {
               if(strcmp(object, group[i].object[j].name)==0)
               {
                    return j;
               }
          }
     }
     return -1;
}

int IsMethod(char *method, int id)
{
     for(int i=0; i<group[id].nr_methods; i++)
     {
          if(strcmp(method, group[id].group_methods[i].method_name) == 0)
          {
               return 1;
          }
     }
     return 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 