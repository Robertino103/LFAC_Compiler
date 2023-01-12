%{
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 100
#define MAX_ARRAYS 100
#define MAX_EL_ARRAY 100
#define MAX_OBJECTS 50
#define MAX_METHODS 100
#define MAX_PARAMS 100
#define MAX_GROUPS 100
#define MAX_MSG 100
#define MAX_MSG_DIGITS 5
#define MAX_FUNCTIONS 100

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *type;
     char *key;
     char *value;
} varmap;
varmap variable[MAX_VARIABLES];

typedef struct{
     char *key;
     int size;
     char *type;
     char *value[MAX_EL_ARRAY];
} vecmap;
vecmap array[MAX_ARRAYS];

typedef struct{
     char *name;
     char *type;
     int nr_params;
    varmap params[MAX_PARAMS];
} methodmap;
methodmap method[MAX_METHODS];

typedef struct{
     char *name;
     char *type;
     int nr_params;
     varmap params[MAX_PARAMS];
} fnctmap;
fnctmap function[MAX_FUNCTIONS];

typedef struct{
     char *name;
     int nr_methods;
     int nr_vars;
     int nr_arrays;
     int nr_objects;
     varmap vars[MAX_OBJECTS][MAX_VARIABLES];
     vecmap arrays[MAX_OBJECTS][MAX_ARRAYS];
     methodmap methods[MAX_METHODS];
     varmap object[MAX_OBJECTS];
} groupmap;
groupmap group[MAX_GROUPS];

void printAll();
void MyError(char *err);
char* getVarType(varmap *m, int size, int index);
char* getArrType(vecmap *m, int size, int index);
void createSymbolTable();
int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;
int nr_functions = 0;
int param_no = 0;
int fnctId = -1;

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
%token IF FOR WHILE CHECK LE GE LT GT
%start progr
%%
progr: global function_def declaratii bloc {printf("\nSuccesfully compiled!\n"); createSymbolTable();}
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

function : TIP ID '(' fnct_list_param ')' {
     if(checkFunction(function, nr_functions, $2))
     {
          MyError("A function with the same name was already declared !");
     }
     function[nr_functions].type = $1;
     function[nr_functions].name = $2;
     nr_functions++;
}
         ;

fnct_list_param : /* empty */
                | fnct_param
                | fnct_list_param ',' fnct_param
                ;

fnct_param : TIP ID { 
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, $2))
     {
          MyError("Duplicate parameter used!");
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = $1;
     function[nr_functions].params[function[nr_functions].nr_params].key = $2;
     function[nr_functions].nr_params++;
}
           | TIP VID '['NR']' {
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, $2))
     {
          MyError("Duplicate parameter used!");
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = $1;
     function[nr_functions].params[function[nr_functions].nr_params].key = $2;
     function[nr_functions].nr_params++;
}
           ;

lista_param : /* empty */
            | param
            | lista_param ','  param 
            ;
            
param : TIP ID
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
          for(int i = 0; i < MAX_OBJECTS; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = $1;
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = $2;
          }
          group[nr_groups].nr_vars++; 
          }
      | TIP VID'['NR']' {
          if(getInt($4) > MAX_EL_ARRAY)
          {
               char err[MAX_MSG] = "Sorry! We can't hold more than ";
               char max_el[MAX_MSG_DIGITS];
               sprintf(max_el, "%d", MAX_EL_ARRAY);
               max_el[strlen(max_el)] = '\0';
               strcat(err, max_el);
               strcat(err, " elements in an array ! Go try writing in RUST! \n");
               MyError(err); 
          }

          for(int i = 0; i < MAX_OBJECTS; i++)
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
               if(checkArr(array, nr_arrays, $2)){
                    MyError("Array already declared!");
               }
               int val = getInt($4);
               if(val > MAX_EL_ARRAY)
               {
                    char err[MAX_MSG] = "Sorry! We can't hold more than ";
                    char max_el[MAX_MSG_DIGITS];
                    sprintf(max_el, "%d", MAX_EL_ARRAY);
                    max_el[strlen(max_el)] = '\0';
                    strcat(err, max_el);
                    strcat(err, " elements in an array ! Go try writing in RUST! \n");
                    MyError(err);
               }

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
                        
          } //TODO
         | PRINT ID
         | ID { fnctId = getFunctionId(function, nr_functions, $1); } '(' lista_apel ')' {
               if(checkFunction(function, nr_functions, $1) == 0)
               {
                    MyError("Called function has not been defined in the function definition section!");
               }
               param_no = 0;
         }
         | VID'['NR']' ASSIGN NR {
               int vid = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               if(vid == -1)
                    MyError("Array not found!\n");
               if(index < 0 || index >= array[vid].size)
                    MyError("Segmentation fault! (core dumped)\n");
               array[vid].value[index] = $6;
         }
         | VID'['NR']' ASSIGN ID {
               int arr_id = getVecId(array, nr_arrays, $1);
               int var_id = getVarId(variable, nr_vars, $6);
               int index = getInt($3);

               if(arr_id == -1)
                    MyError("Array not found!\n");
               if(var_id == -1)
                    MyError("Variable not found!\n");
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = variable[var_id].value;
         }
         | VID'['NR']' ASSIGN VID'['NR']'{
               int arr_id = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               int arr_id2 = getVecId(array, nr_arrays, $6);
               int index2 = getInt($8);

               if(arr_id == -1)
                    MyError("First array not found!\n");
               if(arr_id2 == -1)
                    MyError("Second array not found!\n");
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               if(index2 < 0 || index2 >= array[arr_id2].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = array[arr_id2].value[index2];
         }
         | VID'['NR']' ASSIGN ID GROUP_ACCESS ID{
               int arr_id = getVecId(array, nr_arrays, $1);
               int index = getInt($3);

               int group_id = getObjGroupId($6);
               int obj_id = getObjId($6, group_id);
               int var_id = getObjVarId($8, group_id, obj_id);

               if(arr_id == -1)
                    MyError("First array not found!\n");
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");  
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = group[group_id].vars[obj_id][var_id].value;
         }
         | VID'['NR']' ASSIGN ID GROUP_ACCESS VID'['NR']'{
               int arr_id = getVecId(array, nr_arrays, $1);
               int index = getInt($3);

               int group_id = getObjGroupId($6);
               int obj_id = getObjId($6, group_id);
               int arr_id2 = getObjVecId($8, group_id, obj_id);
               int index2 = getInt($10);

               if(arr_id == -1)
                    MyError("First array not found!\n");
               if(group_id == -1 || obj_id == -1 || arr_id2 == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");  
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               if(index2 < 0 || index2 >= array[arr_id2].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = group[group_id].arrays[obj_id][arr_id2].value[index2];
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
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the first variable does not exist!\n");
               if(assign_id == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
         | ID GROUP_ACCESS ID ASSIGN NR {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
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
                    MyError("Can't assign that becah the first variable does not exist!\n");
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN NR{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = $8;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN ID{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);
               int assign_id = getVarId(variable, nr_vars, $8);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(assign_id == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = variable[assign_id].value;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN ID GROUP_ACCESS ID {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               int group_id2 = getObjGroupId($8);
               int obj_id2 = getObjId($8, group_id2);
               int var_id2 = getObjVarId($10, group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].vars[obj_id2][var_id2].value;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN ID GROUP_ACCESS VID'['NR']' {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               int group_id2 = getObjGroupId($8);
               int obj_id2 = getObjId($8, group_id2);
               int arr_id2 = getObjVecId($10, group_id2, obj_id2);
               int index2 = getInt($12);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(group_id2 == -1 || obj_id2 == -1 || arr_id2 == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               if(index2 < 0 || index2 > group[group_id].arrays[obj_id][arr_id2].size)
                    MyError("Segmentation fault! (core dumped)\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].arrays[obj_id2][arr_id2].value[index2];
         }
         | IF '(' ctrl_statement ')' '{' list '}'
         | FOR '(' for_statement ')' '{' list '}'
         | WHILE '(' ctrl_statement ')' '{' list '}'
         ;

for_statement : ID ASSIGN ID ',' ID {
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $5))
     {
          MyError("Variable used in control statement not declared!");
     }
}
              | ID ASSIGN NR ',' NR
              | ID ASSIGN ID ',' NR {
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
              | ID ASSIGN NR ',' ID {
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $5))
     {
          MyError("Variable used in control statement not declared!");
     }
}
              ;
        
ctrl_statement : ID CHECK ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | ID CHECK NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR CHECK ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR CHECK NR
               | ID LT ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | ID LT NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR LT ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR LT NR
               | ID LE ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | ID LE NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR LE ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR LE NR
               | ID GT ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | ID GT NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR GT ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR GT NR
               | ID GE ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | ID GE NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR GE ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          MyError("Variable used in control statement not declared!");
     }
}
               | NR GE NR
               ;

lista_apel : /* empty */
           | apel
           | lista_apel ',' apel
           ;
apel : NR {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, param_no))
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, param_no);
          if (strcmp(def_type, "char") == 0)
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          else if (strcmp(def_type, "bool") == 0)
          {
               int nr_int = getInt($1);
               if (nr_int != 0 && nr_int != 1)
               {
                    MyError("The type of the variable in the function call does not match the function definition!");
               }
          }
          param_no++;
     }
     | ID {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, param_no))
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, param_no);
          if(checkVar(variable, nr_vars, $1) == 0)
          {
               MyError("The variable used in the function call is not declared!");
          }
          int current_var_id = getVarId(variable, nr_vars, $1);
          char *current_type = getVarType(variable, nr_vars, current_var_id);
          if (strcmp(def_type, current_type) != 0)
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          param_no++;
     }
     | VID {
          if(!isArray(function[fnctId].params, function[fnctId].nr_params, param_no))
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, param_no);
          if(checkArr(array, nr_arrays, $1) == 0)
          {
               MyError("The array used in the function call is not declared!");
          }
          int current_arr_id = getVecId(array, nr_arrays, $1);
          char *current_type = getArrType(array, nr_arrays, current_arr_id);
          if (strcmp(def_type, current_type) != 0)
          {
               MyError("The type of the array in the function call does not match the function definition!");
          }
          param_no++;
     }

group_statement_list : /* empty */
                     | group_statement ';'
                     | group_statement_list group_statement ';'
                     ;

group_statement : ID ASSIGN ID
                | ID ASSIGN NR {}
                | VID'['NR']' ASSIGN ID {}
                | VID'['NR']' ASSIGN NR {}
                | PRINT ID 
                ;


%%
int yyerror(char * s){
     printf("eroare: %s la linia:%d\n",s,yylineno);
}

void MyError(char *s){
     printf("\n[line %d error] -- %s\n", yylineno, s);
     exit(EXIT_FAILURE);
}

void createSymbolTable(){
     FILE* var_file;
     FILE* fun_file;
     var_file = fopen("./symbol_table.txt", "w");
     if(var_file == NULL){
          printf("Error printing to variable file!\n");
          exit(1);
     }
     fprintf(var_file, "Predefined variables: ('type' 'name' = 'value')\n");
     for(int i=0; i<nr_vars; i++)
     {
          if(variable[i].value == NULL)
               fprintf(var_file, "    %s %s\n", variable[i].type, variable[i].key);
          else
               fprintf(var_file, "    %s %s = %s\n", variable[i].type, variable[i].key, variable[i].value);
     }
     for(int i = 0; i < nr_arrays; i++)
     {
          fprintf(var_file, "    %s %s[%d] = {", array[i].type, array[i].key, array[i].size);
          if(array[i].size == 1){
               fprintf(var_file, "%s}\n", array[i].value[0]);
          }
          else{
               int j;
               for(j = 0; j < array[i].size-1; j++)
                    fprintf(var_file, "%s, ", array[i].value[j]);
               fprintf(var_file, "%s}\n", array[i].value[j]);
          }
     }

     fprintf(var_file, "\nUser defined variables: ('type' 'name' = 'value')\n");
     for(int i = 0; i < nr_groups; i++){
          for(int j = 0; j < group[i].nr_objects; j++)
               fprintf(var_file, "    %s %s\n", group[i].object[j].type, group[i].object[j].key);
     }
     for(int i = 0; i < nr_groups; i++){
          for(int k = 0; k < group[i].nr_objects; k++)
               for(int j = 0; j < group[i].nr_vars; j++)
                    if(group[i].vars[k][j].value != NULL)
                         fprintf(var_file, "    %s %s.%s = %s\n", group[i].vars[k][j].type, group[i].object[k].key, group[i].vars[k][j].key, group[i].vars[k][j].value);
                    else
                         fprintf(var_file, "    %s %s.%s\n", group[i].vars[k][j].type, group[i].object[k].key, group[i].vars[k][j].key);
          for(int k = 0; k < group[i].nr_objects; k++)
               for(int j = 0; j < group[i].nr_arrays; j++)
               {
                    fprintf(var_file, "    %s %s.%s[%d] = {", group[i].arrays[k][j].type, group[i].object[k].key, group[i].arrays[k][j].key, group[i].arrays[k][j].size);
                    if(group[i].arrays[k][j].size == 1)
                    {
                         fprintf(var_file, "%s}", group[i].arrays[k][j].value[0]);
                    }
                    else
                    {
                         int z;
                         for(z = 0; z < group[i].arrays[k][j].size - 1; z++)
                         {
                              fprintf(var_file, "%s, ", group[i].arrays[k][j].value[z]);
                         }
                         fprintf(var_file, "%s}\n", group[i].arrays[k][j].value[z]);
                    }
               }
               ;
     }
     fclose(var_file);

     fun_file = fopen("./symbol_table_functions.txt", "w");
     if(fun_file == NULL){
          printf("Error printing to functions file!\n");
          exit(1);
     }     

     fprintf(fun_file, "Methods: 'return_type' 'name'('param_type' 'param_name', ...)\n\n");
     for(int i = 0; i < nr_groups; i++){
          fprintf(fun_file, "%s:\n", group[i].name);
          for(int j = 0; j < group[i].nr_methods; j++){
               fprintf(fun_file, "    %s %s(", group[i].methods[j].type, group[i].methods[j].name);
               if(group[i].methods[j].nr_params == 1)
                    fprintf(fun_file, "%s %s)\n", group[i].methods[j].params[0].type, group[i].methods[j].params[0].key);
               else if(group[i].methods[j].nr_params == 0)
                    fprintf(fun_file, ")\n");
               else{
                    int k = 0;
                    for(k = 0; k < group[i].methods[j].nr_params - 1; k++)
                         fprintf(fun_file, "%s %s, ", group[i].methods[j].params[k].type, group[i].methods[j].params[k].key);
                    fprintf(fun_file, "%s %s)\n", group[i].methods[j].params[k].type, group[i].methods[j].params[k].key) ;
               }
          }
     }

     fprintf(fun_file, "\n\n\nFunctions: 'return_type' 'name'('param_type' 'param_name', ...)\n\n");
     for(int i = 0; i < nr_functions; i++){
          fprintf(fun_file, "    %s %s(", function[i].type, function[i].name);
               if(function[i].nr_params == 1)
                    fprintf(fun_file, "%s %s)\n", function[i].params[0].type, function[i].params[0].key);
               else if(function[i].nr_params == 0)
                    fprintf(fun_file, ")\n");
               else{
                    int k = 0;
                    for(k = 0; k < function[i].nr_params - 1; k++)
                         fprintf(fun_file, "%s %s, ", function[i].params[k].type, function[i].params[k].key);
                    fprintf(fun_file, "%s %s)\n", function[i].params[k].type, function[i].params[k].key) ;
               }
     }

     fclose(fun_file);
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

int getObjVecId(char *name, int group_id, int obj_id){
     for(int i = 0; i < group[group_id].nr_arrays; i++)
          if(strcmp(name, group[group_id].arrays[obj_id][i].key) == 0)
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

int checkArr(vecmap *m, int size, char *arr)
{
     for(int i=0; i<size; i++)
     {
          if(strcmp(m[i].key, arr) == 0)
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

int checkFunction(fnctmap *m, int size, char *function)
{
     for(int i=0; i<size; i++)
     {
          if(strcmp(m[i].name, function) == 0)
          {
               return 1;
          }
     }
     return 0;
}

int getFunctionId(fnctmap *m, int size, char *function)
{
     for(int i=0; i<size; i++)
     {
          if(strcmp(m[i].name, function) == 0)
          {
               return i;
          }
     }
     return -1;
}

char* getVarType(varmap *m, int size, int index)
{
     return m[index].type;
}

char* getArrType(vecmap *m, int size, int index)
{
     return m[index].type;
}

int isArray(varmap *m, int size, int index)
{
     char *varname = m[index].key;
     if(varname[0]=='@') return 1;
          else return 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}