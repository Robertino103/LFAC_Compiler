%{
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_EL_ARRAY 1000
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *type;
     char *key;
     char *value;
} varmap;
varmap variable[100];

typedef struct{
     char *key;
     int size;
     char *type;
     char *value[50];
} vecmap;
vecmap array[100];

typedef struct{
     char *name;
     char *type;
     int nr_params;
    varmap params[100];
} methodmap;
methodmap method[100];

typedef struct{
     char *name;
     int nr_methods;
     int nr_vars;
     int nr_arrays;
     int nr_objects;
     varmap vars[50][50];
     vecmap arrays[50][50];
     methodmap methods[100];
     varmap object[100];
} groupmap;
groupmap group[100];

void printAll();
void MyError(char *err);
int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;

%}
%union {
     char* id;
     char* val;
}

%token <val> NR
%token <id> ID
%token <id> GID
%token <id> VID
%token <id> TIP
%token BGIN END ASSIGN PRINT BGINGLOBAL ENDGLOBAL BGINFNCT ENDFNCT GROUP GROUP_ACCESS
%token BGINFIELDS ENDFIELDS BGINMETHODS ENDMETHODS
%start progr
%%
progr: global function_def declaratii bloc {printf("\nSuccesfully compiled!\n");}
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
         if(checkMethod(group[nr_groups].methods, group[nr_groups].nr_methods, $2))
         {
               MyError("Method already defined!");
         }
         group[nr_groups].methods[group[nr_groups].nr_methods].name = $2;
         group[nr_groups].methods[group[nr_groups].nr_methods].type = $1;
         group[nr_groups].nr_methods++;
         }
         ;

fields : /* empty */
       | field ';'
       | fields field ';'
       ;

field : TIP ID {
          if(checkVar(group[nr_groups].vars[0], group[nr_groups].nr_vars, $2))
          {
               MyError("Field variable already declared!");
          }
          for(int i = 0; i < 50; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = $1;
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = $2;
          }
          group[nr_groups].nr_vars++; 
          }
      | TIP VID'['NR']' {

          for(int i = 0; i < 50; i++)
          {
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].type = $1;
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].key = $2;
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].size = getInt($4);
               for(int j = 0 ; j < getInt($4); j++)
               {
                    group[nr_groups].arrays[i][group[nr_groups].nr_arrays].value[j] = "0";
               }
          }
          group[nr_groups].nr_arrays++;
          }
      ;

declaratii : /* empty */
           | declaratie ';'
	      | declaratii declaratie ';'
	   ;
declaratie : TIP ID {
               if(checkVar(variable, nr_vars, $2))
               {
                    MyError("Variable already declared!");
               }
               variable[nr_vars].type = $1;
               variable[nr_vars].key = $2;
               nr_vars++;     
          }
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           | TIP VID'['NR']'{
               int val = getInt($4);
               if(val > 50)
                    MyError("Sorry! We can't hold more than 50 elements in an array ! Go try RUST!\n");

               array[nr_arrays].key = $2;
               array[nr_arrays].size = val;
               array[nr_arrays].type = $1;
               for(int i = 0; i < val; i++)
                    array[nr_arrays].value[i] = "0";
               nr_arrays++;
           }
           | GROUP GID '{' BGINFIELDS fields ENDFIELDS BGINMETHODS methods ENDMETHODS '}' {
               group[nr_groups].name = $2;
               nr_groups++;
           }
           | TIP ID ':' ID'('method_check_list_param')'{
               bool found_class = 0;
               bool found_method = 0;
               for(int i=0; i<nr_groups; i++)
               {
                    if(strcmp($2, group[i].name) == 0)
                    {
                         found_class = 1;
                         for(int j=0; j<group[nr_groups].nr_methods; j++)
                         {
                              if(strcmp($4, group[i].methods[j].name) == 0)
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
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, $2))
     {
          MyError("Duplicate parameter used!");
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = $1;
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = $2;
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
             | TIP VID '['NR']' {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, $2))
     {
          MyError("Duplicate parameter used!");
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = $1;
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = $2;
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
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
statement: ID ASSIGN ID {
               int id = getVarId(variable, nr_vars, $1);
               int id2 = getVarId(variable, nr_vars, $3);
               if(id == -1)
                    MyError("First variable not found!\n");
               else if(id2 == -1)
                    MyError("Second variable not found!\n");
               else if(variable[id2].value == NULL)
                    MyError("Second variable does not store a value!\n");
               else
                    variable[id].value = variable[id2].value;
          }
         | ID ASSIGN NR {
               int id = getVarId(variable, nr_vars, $1);
               if(id == -1)
                    MyError("Variable not found!\n");
               else
                    variable[id].value = $3;
                        
          }
         | PRINT ID
         | PRINT { printAll(variable, nr_vars); }
         | ID '(' lista_apel ')'
         | VID'['NR']' ASSIGN ID
         | VID'['NR']' ASSIGN NR {
               int vid = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               if(vid == -1)
                    MyError("Array not found!\n");
               if(index < 0 || index >= array[vid].size)
                    MyError("Segmentation fault! (core dumped)\n");
               array[vid].value[index] = $6;
         }
         | GID ID {
               int group_id = getGroupId($1);
               if(group_id == -1)
               {
                    MyError("No such group defined!");
               }
               else{
                    group[group_id].object[group[group_id].nr_objects].key = $2;
                    group[group_id].object[group[group_id].nr_objects].type = $1;
                    group[group_id].nr_objects++;
               }
         }
         | ID GROUP_ACCESS ID ASSIGN ID {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               int assign_id = getVarId(variable, nr_vars, $5);
               if(assign_id == -1)
                    MyError("Can't assign that becah doesnt not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
         | ID GROUP_ACCESS ID ASSIGN NR {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the variable does not not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = $5;
         }
         | ID GROUP_ACCESS ID ASSIGN ID GROUP_ACCESS ID {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               
               int group_id2 = getObjGroupId($5);
               int obj_id2 = getObjId($5, group_id2);
               int var_id2 = getObjVarId($7, group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the first variable does not not exist!\n");
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the second variable does not not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
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
                | ID ASSIGN NR {
                               }
                | VID'['NR']' ASSIGN ID {}
                | VID'['NR']' ASSIGN NR {}
                | PRINT ID 
                | PRINT 
                ;


%%
int yyerror(char * s){
     printf("eroare: %s la linia:%d\n",s,yylineno);
}

void MyError(char *s){
     printf("\n[line %d error] -- %s\n", yylineno, s);
     exit(EXIT_FAILURE);
}

void printAll(){
     printf("----  identifiers  ----\n\n");
     for(int i=0; i<nr_vars; i++)
     {
          if(variable[i].value == NULL)
               printf("    %s %s\n", variable[i].type, variable[i].key);
          else
               printf("    %s %s = %s\n", variable[i].type, variable[i].key, variable[i].value);
     }
     for(int i = 0; i < nr_arrays; i++)
     {
          printf("    %s[%d] = {", array[i].key, array[i].size);
          if(array[i].size == 1){
               printf("%s}\n", array[i].value[0]);
          }
          else{
               int j;
               for(j = 0; j < array[i].size-1; j++)
                    printf("%s, ", array[i].value[j]);
               printf("%s}\n", array[i].value[j]);
          }
     }
     for(int i = 0; i < nr_groups; i++){
          for(int j = 0; j < group[i].nr_objects; j++)
               printf("    %s %s\n", group[i].object[j].type, group[i].object[j].key);
     }
     for(int i = 0; i < nr_groups; i++){
          for(int k = 0; k < group[i].nr_objects; k++)
               for(int j = 0; j < group[i].nr_vars; j++)
                    if(group[i].vars[k][j].value != NULL)
                         printf("    %s %s.%s = %s\n", group[i].vars[k][j].type, group[i].object[k].key, group[i].vars[k][j].key, group[i].vars[k][j].value);
                    else
                         printf("    %s %s.%s\n", group[i].vars[k][j].type, group[i].object[k].key, group[i].vars[k][j].key);
          for(int k = 0; k < group[i].nr_objects; k++)
               for(int j = 0; j < group[i].nr_arrays; j++)
               {
                    printf("    %s %s.%s[%d] = {", group[i].arrays[k][j].type, group[i].object[k].key, group[i].arrays[k][j].key, group[i].arrays[k][j].size);
                    if(group[i].arrays[k][j].size == 1)
                    {
                         printf("%s}", group[i].arrays[k][j].value[0]);
                    }
                    else
                    {
                         int z;
                         for(z = 0; z < group[i].arrays[k][j].size - 1; z++)
                         {
                              printf("%s, ", group[i].arrays[k][j].value[z]);
                         }
                         printf("%s}\n", group[i].arrays[k][j].value[z]);
                    }
               }
               ; //TODO
     }
     printf("\n----  methods  ----\n\n");
     for(int i = 0; i < nr_groups; i++){
          printf("%s:\n", group[i].name);
          for(int j = 0; j < group[i].nr_methods; j++){
               printf("    %s %s(", group[i].methods[j].type, group[i].methods[j].name);
               if(group[i].methods[j].nr_params == 1)
                    printf("%s %s)\n", group[i].methods[j].params[0].type, group[i].methods[j].params[0].key);
               else if(group[i].methods[j].nr_params == 0)
                    printf(")\n");
               else{
                    int k = 0;
                    for(k = 0; k < group[i].methods[j].nr_params - 1; k++)
                         printf("%s %s, ", group[i].methods[j].params[k].type, group[i].methods[j].params[k].key);
                    printf("%s %s)\n", group[i].methods[j].params[k].type, group[i].methods[j].params[k].key) ;
               }
          }
     }
     printf("\n");
}

int getInt(char *var){
     const char *s = var;
     int int_val;
     sscanf(s, "%d", &int_val);
     return int_val;
}

int getVecId(vecmap *m, int size, char *vec){
     for(int i = 0; i < size; i++)
          if(strcmp(vec, m[i].key) == 0)
               return i;
     return -1;
}

int getVarId(varmap *m, int size, char *var){
     for(int i = 0; i < size; i++)
          if(strcmp(var, m[i].key) == 0)
               return i;
     return -1;
}

int getObjVarId(char *name, int group_id, int obj_id){
     for(int i = 0; i < group[group_id].nr_vars; i++)
          if(strcmp(name, group[group_id].vars[obj_id][i].key) == 0)
               return i;
     return -1;
}

int getObjId(char *name, int group_id){
     for(int i = 0; i < group[group_id].nr_objects; i++)
          if(strcmp(name, group[group_id].object[i].key) == 0)
               return i;
     return -1;
}

int getObjGroupId(char *name){
     for(int i = 0; i < nr_groups; i++)
          for(int j = 0; j < group[i].nr_objects; j++)
               if(strcmp(name, group[i].object[j].key) == 0)
                    return i;
     return -1;
}

int getGroupId(char *name){
     for(int i = 0; i < nr_groups; i++){
          if(strcmp(name, group[i].name) == 0)
               return i;
     }
     return -1;
}


int IsMethod(char *method, int id)
{
     for(int i=0; i<group[id].nr_methods; i++)
     {
          if(strcmp(method, group[id].methods[i].name) == 0)
          {
               return 1;
          }
     }
     return 0;
}

int checkVar(varmap *m, int size, char *var)
{
     for(int i=0; i<size; i++)
     {
          if(strcmp(m[i].key, var) == 0)
          {
               return 1;
          }
     }
     return 0;
}

int checkMethod(methodmap *m, int size, char *method)
{
     for(int i=0; i<size; i++)
     {
          if(strcmp(m[i].name, method) == 0)
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