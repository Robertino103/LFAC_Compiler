%{
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
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
#define MAX_EXPRESSIONS 100
#define MAX_EXP_SIZE 100
#define INT_MIN -2147483648
#define MAX_STR 200
#define MAX_VAR_SIZE 20

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
     int param_no;
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

typedef struct{
     char *type;
     char expr[MAX_EXP_SIZE];
     char *value;
} expmap;
expmap expression[MAX_EXPRESSIONS];

void printAll();
void MyError(char *err);
char* getVarType(varmap *m, int size, int index);
char* getArrType(vecmap *m, int size, int index);
char* getFnctType(fnctmap *m, int size, int index);
void createSymbolTable();
void checkExprType(char* var_name);
void assignCheckTypes(varmap *m1, int size1, char *var1, varmap *m2, int size2, char *var2);
void assignCheckTypesArrArr(vecmap *m1, int size1, char *var1, vecmap *m2, int size2, char *var2);
void assignCheckTypesArr(varmap *m1, int size1, char *var1, vecmap *m2, int size2, char *var2);
void checkFunType(char *var_name);
char *infixToPostfix(char *infix);
char *swapWithValue(char *infix);

int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;
int nr_functions = 0;
int nr_expr = 0;
int param_no = 0;
int fnctId = -1;
int fnctId2 = -1;
char *expr_current_type;

struct ASTNode {
  char* type;
  int value;
  struct ASTNode* left;
  struct ASTNode* right;
};

struct StackNode {
    struct ASTNode* node;
    struct StackNode* next;
};

struct ASTNode* pop(struct StackNode** root){
    if (*root == NULL)
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;    
    struct ASTNode* popped = temp->node;
    free(temp);
    return popped;
}

void push(struct StackNode** root, struct ASTNode* node){
    struct StackNode* new_node = (struct StackNode*) malloc(sizeof(struct StackNode));
    new_node->node = node;
    new_node->next = *root;
    *root = new_node;
}

struct ASTNode* buildAST(char* postfix){
    struct StackNode* stack = NULL;
    int i;
    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            struct ASTNode* new_node = (struct ASTNode*) malloc(sizeof(struct ASTNode));
            new_node->type = "operand";
            new_node->value = postfix[i] - '0';
            new_node->left = NULL;
            new_node->right = NULL;
            push(&stack, new_node);
        } else {
            struct ASTNode* new_node = (struct ASTNode*) malloc(sizeof(struct ASTNode));
            new_node->type = "operator";
            new_node->value = postfix[i];
            new_node->right = pop(&stack);
            new_node->left = pop(&stack);
            push(&stack, new_node);
        }
    }
    return pop(&stack);
}

void printAST(struct ASTNode* root) {
    if (root != NULL) {
        if (root->type == "operand") {
            printf("%d ", root->value);
        }
        else {
            printf("%c ", root->value);
            printAST(root->left);
            printAST(root->right);
        }
    }
}

int eval(struct ASTNode* node) {
  if (node->type == "operand") {
    return node->value;
  } else if (node->type == "operator") {
    switch (node->value) {
      case '+':
        return eval(node->left) + eval(node->right);
      case '-':
        return eval(node->left) - eval(node->right);
      case '*':
        return eval(node->left) * eval(node->right);
      case '/':
        return eval(node->left) / eval(node->right);
    }
  }
}

%}
%union {
     char* id;
     char* val;
}

%token <val> NR
%token <val> FNR
%token <val> STRING
%token <val> CHAR
%token <id> ID
%token <id> GID
%token <id> VID
%token <id> TIP
%token <id> CTIP
%token <id> BOOLVAL

%token BGIN END ASSIGN ASSIGNEXP PRINT BGINGLOBAL ENDGLOBAL BGINFNCT ENDFNCT GROUP GROUP_ACCESS
%token BGINFIELDS ENDFIELDS BGINMETHODS ENDMETHODS
%token IF FOR WHILE CHECK LE GE LT GT 
%token PLUS MINUS TIMES DIVIDE
%token LPAREN RPAREN
%token OR AND
%token TYPEOF EVAL

%left PLUS MINUS
%left TIMES DIVIDE

%start progr
%%
progr: global function_def declaratii bloc {printf("\nSuccesfully compiled!\n\n"); createSymbolTable();}
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
          char err[MAX_MSG];
          sprintf(err,"The function '%s' was already declared !", $2);
          MyError(err);
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
          char err[MAX_MSG];
          sprintf(err,"Duplicate usage of parameter '%s'!", $2);
          MyError(err);
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = $1;
     function[nr_functions].params[function[nr_functions].nr_params].key = $2;
     function[nr_functions].nr_params++;
}
           | TIP VID '['NR']' {
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, $2))
     {
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of parameter '%s'!", $2);
          MyError(err);
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
               char err[MAX_MSG];
               sprintf(err, "Method '%s' already defined!", $2);
               MyError(err);
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
               char err[MAX_MSG];
               sprintf(err, "Duplicate usage of the field variable '%s'", $2);
               MyError(err);
          }
          for(int i = 0; i < MAX_OBJECTS; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = $1;
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = $2;
          }
          group[nr_groups].nr_vars++; 
          }
      | TIP VID'['NR']' {
          if(getInt($4) > MAX_EL_ARRAY){
               char err[MAX_MSG];
               sprintf(err, "Sorry! We can't hold more than %d elements in an array ! Go try writing in RUST! \n", MAX_EL_ARRAY);
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
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' already declared!", $2);
                    MyError(err);
               }
               variable[nr_vars].type = $1;
               variable[nr_vars].key = $2;
               nr_vars++;     
          }
           | TIP ID ASSIGN NR {
               char err[MAX_MSG];
               sprintf(err, "You can't assign a value there unless '%s' is of constant type!\n");
               MyError(err);
           }
           | CTIP ID ASSIGN NR {
               variable[nr_vars].type = $1;
               variable[nr_vars].key = $2;
               variable[nr_vars].value = $4;
               nr_vars++;
           }
           | CTIP ID{
               char err[MAX_MSG];
               sprintf(err, "Can't declare a constant without assigning a value to it!\n");
               MyError(err);
           }
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           | TIP VID'['NR']'{
               if(checkArr(array, nr_arrays, $2)){
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' already declared!", $2);
                    MyError(err);
               }
               int val = getInt($4);
               if(val > MAX_EL_ARRAY)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Sorry! We can't hold more than %d elements in an array ! Go try writing in RUST!", MAX_EL_ARRAY);
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
               if(checkGroup(group, nr_groups, $2)){
                    char err[MAX_MSG];
                    sprintf(err, "Group '%s' already declared previously!", $2);
                    MyError(err);
               }
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
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of the parameter '%s'", $2);
          MyError(err);
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = $1;
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = $2;
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
             | TIP VID '['NR']' {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, $2))
     {
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of the parameter '%s'", $2);
          MyError(err);
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

expressions : arithmexp 
            | booleanexp 
            ;
          
booleanexp : boolean
           | booleanexp boolean
           ;

arithmexp : arithmetic
          | arithmexp arithmetic
          ;

boolean : BOOLVAL {strcat(expression[nr_expr].expr, $1);}
        | ID { 
               int id = getVarId(variable, nr_vars, $1);
               if(strcmp(variable[id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of boolean type!\n", $1);
                    MyError(err);
               }
               strcat(expression[nr_expr].expr, $1);
               expr_current_type = "bool";
          }
        | boolean OR {strcat(expression[nr_expr].expr, "||" );} boolean
        | boolean AND {strcat(expression[nr_expr].expr, "&&");} boolean
        | LPAREN {strcat(expression[nr_expr].expr, "(");} boolean RPAREN {strcat(expression[nr_expr].expr, ")");}
        ;

arithmetic : NR {strcat(expression[nr_expr].expr, $1); expr_current_type = "int";}
           | ID {checkExprType($1); strcat(expression[nr_expr].expr, $1);}
           | arithmetic PLUS {strcat(expression[nr_expr].expr, "+");} arithmetic
           | arithmetic MINUS {strcat(expression[nr_expr].expr, "-");} arithmetic
           | arithmetic TIMES {strcat(expression[nr_expr].expr, "*");} arithmetic
           | arithmetic DIVIDE {strcat(expression[nr_expr].expr, "/");} arithmetic
           | LPAREN {strcat(expression[nr_expr].expr, "(");} arithmetic RPAREN {strcat(expression[nr_expr].expr, ")");} 
           ;

statement:| ID ASSIGN CHAR {
               int id = getVarId(variable, nr_vars, $1);
               if(strcmp(variable[id].type, "char") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of char type!\n", $1);
                    MyError(err);
               }
               variable[id].value = $3;
          }
          | ID ASSIGN STRING {
               int id = getVarId(variable, nr_vars, $1);
               if(strcmp(variable[id].type, "string") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of string type!\n", $1);
                    MyError(err);
               }
               variable[id].value = $3;
          } 
         | ID ASSIGN BOOLVAL {
               int id = getVarId(variable, nr_vars, $1);
               if(strcmp(variable[id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of bool type!\n", $1);
                    MyError(err);
               }
               variable[id].value = $3;
          }
         | ID ASSIGNEXP expressions {
               int id = getVarId(variable, nr_vars, $1);
               if(id == -1){
                    char err[MAX_MSG];
                    sprintf(err, "Variable %s does not exist!\n", $1);
                    MyError(err);
               }
               if(expr_current_type == NULL)
                    expr_current_type = variable[id].type;
               else if(strcmp(variable[id].type, expr_current_type) != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign '%s' expression because the variable '%s' expects a type of '%s'!\n", expr_current_type, $1, variable[id].type);
                    MyError(err);
               }
               expression[nr_expr].type = expr_current_type;
               variable[id].value = expression[nr_expr].expr;
               expr_current_type = NULL;

         }
         | ID ASSIGN ID {
               int id = getVarId(variable, nr_vars, $1);
               int id2 = getVarId(variable, nr_vars, $3);
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf("Variable '%s' not declared previously", $1);
                    MyError(err);
               }
               else if(id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $3);
                    MyError(err);
               }
               else if(variable[id2].value == NULL)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' does't have a stored value!", $3);
                    MyError(err);
               }
               
               variable[id].value = variable[id2].value;
               assignCheckTypes(variable, nr_vars, $1, variable, nr_vars, $3);
          }
         | ID ASSIGN NR {
               int id = getVarId(variable, nr_vars, $1);
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $1);
                    MyError(err);
               }
               
               variable[id].value = $3;
               if(strcmp(variable[id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", $1, variable[id].type);
                    MyError(err);
               }
                        
          }
          | ID ASSIGN FNR {
               int id = getVarId(variable, nr_vars, $1);
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $1);
                    MyError(err);
               }
               variable[id].value = $3;
               if(strcmp(variable[id].type, "float") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an float value to '%s' because it expects a value of type '%s'!\n", $1, variable[id].type);
                    MyError(err);
               }

          }
          | VID '['NR']' ASSIGN FNR {
               int vid = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(array[vid].type, "float") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an float value to '%s[%d]' because it expects a value of type '%s'!\n", $1, index, array[vid].type);
                    MyError(err);
               }
               array[vid].value[index] = $6;
         }
         | VID '['NR']' ASSIGN BOOLVAL {
              int vid = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(array[vid].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an bool value to '%s[%d]' because it expects a value of type '%s'!\n", $1, index, array[vid].type);
                    MyError(err);
               }
               array[vid].value[index] = $6;
         }
         | ID ASSIGN VID'['NR']'{
               int id = getVarId(variable, nr_vars, $1);
               int vid = getVecId(array, nr_arrays, $3);
               int index = getInt($5);
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $3);
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               assignCheckTypesArr(variable, nr_vars, $1, array, nr_arrays, $3);
               variable[id].value = array[vid].value[index];
         }
         | ID GROUP_ACCESS ID ASSIGN CHAR {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "char") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an char value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
               group[group_id].vars[obj_id][var_id].value = $5;
         }
         | ID GROUP_ACCESS ID ASSIGN STRING {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "string") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an string value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
               group[group_id].vars[obj_id][var_id].value = $5;
         }
         | ID GROUP_ACCESS ID ASSIGN BOOLVAL {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an bool value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
               group[group_id].vars[obj_id][var_id].value = $5;
         }
         | ID GROUP_ACCESS ID ASSIGN FNR {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "float") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an float value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
               group[group_id].vars[obj_id][var_id].value = $5;
         }
         | ID ASSIGN ID GROUP_ACCESS ID{
               int group_id = getObjGroupId($3);
               int obj_id = getObjId($3, group_id);
               int var_id = getObjVarId($5, group_id, obj_id);
               int id = getVarId(variable, nr_vars, $1);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' does not exist!", $3, $5);
                    MyError(err);
               }
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $1);
                    MyError(err);
               }
               assignCheckTypes(variable, nr_vars, $1, group[group_id].vars[obj_id], group[group_id].nr_vars, $5);
               variable[id].value = group[group_id].vars[obj_id][var_id].value;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN BOOLVAL{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(group[group_id].arrays[obj_id][arr_id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an bool value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].arrays[obj_id][arr_id].type);
                    MyError(err);
               }
               group[group_id].arrays[obj_id][arr_id].value[index] = $8;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN FNR{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(group[group_id].arrays[obj_id][arr_id].type, "float") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an float value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].arrays[obj_id][arr_id].type);
                    MyError(err);
               }
               group[group_id].arrays[obj_id][arr_id].value[index] = $8;
         }
         | ID ASSIGN ID GROUP_ACCESS VID'['NR']'{
               int group_id = getObjGroupId($3);
               int obj_id = getObjId($3, group_id);
               int arr_id = getObjVecId($5, group_id, obj_id);
               int index = getInt($7);
               int id = getVarId(variable, nr_vars, $1);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' does not exist!", $3, $5);
                    MyError(err);
               }
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               assignCheckTypesArr(variable, nr_vars, $1, group[group_id].arrays[obj_id], group[group_id].nr_arrays, $5);
               variable[id].value = group[group_id].arrays[obj_id][arr_id].value[index];
         }
         | PRINT ID
         | ID { fnctId = getFunctionId(function, nr_functions, $1); } '(' lista_apel ')' {
               if(checkFunction(function, nr_functions, $1) == 0)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Called function '%s' has not been defined!", $1);
                    MyError(err);
               }
               function[fnctId].param_no = 0;
         }
         | VID'['NR']' ASSIGN NR {
               int vid = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(array[vid].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s[%d]' because it expects a value of type '%s'!\n", $1, index, array[vid].type);
                    MyError(err);
               }
               array[vid].value[index] = $6;
         }
         | VID'['NR']' ASSIGN ID {
               int arr_id = getVecId(array, nr_arrays, $1);
               int var_id = getVarId(variable, nr_vars, $6);
               int index = getInt($3);

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $6);
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               assignCheckTypesArr(variable, nr_vars, $6, array, nr_arrays, $1);
               array[arr_id].value[index] = variable[var_id].value;
         }
         | VID'['NR']' ASSIGN VID'['NR']'{
               int arr_id = getVecId(array, nr_arrays, $1);
               int index = getInt($3);
               int arr_id2 = getVecId(array, nr_arrays, $6);
               int index2 = getInt($8);

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $6);
                    MyError(err);
               }
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index, $1);
                    MyError(err);
               }
               if(index2 < 0 || index2 >= array[arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index2, $6);
                    MyError(err);
               }
               assignCheckTypesArrArr(array, nr_arrays, $1, array, nr_arrays, $6);
               array[arr_id].value[index] = array[arr_id2].value[index2];
         }
         | VID'['NR']' ASSIGN ID GROUP_ACCESS ID{
               int arr_id = getVecId(array, nr_arrays, $1);
               int index = getInt($3);

               int group_id = getObjGroupId($6);
               int obj_id = getObjId($6, group_id);
               int var_id = getObjVarId($8, group_id, obj_id);

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $6, $8);
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               assignCheckTypesArr(group[group_id].vars[obj_id], group[group_id].nr_vars, $8, array, nr_arrays, $1);
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
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", $1);
                    MyError(err);
               }
               if(group_id == -1 || obj_id == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $6, $8);
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index, $1);
                    MyError(err);
               }
               if(index2 < 0 || index2 >= array[arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index2, $8);
                    MyError(err);
               }
               assignCheckTypesArrArr(group[group_id].arrays[obj_id], group[group_id].nr_arrays, $8, array, nr_arrays, $1);
               array[arr_id].value[index] = group[group_id].arrays[obj_id][arr_id2].value[index2];
         }
         | GID ID {
               int group_id = getGroupId($1);
               if(group_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Group '%s' not defined previously!", $1);
                    MyError(err);
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
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(assign_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $5);
                    MyError(err);
               } 
               assignCheckTypes(variable, nr_vars, $5, group[group_id].vars[obj_id], group[group_id].nr_vars, $3);
               group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
         | ID GROUP_ACCESS ID ASSIGN NR {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
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
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $5, $7);
                    MyError(err);
               } 
               assignCheckTypes(group[group_id].vars[obj_id], group[group_id].nr_vars, $3, group[group_id2].vars[obj_id2], group[group_id2].nr_vars, $7);
               group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
         | ID GROUP_ACCESS ID ASSIGN ID GROUP_ACCESS VID'['NR']' {
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int var_id = getObjVarId($3, group_id, obj_id);

               int group_id2 = getObjGroupId($5);
               int obj_id2 = getObjId($5, group_id2);
               int arr_id2 = getObjVecId($7, group_id2, obj_id2);
               int index = getInt($9);

               if(group_id2 == -1 || obj_id2 == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $5, $7);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id2].arrays[obj_id2][arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               } 
               assignCheckTypesArr(group[group_id].vars[obj_id], group[group_id].nr_vars, $3, group[group_id2].arrays[obj_id2], group[group_id2].nr_arrays, $7);
               group[group_id].vars[obj_id][var_id].value = group[group_id2].arrays[obj_id2][arr_id2].value[index];
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN NR{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(strcmp(group[group_id].arrays[obj_id][arr_id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", $3, group[group_id].arrays[obj_id][arr_id].type);
                    MyError(err);
               }
               group[group_id].arrays[obj_id][arr_id].value[index] = $8;
         }
         | ID GROUP_ACCESS VID'['NR']' ASSIGN ID{
               int group_id = getObjGroupId($1);
               int obj_id = getObjId($1, group_id);
               int arr_id = getObjVecId($3, group_id, obj_id);
               int index = getInt($5);
               int assign_id = getVarId(variable, nr_vars, $8);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(assign_id == -1)
               {    
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", $8);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               assignCheckTypesArr(variable, nr_vars, $8, group[group_id].arrays[obj_id], group[group_id].nr_arrays, $3);
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
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", $8, $10);
                    MyError(err);
               } 
               assignCheckTypesArr(group[group_id2].vars[obj_id2], group[group_id2].nr_vars, $10, group[group_id].arrays[obj_id], group[group_id].nr_arrays, $3);
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
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $1, $3);
                    MyError(err);
               }
               if(group_id2 == -1 || obj_id2 == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", $8, $10);
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s.%s' array!", index, $1, $3);
                    MyError(err);
               }
               if(index2 < 0 || index2 > group[group_id].arrays[obj_id][arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s.%s' array!", index2, $8, $10);
                    MyError(err);
               }
               assignCheckTypesArrArr(group[group_id].arrays[obj_id], group[group_id].nr_arrays, $3, group[group_id2].arrays[obj_id2], group[group_id2].nr_arrays, $10);
               group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].arrays[obj_id2][arr_id2].value[index2];
         }
         | IF '(' ctrl_statement ')' '{' list '}'
         | FOR '(' for_statement ')' '{' list '}'
         | WHILE '(' ctrl_statement ')' '{' list '}'
         | EVAL '(' expressions ')'{
               expression[nr_expr].type = expr_current_type;
               expr_current_type = NULL;
               char *infix;
               infix = expression[nr_expr].expr;
               infix = swapWithValue(infix);
               char *postfix = infixToPostfix(infix);
               printf("Postfix expression: %s\n", postfix);
               struct ASTNode* root = buildAST(postfix);
               printf("AST in preorder: ");
               printAST(root);
               int val_exp = eval(root);
               printf("\nEval(%s) = %d\n", expression[nr_expr].expr, val_exp);
               
               strcpy(expression[nr_expr].expr, "");
               expression[nr_expr].type = NULL;
         }
         | TYPEOF '(' ID GROUP_ACCESS ID ')' {
               int group_id = getObjGroupId($3);
               int obj_id = getObjId($3, group_id);
               int var_id = getObjVarId($5, group_id, obj_id);
               printf("TypeOf(%s.%s) = %s\n", $3, $5, getVarType(group[group_id].vars[obj_id], group[group_id].nr_vars, var_id));
         }
         | TYPEOF '(' ID ')' {
               printf("TypeOf(%s) = %s\n", $3, getVarType(variable, nr_vars, getVarId(variable, nr_vars, $3)));
         }
         | TYPEOF '(' VID ')' {
               printf("TypeOf(%s) = %s\n", $3, getArrType(array, nr_arrays, getVecId(array,nr_arrays, $3)));
         }
         | TYPEOF '(' NR ')' {
               printf("TypeOf(%s) = int\n", $3);
         }
         | TYPEOF '(' expressions ')' {
               expression[nr_expr].type = expr_current_type;
               expr_current_type = NULL;
               printf("TypeOf(%s) = %s\n", expression[nr_expr].expr, expression[nr_expr].type);
               strcpy(expression[nr_expr].expr, "");
               expression[nr_expr].type = NULL;
         }
         ;
         ;

for_statement : ID ASSIGN ID ',' ID {
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $5))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $5);
          MyError(err);
     }
}
              | ID ASSIGN NR ',' NR
              | ID ASSIGN ID ',' NR {
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
              | ID ASSIGN NR ',' ID {
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $5))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $5);
          MyError(err);
     }
}
              ;
        
ctrl_statement : ID CHECK ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | ID CHECK NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
}
               | NR CHECK ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | NR CHECK NR
               | ID LT ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | ID LT NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
}
               | NR LT ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | NR LT NR
               | ID LE ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | ID LE NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
}
               | NR LE ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | NR LE NR
               | ID GT ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | ID GT NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
}
               | NR GT ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | NR GT NR
               | ID GE ID{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | ID GE NR{
     if(!checkVar(variable, nr_vars, $1))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $1);
          MyError(err);
     }
}
               | NR GE ID{
     if(!checkVar(variable, nr_vars, $3))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", $3);
          MyError(err);
     }
}
               | NR GE NR
               ;

lista_apel : /* empty */
           | apel
           | lista_apel ',' apel
           ;
apel : NR {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if (strcmp(def_type, "char") == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          else if (strcmp(def_type, "bool") == 0)
          {
               int nr_int = getInt($1);
               if (nr_int != 0 && nr_int != 1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
                    MyError(err);
               }
          }
          function[fnctId].param_no++;
     }
     | ID {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if(checkVar(variable, nr_vars, $1) == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          int current_var_id = getVarId(variable, nr_vars, $1);
          char *current_type = getVarType(variable, nr_vars, current_var_id);
          if (strcmp(def_type, current_type) != 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          function[fnctId].param_no++;
     }
     | VID {
          if(!isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if(checkArr(array, nr_arrays, $1) == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          int current_arr_id = getVecId(array, nr_arrays, $1);
          char *current_type = getArrType(array, nr_arrays, current_arr_id);
          if (strcmp(def_type, current_type) != 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", $1);
               MyError(err);
          }
          function[fnctId].param_no++;
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


     fprintf(var_file, "\nUsed expressions:\n");
     for(int i = 0; i < nr_expr; i++)
          fprintf(var_file, "    %s   (type: %s)\n", expression[i].expr, expression[i].type);

     fclose(fun_file);
     fclose(var_file);
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

char* getFnctType(fnctmap *m, int size, int index)
{
     return m[index].type;
}

int isArray(varmap *m, int size, int index)
{
     char *varname = m[index].key;
     if(varname[0]=='@') return 1;
          else return 0;
}

void checkExprType(char *var_name) {
     int id = getVarId(variable, nr_vars, var_name);
     if(id == -1){
          char errMsg[100];
          sprintf(errMsg,"Variable '%s' does not exist!\n", var_name);
          MyError(errMsg);
     }
     if(expr_current_type == NULL)
          expr_current_type = variable[id].type;
     else if(strcmp(variable[id].type, expr_current_type) != 0){
          char errMsg[100];
          sprintf(errMsg,"Variable '%s' has type '%s' but expected '%s'\n", var_name, variable[id].type, expr_current_type);
          MyError(errMsg);
     }
}

void checkFunType(char *var_name){
     int id = getFunctionId(function, nr_functions, var_name);
     if(id == -1){
          char errMsg[100];
          sprintf(errMsg,"Function '%s' does not exist!\n", var_name);
          MyError(errMsg);
     }
     if(expr_current_type == NULL)
          expr_current_type = function[id].type;
     else if(strcmp(function[id].type, expr_current_type) != 0){
          char errMsg[100];
          sprintf(errMsg,"Function '%s' has return type '%s' but expected '%s'\n", var_name, function[id].type, expr_current_type);
          MyError(errMsg);
     }
}

void assignCheckTypes(varmap *m1, int size1, char *var1, varmap *m2, int size2, char *var2){
     int id1 = getVarId(m1, size1, var1);
     int id2 = getVarId(m2, size2, var2);
     if(strcmp(m1[id1].type, m2[id2].type) != 0){
          char err[MAX_MSG];
          sprintf(err, "Cannot assign because '%s' is of type '%s' and '%s' is of type '%s'!\n", var1, m1[id1].type, var2, m2[id2].type);
          MyError(err);
     }
     return;
}

void assignCheckTypesArr(varmap *m1, int size1, char *var1, vecmap *m2, int size2, char *var2){
     int id1 = getVarId(m1, size1, var1);
     int id2 = getVecId(m2, size2, var2);
     if(strcmp(m1[id1].type, m2[id2].type) != 0){
          char err[MAX_MSG];
          sprintf(err, "Cannot assign because '%s' is of type '%s' and '%s' is of type '%s'!\n", var1, m1[id1].type, var2, m2[id2].type);
          MyError(err);
     }
     return;
}

void assignCheckTypesArrArr(vecmap *m1, int size1, char *var1, vecmap *m2, int size2, char *var2){
     int id1 = getVecId(m1, size1, var1);
     int id2 = getVecId(m2, size2, var2);
     if(strcmp(m1[id1].type, m2[id2].type) != 0){
          char err[MAX_MSG];
          sprintf(err, "Cannot assign because '%s' is of type '%s' and '%s' is of type '%s'!\n", var1, m1[id1].type, var2, m2[id2].type);
          MyError(err);
     }
     return;
}


int checkGroup(groupmap *m, int size, char *group)
{
     for(int i = 0; i < size; i++)
     {
          if(strcmp(m[i].name, group) == 0)
          {
               return 1;
          }
     }
     return 0;
}

int orderOperator(char operator) {
     switch (operator) {
          case '+':
          case '-':
               return 1;
          case '*':
          case '/':
               return 2;
          case '^':
               return 3;
          default:
               return -1;
     }
}
 
int isOperator(char ch) {
     return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
 
char *infixToPostfix(char *infix){
     int i, j;
     int len = strlen(infix);
     char *postfix = (char *)malloc(sizeof(char) * (len + 2));
     char stack[MAX_EXP_SIZE];
     int top = -1;
     
     for (i = 0, j = 0; i < len; i++) {
          if (infix[i] == ' ' || infix[i] == '\t')
               continue;
          while (isalnum(infix[i]) || infix[i] == '$') {
               postfix[j++] = infix[i];
               i++;
          } 
          //postfix[j++] = ' ';
          if (infix[i] == '(') {
               stack[++top] = infix[i];
          } else if (infix[i] == ')') {
               while (top > -1 && stack[top] != '(')
                    postfix[j++] = stack[top--];
               if (top > -1 && stack[top] != '(')
                    return "Invalid Expression";
               else
                    top--;
          } else if (isOperator(infix[i])) {
               while (top > -1 && orderOperator(stack[top]) >= orderOperator(infix[i])){
                    postfix[j++] = stack[top--];
                    //postfix[j++] = ' ';
               }
               stack[++top] = infix[i];
          }
     }
     
     while (top > -1)
          postfix[j++] = stack[top--];
     
     postfix[j] = '\0';
     return postfix;
}

char *swapWithValue(char *infix){
     char result[MAX_EXP_SIZE] = {""};
     int k = 0;
     for(int i = 0; i < strlen(infix); i++){
          if(infix[i] == '$'){
               char temp_var[MAX_EXP_SIZE] = {""};
               int temp_k = 0;
               while(strchr("+-*/()", infix[i]) == NULL){
                    temp_var[temp_k++] = infix[i++];
               }
               int var_id = getVarId(variable, nr_vars, temp_var);
               if(var_id == -1){
                    char err[MAX_MSG*2];
                    sprintf(err, "Variable %s not declared!\n", temp_var);
                    MyError(err);
               }
               char *value = variable[var_id].value;
               for(int j = 0; j < strlen(value); j++)
                    result[k++] = value[j];
               result[k++] = infix[i];
          }
          else
               result[k++] = infix[i];
     }
     result[k]= '\0';
     char *p = result;
     return p  ;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}