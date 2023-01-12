/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"

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
#define MAX_EXPRESSIONS 100
#define MAX_EXP_SIZE 100

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
void addExpression();

int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;
int nr_functions = 0;
int nr_expr = 0;
int param_no = 0;
int fnctId = -1;
int fnctId2 = -1;
char *expr_current_type;


#line 166 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NR = 258,
    ID = 259,
    GID = 260,
    VID = 261,
    TIP = 262,
    BGIN = 263,
    END = 264,
    ASSIGN = 265,
    ASSIGNEXP = 266,
    PRINT = 267,
    BGINGLOBAL = 268,
    ENDGLOBAL = 269,
    BGINFNCT = 270,
    ENDFNCT = 271,
    GROUP = 272,
    GROUP_ACCESS = 273,
    BGINFIELDS = 274,
    ENDFIELDS = 275,
    BGINMETHODS = 276,
    ENDMETHODS = 277,
    IF = 278,
    FOR = 279,
    WHILE = 280,
    CHECK = 281,
    LE = 282,
    GE = 283,
    LT = 284,
    GT = 285,
    PLUS = 286,
    MINUS = 287,
    TIMES = 288,
    DIVIDE = 289,
    LPAREN = 290,
    RPAREN = 291
  };
#endif
/* Tokens.  */
#define NR 258
#define ID 259
#define GID 260
#define VID 261
#define TIP 262
#define BGIN 263
#define END 264
#define ASSIGN 265
#define ASSIGNEXP 266
#define PRINT 267
#define BGINGLOBAL 268
#define ENDGLOBAL 269
#define BGINFNCT 270
#define ENDFNCT 271
#define GROUP 272
#define GROUP_ACCESS 273
#define BGINFIELDS 274
#define ENDFIELDS 275
#define BGINMETHODS 276
#define ENDMETHODS 277
#define IF 278
#define FOR 279
#define WHILE 280
#define CHECK 281
#define LE 282
#define GE 283
#define LT 284
#define GT 285
#define PLUS 286
#define MINUS 287
#define TIMES 288
#define DIVIDE 289
#define LPAREN 290
#define RPAREN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 96 "limbaj.y"

     char* id;
     char* val;

#line 295 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   120,   121,   124,   125,   128,   129,   132,
     133,   136,   149,   150,   151,   154,   165,   178,   179,   180,
     183,   186,   187,   188,   192,   205,   206,   207,   210,   223,
     244,   245,   246,   248,   259,   260,   261,   282,   291,   315,
     316,   317,   320,   331,   344,   345,   346,   349,   355,   359,
     360,   361,   367,   368,   371,   372,   373,   373,   374,   374,
     375,   375,   376,   376,   377,   377,   380,   381,   392,   416,
     428,   452,   472,   500,   501,   501,   510,   527,   553,   586,
     615,   651,   665,   685,   698,   722,   753,   774,   802,   833,
     871,   872,   873,   876,   896,   897,   911,   927,   941,   949,
     957,   958,   972,   980,   988,   989,  1003,  1011,  1019,  1020,
    1034,  1042,  1050,  1051,  1065,  1073,  1081,  1084,  1085,  1086,
    1088,  1114,  1138,  1264,  1265,  1266,  1269,  1270,  1271,  1272,
    1273
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NR", "ID", "GID", "VID", "TIP", "BGIN",
  "END", "ASSIGN", "ASSIGNEXP", "PRINT", "BGINGLOBAL", "ENDGLOBAL",
  "BGINFNCT", "ENDFNCT", "GROUP", "GROUP_ACCESS", "BGINFIELDS",
  "ENDFIELDS", "BGINMETHODS", "ENDMETHODS", "IF", "FOR", "WHILE", "CHECK",
  "LE", "GE", "LT", "GT", "PLUS", "MINUS", "TIMES", "DIVIDE", "LPAREN",
  "RPAREN", "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'", "':'",
  "$accept", "progr", "global", "global_defs", "function_def", "functions",
  "function", "fnct_list_param", "fnct_param", "lista_param", "param",
  "methods", "method", "fields", "field", "declaratii", "declaratie",
  "method_list_param", "method_param", "method_check_list_param",
  "method_check_param", "bloc", "list", "expression", "arithmetic", "$@1",
  "$@2", "$@3", "$@4", "$@5", "statement", "$@6", "for_statement",
  "ctrl_statement", "lista_apel", "apel", "group_statement_list",
  "group_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    59,    40,    41,
      44,    91,    93,   123,   125,    58
};
# endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    29,     7,     6,    44,    33,    63,    29,    28,  -107,
      65,    29,   -23,    41,    73,  -107,    60,    94,    97,    54,
      88,    35,    95,    -6,   138,   156,   187,   191,   169,  -107,
     171,  -107,    99,   173,  -107,  -107,   205,  -107,   114,  -107,
     175,   177,   204,   207,  -107,  -107,    21,   208,   179,   211,
     183,   185,   188,  -107,    75,    10,    87,   181,  -107,  -107,
    -107,   209,   210,  -107,    58,    40,   193,    67,   116,  -107,
     103,    10,    84,   189,  -107,   219,  -107,   154,   220,   154,
      10,  -107,   195,  -107,    87,  -107,  -107,  -107,  -107,  -107,
    -107,   221,   122,  -107,  -107,   196,   212,   197,  -107,  -107,
     199,  -107,   207,  -107,   213,   201,    10,   218,   202,   137,
     203,   100,   109,   214,   225,   215,   216,    81,  -107,    10,
      10,    10,    10,  -107,  -107,   210,   226,   229,  -107,   235,
    -107,    90,   236,   162,   238,  -107,  -107,  -107,   128,  -107,
     234,   166,   168,   170,   172,   174,   176,   178,   180,   182,
     184,   206,   186,   217,   222,  -107,   158,   158,  -107,  -107,
    -107,   224,   242,    12,   227,   228,  -107,   230,   231,  -107,
     232,   233,  -107,   137,   141,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,    99,   223,   237,    99,    99,
    -107,   240,   239,   243,  -107,  -107,   244,  -107,   127,   241,
    -107,  -107,   249,   245,     0,   190,   192,     5,    51,   250,
    -107,  -107,   246,  -107,   248,   194,   142,   253,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,   145,   160,  -107,  -107,   255,
    -107,   251,  -107,   252,   254,  -107,   256,   247,   250,   257,
     146,   258,  -107,   259,    79,  -107,  -107,  -107,   260,   261,
     262,   264,   265,   268,    14,   263,   273,  -107,  -107,   198,
     276,  -107,  -107,   270,  -107,   266,  -107,  -107,   267,  -107,
    -107,   271,   200,  -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     7,     0,     0,     0,     0,     0,     1,
       0,    30,    33,     0,     0,     4,     0,    31,     0,     0,
       0,     0,     0,    17,     0,     0,     0,    32,     0,     8,
       0,     9,    49,     0,     2,    31,     0,    35,     0,    18,
       0,     0,    25,    12,    10,    54,    55,     0,     0,     0,
       0,     0,     0,    64,     0,    66,    52,     0,    32,    20,
      34,     0,    44,    36,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    81,     0,    73,     0,     0,     0,
       0,    48,     0,    55,    53,    56,    58,    60,    62,    50,
      19,     0,     0,    45,    28,     0,     0,     0,    26,    15,
       0,    11,     0,    69,    68,     0,    67,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,    47,    38,     0,     0,    21,    27,     0,
      14,     0,     0,     0,     0,   120,   121,   122,     0,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    57,    59,    61,    63,
      46,     0,     0,     0,     0,     0,    71,     0,     0,    83,
      82,     0,    75,     0,     0,   100,    99,   108,   107,   116,
     115,   104,   103,   112,   111,    98,    97,   106,   105,   114,
     113,   102,   101,   110,   109,    49,     0,     0,    49,    49,
      29,     0,     0,     0,    22,    16,     0,    70,     0,     0,
     119,    76,    77,     0,     0,     0,     0,     0,     0,    39,
      37,    23,     0,    84,     0,     0,     0,     0,    90,    94,
      96,    95,    93,    91,    92,     0,     0,    40,    72,     0,
      86,    87,    79,     0,     0,    42,     0,     0,     0,     0,
       0,     0,    78,     0,   123,    41,    85,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    43,     0,
       0,   130,    24,     0,   124,     0,   127,   126,     0,   125,
      89,     0,     0,   129,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,  -107,  -107,  -107,   272,  -107,   150,  -107,
     269,  -107,    85,  -107,   274,   281,    30,  -107,    11,  -107,
     143,  -107,  -106,   275,   -53,  -107,  -107,  -107,  -107,  -107,
     -54,  -107,  -107,   277,  -107,   111,  -107,    18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    11,    19,    20,    68,    69,    38,
      39,   163,   164,    65,    66,     7,     8,   236,   237,    92,
      93,    34,    54,    55,    56,   119,   120,   121,   122,    80,
      57,    73,   115,   113,   138,   139,   264,   265
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    36,    84,    45,    46,    47,    48,     9,    45,    46,
      47,    48,    49,    45,    83,    23,     1,    49,   261,   162,
     262,    10,    24,    50,    51,    52,   263,   117,    50,    51,
      52,    70,    71,    37,   202,    53,     4,    16,    14,    72,
      53,    22,     4,    32,   228,    53,     5,    64,    12,   233,
      13,    33,     5,    84,    45,    46,    47,    48,   272,   -74,
      96,    18,    94,    49,    95,    17,   156,   157,   158,   159,
      29,    99,    18,   100,    50,    51,    52,    15,    45,    46,
      47,    48,    25,   261,    81,   262,    53,    49,   107,   214,
     108,   263,   217,   218,   166,   234,   167,    27,    50,    51,
      52,    28,    45,    46,    47,    48,   103,   104,    -5,   105,
      53,    49,    85,    86,    87,    88,    26,   155,    85,    86,
      87,    88,    50,    51,    52,    31,   141,   142,   143,   144,
     145,   223,    35,   224,    53,   146,   147,   148,   149,   150,
     135,   136,    40,   137,   211,   212,   242,   213,   243,   245,
     257,   246,   258,    60,    61,   101,   102,   111,   112,    41,
      82,   124,   125,    82,    82,   169,   170,   172,   173,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   196,
     197,    87,    88,   229,   230,   231,   232,   240,   241,   247,
     248,   276,   277,   283,   284,    -6,    42,    43,    44,    59,
      58,    64,    74,    62,    67,    76,    36,    91,    89,    63,
      75,    77,   110,    78,   114,   123,    79,   109,   133,   161,
      98,   131,   118,   127,   128,   152,   162,   126,   165,   168,
     129,   171,   132,   134,   174,   140,   201,   222,   203,   195,
     208,   225,   130,   151,   153,   154,   244,   235,   249,   255,
     198,   259,   260,   215,   204,   199,   200,   226,   160,   250,
     205,   206,   271,   207,   269,   209,   275,   216,   219,   278,
     221,   282,   273,   220,   210,     0,   227,     0,   238,   239,
     254,    30,    21,   251,     0,     0,   252,   253,     0,   256,
     274,   266,     0,   267,   268,     0,   270,   279,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116
};

static const yytype_int16 yycheck[] =
{
      54,     7,    55,     3,     4,     5,     6,     0,     3,     4,
       5,     6,    12,     3,     4,    38,    13,    12,     4,     7,
       6,    15,    45,    23,    24,    25,    12,    80,    23,    24,
      25,    10,    11,    39,    22,    35,     7,     7,     5,    18,
      35,    11,     7,     8,    44,    35,    17,     7,     4,    44,
       6,    21,    17,   106,     3,     4,     5,     6,    44,    38,
      20,     7,     4,    12,     6,    37,   119,   120,   121,   122,
      16,     4,     7,     6,    23,    24,    25,    14,     3,     4,
       5,     6,    41,     4,     9,     6,    35,    12,     4,   195,
       6,    12,   198,   199,     4,    44,     6,    37,    23,    24,
      25,     4,     3,     4,     5,     6,     3,     4,    14,     6,
      35,    12,    31,    32,    33,    34,    43,    36,    31,    32,
      33,    34,    23,    24,    25,    37,    26,    27,    28,    29,
      30,     4,    37,     6,    35,    26,    27,    28,    29,    30,
       3,     4,     4,     6,     3,     4,     4,     6,     6,     4,
       4,     6,     6,    39,    40,    39,    40,     3,     4,     3,
     214,    39,    40,   217,   218,     3,     4,    39,    40,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,    33,    34,     3,     4,     3,     4,     3,     4,    39,
      40,     3,     4,     3,     4,    14,    19,    38,    37,     4,
      37,     7,     4,    38,     7,     4,     7,     7,    37,    42,
      41,    38,     3,    38,     4,     4,    38,    38,    10,     3,
      37,    18,    37,    21,    37,    10,     7,    41,     3,     3,
      41,     3,    41,    41,    10,    42,     4,     3,   163,    43,
      18,    10,   102,    39,    39,    39,     3,     7,     3,   248,
      43,     3,     3,    40,    37,    43,    42,    18,   125,    18,
      42,    41,     4,    42,    10,    42,     3,    40,    38,     3,
      37,    10,   264,    44,   173,    -1,    41,    -1,    42,    41,
      43,    19,    11,    41,    -1,    -1,    42,    41,    -1,    42,
      37,    41,    -1,    42,    42,    -1,    41,    37,    42,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    47,    48,     7,    17,    49,    61,    62,     0,
      15,    50,     4,     6,     5,    14,    62,    37,     7,    51,
      52,    61,    62,    38,    45,    41,    43,    37,     4,    16,
      52,    37,     8,    62,    67,    37,     7,    39,    55,    56,
       4,     3,    19,    38,    37,     3,     4,     5,     6,    12,
      23,    24,    25,    35,    68,    69,    70,    76,    37,     4,
      39,    40,    38,    42,     7,    59,    60,     7,    53,    54,
      10,    11,    18,    77,     4,    41,     4,    38,    38,    38,
      75,     9,    76,     4,    70,    31,    32,    33,    34,    37,
      56,     7,    65,    66,     4,     6,    20,    60,    37,     4,
       6,    39,    40,     3,     4,     6,    69,     4,     6,    38,
       3,     3,     4,    79,     4,    78,    79,    70,    37,    71,
      72,    73,    74,     4,    39,    40,    41,    21,    37,    41,
      54,    18,    41,    10,    41,     3,     4,     6,    80,    81,
      42,    26,    27,    28,    29,    30,    26,    27,    28,    29,
      30,    39,    10,    39,    39,    36,    70,    70,    70,    70,
      66,     3,     7,    57,    58,     3,     4,     6,     3,     3,
       4,     3,    39,    40,    10,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,    43,     3,     4,    43,    43,
      42,     4,    22,    58,    37,    42,    41,    42,    18,    42,
      81,     3,     4,     6,    68,    40,    40,    68,    68,    38,
      44,    37,     3,     4,     6,    10,    18,    41,    44,     3,
       4,     3,     4,    44,    44,     7,    63,    64,    42,    41,
       3,     4,     4,     6,     3,     4,     6,    39,    40,     3,
      18,    41,    42,    41,    43,    64,    42,     4,     6,     3,
       3,     4,     6,    12,    82,    83,    41,    42,    42,    10,
      41,     4,    44,    83,    37,     3,     3,     4,     3,    37,
      42,    42,    10,     3,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    53,    53,    53,    54,    54,    55,    55,    55,
      56,    57,    57,    57,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    67,    68,
      68,    68,    69,    69,    70,    70,    71,    70,    72,    70,
      73,    70,    74,    70,    75,    70,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
      83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     2,     3,     0,     3,     2,
       3,     5,     0,     1,     3,     2,     5,     0,     1,     3,
       2,     0,     2,     3,     8,     0,     2,     3,     2,     5,
       0,     2,     3,     2,     5,     4,     5,    10,     7,     0,
       1,     3,     2,     5,     0,     1,     3,     2,     3,     0,
       2,     3,     1,     2,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     1,     3,     3,     3,
       6,     5,     8,     2,     0,     5,     6,     6,     9,     8,
      11,     2,     5,     5,     7,    10,     8,     8,    10,    13,
       7,     7,     7,     5,     5,     5,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     1,     3,
       1,     1,     1,     0,     2,     3,     3,     3,     6,     6,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 117 "limbaj.y"
                                           {printf("\nSuccesfully compiled!\n"); createSymbolTable();}
#line 1676 "y.tab.c"
    break;

  case 11:
#line 136 "limbaj.y"
                                          {
     if(checkFunction(function, nr_functions, (yyvsp[-3].id)))
     {
          char err[MAX_MSG];
          sprintf(err,"The function '%s' was already declared !", (yyvsp[-3].id));
          MyError(err);
     }
     function[nr_functions].type = (yyvsp[-4].id);
     function[nr_functions].name = (yyvsp[-3].id);
     nr_functions++;
}
#line 1692 "y.tab.c"
    break;

  case 15:
#line 154 "limbaj.y"
                    { 
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err,"Duplicate usage of parameter '%s'!", (yyvsp[0].id));
          MyError(err);
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = (yyvsp[-1].id);
     function[nr_functions].params[function[nr_functions].nr_params].key = (yyvsp[0].id);
     function[nr_functions].nr_params++;
}
#line 1708 "y.tab.c"
    break;

  case 16:
#line 165 "limbaj.y"
                              {
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, (yyvsp[-3].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of parameter '%s'!", (yyvsp[-3].id));
          MyError(err);
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = (yyvsp[-4].id);
     function[nr_functions].params[function[nr_functions].nr_params].key = (yyvsp[-3].id);
     function[nr_functions].nr_params++;
}
#line 1724 "y.tab.c"
    break;

  case 24:
#line 192 "limbaj.y"
                                                                 {
         if(checkMethod(group[nr_groups].methods, group[nr_groups].nr_methods, (yyvsp[-6].id)))
         {
               char err[MAX_MSG];
               sprintf(err, "Method '%s' already defined!", (yyvsp[-6].id));
               MyError(err);
         }
         group[nr_groups].methods[group[nr_groups].nr_methods].name = (yyvsp[-6].id);
         group[nr_groups].methods[group[nr_groups].nr_methods].type = (yyvsp[-7].id);
         group[nr_groups].nr_methods++;
         }
#line 1740 "y.tab.c"
    break;

  case 28:
#line 210 "limbaj.y"
               {
          if(checkVar(group[nr_groups].vars[0], group[nr_groups].nr_vars, (yyvsp[0].id)))
          {
               char err[MAX_MSG];
               sprintf(err, "Duplicate usage of the field variable '%s'", (yyvsp[0].id));
               MyError(err);
          }
          for(int i = 0; i < MAX_OBJECTS; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = (yyvsp[-1].id);
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = (yyvsp[0].id);
          }
          group[nr_groups].nr_vars++; 
          }
#line 1758 "y.tab.c"
    break;

  case 29:
#line 223 "limbaj.y"
                        {
          if(getInt((yyvsp[-1].val)) > MAX_EL_ARRAY){
               char err[MAX_MSG];
               sprintf(err, "Sorry! We can't hold more than %d elements in an array ! Go try writing in RUST! \n", MAX_EL_ARRAY);
               MyError(err); 
          }

          for(int i = 0; i < MAX_OBJECTS; i++)
          {
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].type = (yyvsp[-4].id);
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].key = (yyvsp[-3].id);
               group[nr_groups].arrays[i][group[nr_groups].nr_arrays].size = getInt((yyvsp[-1].val));
               for(int j = 0 ; j < getInt((yyvsp[-1].val)); j++)
               {
                    group[nr_groups].arrays[i][group[nr_groups].nr_arrays].value[j] = "0";
               }
          }
          group[nr_groups].nr_arrays++;
          }
#line 1782 "y.tab.c"
    break;

  case 33:
#line 248 "limbaj.y"
                    {
               if(checkVar(variable, nr_vars, (yyvsp[0].id)))
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' already declared!", (yyvsp[0].id));
                    MyError(err);
               }
               variable[nr_vars].type = (yyvsp[-1].id);
               variable[nr_vars].key = (yyvsp[0].id);
               nr_vars++;     
          }
#line 1798 "y.tab.c"
    break;

  case 36:
#line 261 "limbaj.y"
                            {
               if(checkArr(array, nr_arrays, (yyvsp[-3].id))){
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' already declared!", (yyvsp[-3].id));
                    MyError(err);
               }
               int val = getInt((yyvsp[-1].val));
               if(val > MAX_EL_ARRAY)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Sorry! We can't hold more than %d elements in an array ! Go try writing in RUST!", MAX_EL_ARRAY);
                    MyError(err);
               }

               array[nr_arrays].key = (yyvsp[-3].id);
               array[nr_arrays].size = val;
               array[nr_arrays].type = (yyvsp[-4].id);
               for(int i = 0; i < val; i++)
                    array[nr_arrays].value[i] = "0";
               nr_arrays++;
           }
#line 1824 "y.tab.c"
    break;

  case 37:
#line 282 "limbaj.y"
                                                                                          {
               if(checkGroup(group, nr_groups, (yyvsp[-8].id))){
                    char err[MAX_MSG];
                    sprintf(err, "Group '%s' already declared previously!", (yyvsp[-8].id));
                    MyError(err);
               }
               group[nr_groups].name = (yyvsp[-8].id);
               nr_groups++;
           }
#line 1838 "y.tab.c"
    break;

  case 38:
#line 291 "limbaj.y"
                                                       {
               bool found_class = 0;
               bool found_method = 0;
               for(int i=0; i<nr_groups; i++)
               {
                    if(strcmp((yyvsp[-5].id), group[i].name) == 0)
                    {
                         found_class = 1;
                         for(int j=0; j<group[nr_groups].nr_methods; j++)
                         {
                              if(strcmp((yyvsp[-3].id), group[i].methods[j].name) == 0)
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
#line 1865 "y.tab.c"
    break;

  case 42:
#line 320 "limbaj.y"
                      {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of the parameter '%s'", (yyvsp[0].id));
          MyError(err);
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-1].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[0].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
#line 1881 "y.tab.c"
    break;

  case 43:
#line 331 "limbaj.y"
                                {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, (yyvsp[-3].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Duplicate usage of the parameter '%s'", (yyvsp[-3].id));
          MyError(err);
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-4].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[-3].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
#line 1897 "y.tab.c"
    break;

  case 47:
#line 349 "limbaj.y"
                            {
     
}
#line 1905 "y.tab.c"
    break;

  case 54:
#line 371 "limbaj.y"
                {strcat(expression[nr_expr].expr, (yyvsp[0].val));}
#line 1911 "y.tab.c"
    break;

  case 55:
#line 372 "limbaj.y"
                {checkExprType((yyvsp[0].id)); strcat(expression[nr_expr].expr, (yyvsp[0].id));}
#line 1917 "y.tab.c"
    break;

  case 56:
#line 373 "limbaj.y"
                             {strcat(expression[nr_expr].expr, "+");}
#line 1923 "y.tab.c"
    break;

  case 58:
#line 374 "limbaj.y"
                              {strcat(expression[nr_expr].expr, "-");}
#line 1929 "y.tab.c"
    break;

  case 60:
#line 375 "limbaj.y"
                              {strcat(expression[nr_expr].expr, "*");}
#line 1935 "y.tab.c"
    break;

  case 62:
#line 376 "limbaj.y"
                               {strcat(expression[nr_expr].expr, "/");}
#line 1941 "y.tab.c"
    break;

  case 64:
#line 377 "limbaj.y"
                    {strcat(expression[nr_expr].expr, "((");}
#line 1947 "y.tab.c"
    break;

  case 65:
#line 377 "limbaj.y"
                                                                                {strcat(expression[nr_expr].expr, "))");}
#line 1953 "y.tab.c"
    break;

  case 67:
#line 381 "limbaj.y"
                                   {
               if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
               {
                    char err[MAX_MSG];
                    sprintf(err,"Variable '%s' not declared previously!", (yyvsp[-2].id));
                    MyError(err);
               }
               expression[nr_expr].type = expr_current_type;
               expr_current_type = NULL;
               nr_expr++;
          }
#line 1969 "y.tab.c"
    break;

  case 68:
#line 392 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               int id2 = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf("Variable '%s' not declared previously", (yyvsp[-2].id));
                    MyError(err);
               }
               else if(id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[0].id));
                    MyError(err);
               }
               else if(variable[id2].value == NULL)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' does't have a stored value!", (yyvsp[0].id));
                    MyError(err);
               }
               else
                    variable[id].value = variable[id2].value;
          }
#line 1998 "y.tab.c"
    break;

  case 69:
#line 416 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[-2].id));
                    MyError(err);
               }
               else
                    variable[id].value = (yyvsp[0].val);
                        
          }
#line 2015 "y.tab.c"
    break;

  case 70:
#line 428 "limbaj.y"
                                {
               int id = getVarId(variable, nr_vars, (yyvsp[-5].id));
               int vid = getVecId(array, nr_arrays, (yyvsp[-3].id));
               int index = getInt((yyvsp[-1].val));
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[-5].id));
                    MyError(err);
               }
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-3].id));
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               variable[id].value = array[vid].value[index];
         }
#line 2044 "y.tab.c"
    break;

  case 71:
#line 452 "limbaj.y"
                                       {
               int group_id = getObjGroupId((yyvsp[-2].id));
               int obj_id = getObjId((yyvsp[-2].id), group_id);
               int var_id = getObjVarId((yyvsp[0].id), group_id, obj_id);
               int id = getVarId(variable, nr_vars, (yyvsp[-4].id));
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' does not exist!", (yyvsp[-2].id), (yyvsp[0].id));
                    MyError(err);
               }
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[-4].id));
                    MyError(err);
               }
               else
                    variable[id].value = group[group_id].vars[obj_id][var_id].value;
         }
#line 2069 "y.tab.c"
    break;

  case 72:
#line 472 "limbaj.y"
                                                {
               int group_id = getObjGroupId((yyvsp[-5].id));
               int obj_id = getObjId((yyvsp[-5].id), group_id);
               int arr_id = getObjVecId((yyvsp[-3].id), group_id, obj_id);
               int index = getInt((yyvsp[-1].val));
               int id = getVarId(variable, nr_vars, (yyvsp[-7].id));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' does not exist!", (yyvsp[-5].id), (yyvsp[-3].id));
                    MyError(err);
               }
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[-7].id));
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               else
                    variable[id].value = group[group_id].arrays[obj_id][arr_id].value[index];
         }
#line 2102 "y.tab.c"
    break;

  case 74:
#line 501 "limbaj.y"
              { fnctId = getFunctionId(function, nr_functions, (yyvsp[0].id)); }
#line 2108 "y.tab.c"
    break;

  case 75:
#line 501 "limbaj.y"
                                                                                         {
               if(checkFunction(function, nr_functions, (yyvsp[-4].id)) == 0)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Called function '%s' has not been defined!", (yyvsp[-4].id));
                    MyError(err);
               }
               function[fnctId].param_no = 0;
         }
#line 2122 "y.tab.c"
    break;

  case 76:
#line 510 "limbaj.y"
                                 {
               int vid = getVecId(array, nr_arrays, (yyvsp[-5].id));
               int index = getInt((yyvsp[-3].val));
               if(vid == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-5].id));
                    MyError(err);
               }
               if(index < 0 || index >= array[vid].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               array[vid].value[index] = (yyvsp[0].val);
         }
#line 2144 "y.tab.c"
    break;

  case 77:
#line 527 "limbaj.y"
                                 {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-5].id));
               int var_id = getVarId(variable, nr_vars, (yyvsp[0].id));
               int index = getInt((yyvsp[-3].val));

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-5].id));
                    MyError(err);
               }
               if(var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[0].id));
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               
               array[arr_id].value[index] = variable[var_id].value;
         }
#line 2175 "y.tab.c"
    break;

  case 78:
#line 553 "limbaj.y"
                                         {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-8].id));
               int index = getInt((yyvsp[-6].val));
               int arr_id2 = getVecId(array, nr_arrays, (yyvsp[-3].id));
               int index2 = getInt((yyvsp[-1].val));

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-8].id));
                    MyError(err);
               }
               if(arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-3].id));
                    MyError(err);
               }
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index, (yyvsp[-8].id));
                    MyError(err);
               }
               if(index2 < 0 || index2 >= array[arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index2, (yyvsp[-3].id));
                    MyError(err);
               }
               
               array[arr_id].value[index] = array[arr_id2].value[index2];
         }
#line 2213 "y.tab.c"
    break;

  case 79:
#line 586 "limbaj.y"
                                                {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-7].id));
               int index = getInt((yyvsp[-5].val));

               int group_id = getObjGroupId((yyvsp[-2].id));
               int obj_id = getObjId((yyvsp[-2].id), group_id);
               int var_id = getObjVarId((yyvsp[0].id), group_id, obj_id);

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-7].id));
                    MyError(err);
               }
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-2].id), (yyvsp[0].id));
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               
               array[arr_id].value[index] = group[group_id].vars[obj_id][var_id].value;
         }
#line 2247 "y.tab.c"
    break;

  case 80:
#line 615 "limbaj.y"
                                                         {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-10].id));
               int index = getInt((yyvsp[-8].val));

               int group_id = getObjGroupId((yyvsp[-5].id));
               int obj_id = getObjId((yyvsp[-5].id), group_id);
               int arr_id2 = getObjVecId((yyvsp[-3].id), group_id, obj_id);
               int index2 = getInt((yyvsp[-1].val));

               if(arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s' not declared previously!", (yyvsp[-10].id));
                    MyError(err);
               }
               if(group_id == -1 || obj_id == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-5].id), (yyvsp[-3].id));
                    MyError(err);
               }     
               if(index < 0 || index >= array[arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index, (yyvsp[-10].id));
                    MyError(err);
               }
               if(index2 < 0 || index2 >= array[arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s' array!", index2, (yyvsp[-3].id));
                    MyError(err);
               }
               
               array[arr_id].value[index] = group[group_id].arrays[obj_id][arr_id2].value[index2];
         }
#line 2288 "y.tab.c"
    break;

  case 81:
#line 651 "limbaj.y"
                  {
               int group_id = getGroupId((yyvsp[-1].id));
               if(group_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Group '%s' not defined previously!", (yyvsp[-1].id));
                    MyError(err);
               }
               else{
                    group[group_id].object[group[group_id].nr_objects].key = (yyvsp[0].id);
                    group[group_id].object[group[group_id].nr_objects].type = (yyvsp[-1].id);
                    group[group_id].nr_objects++;
               }
         }
#line 2307 "y.tab.c"
    break;

  case 82:
#line 665 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               int assign_id = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-4].id), (yyvsp[-2].id));
                    MyError(err);
               } 
               if(assign_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[0].id));
                    MyError(err);
               } 
               else
                    group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
#line 2332 "y.tab.c"
    break;

  case 83:
#line 685 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-4].id), (yyvsp[-2].id));
                    MyError(err);
               } 
               else
                    group[group_id].vars[obj_id][var_id].value = (yyvsp[0].val);
         }
#line 2350 "y.tab.c"
    break;

  case 84:
#line 698 "limbaj.y"
                                                        {
               int group_id = getObjGroupId((yyvsp[-6].id));
               int obj_id = getObjId((yyvsp[-6].id), group_id);
               int var_id = getObjVarId((yyvsp[-4].id), group_id, obj_id);
               
               int group_id2 = getObjGroupId((yyvsp[-2].id));
               int obj_id2 = getObjId((yyvsp[-2].id), group_id2);
               int var_id2 = getObjVarId((yyvsp[0].id), group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || var_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-6].id), (yyvsp[-4].id));
                    MyError(err);
               } 
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-2].id), (yyvsp[0].id));
                    MyError(err);
               } 
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2379 "y.tab.c"
    break;

  case 85:
#line 722 "limbaj.y"
                                                                 {
               int group_id = getObjGroupId((yyvsp[-9].id));
               int obj_id = getObjId((yyvsp[-9].id), group_id);
               int var_id = getObjVarId((yyvsp[-7].id), group_id, obj_id);

               int group_id2 = getObjGroupId((yyvsp[-5].id));
               int obj_id2 = getObjId((yyvsp[-5].id), group_id2);
               int arr_id2 = getObjVecId((yyvsp[-3].id), group_id2, obj_id2);
               int index = getInt((yyvsp[-1].val));

               if(group_id2 == -1 || obj_id2 == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-5].id), (yyvsp[-3].id));
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
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-9].id), (yyvsp[-7].id));
                    MyError(err);
               } 
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].arrays[obj_id2][arr_id2].value[index];
         }
#line 2415 "y.tab.c"
    break;

  case 86:
#line 753 "limbaj.y"
                                                {
               int group_id = getObjGroupId((yyvsp[-7].id));
               int obj_id = getObjId((yyvsp[-7].id), group_id);
               int arr_id = getObjVecId((yyvsp[-5].id), group_id, obj_id);
               int index = getInt((yyvsp[-3].val));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-7].id), (yyvsp[-5].id));
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = (yyvsp[0].val);
         }
#line 2441 "y.tab.c"
    break;

  case 87:
#line 774 "limbaj.y"
                                                {
               int group_id = getObjGroupId((yyvsp[-7].id));
               int obj_id = getObjId((yyvsp[-7].id), group_id);
               int arr_id = getObjVecId((yyvsp[-5].id), group_id, obj_id);
               int index = getInt((yyvsp[-3].val));
               int assign_id = getVarId(variable, nr_vars, (yyvsp[0].id));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-7].id), (yyvsp[-5].id));
                    MyError(err);
               }
               if(assign_id == -1)
               {    
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[0].id));
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d]!", index);
                    MyError(err);
               }
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = variable[assign_id].value;
         }
#line 2474 "y.tab.c"
    break;

  case 88:
#line 802 "limbaj.y"
                                                                 {
               int group_id = getObjGroupId((yyvsp[-9].id));
               int obj_id = getObjId((yyvsp[-9].id), group_id);
               int arr_id = getObjVecId((yyvsp[-7].id), group_id, obj_id);
               int index = getInt((yyvsp[-5].val));

               int group_id2 = getObjGroupId((yyvsp[-2].id));
               int obj_id2 = getObjId((yyvsp[-2].id), group_id2);
               int var_id2 = getObjVarId((yyvsp[0].id), group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-9].id), (yyvsp[-7].id));
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
                    sprintf(err, "Variable '%s.%s' not declared previously!", (yyvsp[-2].id), (yyvsp[0].id));
                    MyError(err);
               } 
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2510 "y.tab.c"
    break;

  case 89:
#line 833 "limbaj.y"
                                                                          {
               int group_id = getObjGroupId((yyvsp[-12].id));
               int obj_id = getObjId((yyvsp[-12].id), group_id);
               int arr_id = getObjVecId((yyvsp[-10].id), group_id, obj_id);
               int index = getInt((yyvsp[-8].val));

               int group_id2 = getObjGroupId((yyvsp[-5].id));
               int obj_id2 = getObjId((yyvsp[-5].id), group_id2);
               int arr_id2 = getObjVecId((yyvsp[-3].id), group_id2, obj_id2);
               int index2 = getInt((yyvsp[-1].val));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-12].id), (yyvsp[-10].id));
                    MyError(err);
               }
               if(group_id2 == -1 || obj_id2 == -1 || arr_id2 == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Array '%s.%s' not declared previously!", (yyvsp[-5].id), (yyvsp[-3].id));
                    MyError(err);
               }
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s.%s' array!", index, (yyvsp[-12].id), (yyvsp[-10].id));
                    MyError(err);
               }
               if(index2 < 0 || index2 > group[group_id].arrays[obj_id][arr_id2].size)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Incorrect access for index [%d] at the '%s.%s' array!", index2, (yyvsp[-5].id), (yyvsp[-3].id));
                    MyError(err);
               }
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].arrays[obj_id2][arr_id2].value[index2];
         }
#line 2553 "y.tab.c"
    break;

  case 93:
#line 876 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-4].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2578 "y.tab.c"
    break;

  case 95:
#line 897 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-4].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2597 "y.tab.c"
    break;

  case 96:
#line 911 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-4].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2616 "y.tab.c"
    break;

  case 97:
#line 927 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2635 "y.tab.c"
    break;

  case 98:
#line 941 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2648 "y.tab.c"
    break;

  case 99:
#line 949 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2661 "y.tab.c"
    break;

  case 101:
#line 958 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2680 "y.tab.c"
    break;

  case 102:
#line 972 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2693 "y.tab.c"
    break;

  case 103:
#line 980 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2706 "y.tab.c"
    break;

  case 105:
#line 989 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2725 "y.tab.c"
    break;

  case 106:
#line 1003 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2738 "y.tab.c"
    break;

  case 107:
#line 1011 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2751 "y.tab.c"
    break;

  case 109:
#line 1020 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2770 "y.tab.c"
    break;

  case 110:
#line 1034 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2783 "y.tab.c"
    break;

  case 111:
#line 1042 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2796 "y.tab.c"
    break;

  case 113:
#line 1051 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2815 "y.tab.c"
    break;

  case 114:
#line 1065 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2828 "y.tab.c"
    break;

  case 115:
#line 1073 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2841 "y.tab.c"
    break;

  case 120:
#line 1088 "limbaj.y"
          {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].val));
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if (strcmp(def_type, "char") == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].val));
               MyError(err);
          }
          else if (strcmp(def_type, "bool") == 0)
          {
               int nr_int = getInt((yyvsp[0].val));
               if (nr_int != 0 && nr_int != 1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].val));
                    MyError(err);
               }
          }
          function[fnctId].param_no++;
     }
#line 2872 "y.tab.c"
    break;

  case 121:
#line 1114 "limbaj.y"
          {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if(checkVar(variable, nr_vars, (yyvsp[0].id)) == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          int current_var_id = getVarId(variable, nr_vars, (yyvsp[0].id));
          char *current_type = getVarType(variable, nr_vars, current_var_id);
          if (strcmp(def_type, current_type) != 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          function[fnctId].param_no++;
     }
#line 2901 "y.tab.c"
    break;

  case 122:
#line 1138 "limbaj.y"
           {
          if(!isArray(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no))
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, function[fnctId].param_no);
          if(checkArr(array, nr_arrays, (yyvsp[0].id)) == 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          int current_arr_id = getVecId(array, nr_arrays, (yyvsp[0].id));
          char *current_type = getArrType(array, nr_arrays, current_arr_id);
          if (strcmp(def_type, current_type) != 0)
          {
               char err[MAX_MSG];
               sprintf(err, "The type of variable '%s' in the function call does not match the definition!", (yyvsp[0].id));
               MyError(err);
          }
          function[fnctId].param_no++;
     }
#line 2930 "y.tab.c"
    break;

  case 127:
#line 1270 "limbaj.y"
                               {}
#line 2936 "y.tab.c"
    break;

  case 128:
#line 1271 "limbaj.y"
                                        {}
#line 2942 "y.tab.c"
    break;

  case 129:
#line 1272 "limbaj.y"
                                        {}
#line 2948 "y.tab.c"
    break;


#line 2952 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1277 "limbaj.y"

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
     if(expr_current_type == NULL)
          expr_current_type = variable[id].type;
     else if(strcmp(variable[id].type, expr_current_type) != 0){
          char errMsg[100];
          sprintf(errMsg,"Variable '%s' has type '%s' but expected '%s'\n", var_name, variable[id].type, expr_current_type);
          MyError(errMsg);
     }
}

void addExpression(){

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

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}
