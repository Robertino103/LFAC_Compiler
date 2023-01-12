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

int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;
int nr_functions = 0;
int nr_expr = 0;
int param_no = 0;
int fnctId = -1;
int fnctId2 = -1;
char *expr_current_type;


#line 169 "y.tab.c"

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
    CTIP = 263,
    BOOLVAL = 264,
    BGIN = 265,
    END = 266,
    ASSIGN = 267,
    ASSIGNEXP = 268,
    PRINT = 269,
    BGINGLOBAL = 270,
    ENDGLOBAL = 271,
    BGINFNCT = 272,
    ENDFNCT = 273,
    GROUP = 274,
    GROUP_ACCESS = 275,
    BGINFIELDS = 276,
    ENDFIELDS = 277,
    BGINMETHODS = 278,
    ENDMETHODS = 279,
    IF = 280,
    FOR = 281,
    WHILE = 282,
    CHECK = 283,
    LE = 284,
    GE = 285,
    LT = 286,
    GT = 287,
    PLUS = 288,
    MINUS = 289,
    TIMES = 290,
    DIVIDE = 291,
    LPAREN = 292,
    RPAREN = 293,
    OR = 294,
    AND = 295
  };
#endif
/* Tokens.  */
#define NR 258
#define ID 259
#define GID 260
#define VID 261
#define TIP 262
#define CTIP 263
#define BOOLVAL 264
#define BGIN 265
#define END 266
#define ASSIGN 267
#define ASSIGNEXP 268
#define PRINT 269
#define BGINGLOBAL 270
#define ENDGLOBAL 271
#define BGINFNCT 272
#define ENDFNCT 273
#define GROUP 274
#define GROUP_ACCESS 275
#define BGINFIELDS 276
#define ENDFIELDS 277
#define BGINMETHODS 278
#define ENDMETHODS 279
#define IF 280
#define FOR 281
#define WHILE 282
#define CHECK 283
#define LE 284
#define GE 285
#define LT 286
#define GT 287
#define PLUS 288
#define MINUS 289
#define TIMES 290
#define DIVIDE 291
#define LPAREN 292
#define RPAREN 293
#define OR 294
#define AND 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "limbaj.y"

     char* id;
     char* val;

#line 306 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      42,    43,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   127,   128,   131,   132,   135,   136,   139,
     140,   143,   156,   157,   158,   161,   172,   185,   186,   187,
     190,   193,   194,   195,   199,   212,   213,   214,   217,   230,
     251,   252,   253,   255,   266,   271,   277,   282,   283,   284,
     305,   314,   338,   339,   340,   343,   354,   367,   368,   369,
     372,   378,   382,   383,   384,   389,   390,   393,   394,   397,
     398,   401,   402,   412,   412,   413,   413,   414,   414,   417,
     418,   419,   419,   420,   420,   421,   421,   422,   422,   423,
     423,   426,   435,   446,   471,   488,   513,   533,   561,   562,
     562,   571,   593,   619,   652,   681,   717,   731,   751,   768,
     792,   823,   848,   876,   907,   945,   946,   947,   950,   970,
     971,   985,  1001,  1015,  1023,  1031,  1032,  1046,  1054,  1062,
    1063,  1077,  1085,  1093,  1094,  1108,  1116,  1124,  1125,  1139,
    1147,  1155,  1158,  1159,  1160,  1162,  1188,  1212,  1338,  1339,
    1340,  1343,  1344,  1345,  1346,  1347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NR", "ID", "GID", "VID", "TIP", "CTIP",
  "BOOLVAL", "BGIN", "END", "ASSIGN", "ASSIGNEXP", "PRINT", "BGINGLOBAL",
  "ENDGLOBAL", "BGINFNCT", "ENDFNCT", "GROUP", "GROUP_ACCESS",
  "BGINFIELDS", "ENDFIELDS", "BGINMETHODS", "ENDMETHODS", "IF", "FOR",
  "WHILE", "CHECK", "LE", "GE", "LT", "GT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "LPAREN", "RPAREN", "OR", "AND", "';'", "'('", "')'", "','",
  "'['", "']'", "'{'", "'}'", "':'", "$accept", "progr", "global",
  "global_defs", "function_def", "functions", "function",
  "fnct_list_param", "fnct_param", "lista_param", "param", "methods",
  "method", "fields", "field", "declaratii", "declaratie",
  "method_list_param", "method_param", "method_check_list_param",
  "method_check_param", "bloc", "list", "expressions", "booleanexp",
  "arithmexp", "boolean", "$@1", "$@2", "$@3", "arithmetic", "$@4", "$@5",
  "$@6", "$@7", "$@8", "statement", "$@9", "for_statement",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,    40,    41,    44,    91,    93,   123,   125,    58
};
# endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    49,    18,     5,   111,    46,    40,    45,    49,    26,
    -118,    73,    49,    -7,    43,    84,    53,  -118,    71,   128,
     158,    36,    96,    83,   135,   176,     9,   215,   217,   218,
     201,   207,   183,  -118,   185,  -118,    81,   187,  -118,  -118,
    -118,   220,  -118,   121,  -118,   189,   181,  -118,   222,   223,
    -118,    98,   228,   191,   229,   193,   195,   197,    78,   199,
    -118,  -118,  -118,   227,   231,  -118,   120,    12,   202,   145,
     123,  -118,   110,    11,   146,   203,  -118,   238,  -118,   165,
     240,   165,  -118,   205,  -118,  -118,   243,   127,  -118,  -118,
     209,   219,   211,  -118,  -118,   212,  -118,   223,  -118,   230,
     213,  -118,  -118,    37,  -118,   245,  -118,    32,    29,   133,
     105,   237,   216,    59,   221,    99,   104,   225,   239,   226,
     232,  -118,  -118,  -118,   231,   250,   248,  -118,   253,  -118,
     149,   256,    32,    29,  -118,  -118,   133,  -118,  -118,   105,
    -118,  -118,  -118,  -118,  -118,  -118,   171,   257,  -118,  -118,
    -118,   134,  -118,   251,   178,   182,   184,   186,   188,   190,
     192,   194,   196,   198,   224,   200,   233,   234,  -118,   236,
     258,    20,   235,   241,  -118,   244,   242,   108,    87,    32,
      32,    29,    29,    29,    29,  -118,   246,   247,  -118,    59,
     139,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,    81,   252,   254,    81,    81,  -118,   249,   255,   259,
    -118,  -118,   261,  -118,  -118,  -118,   133,   133,   170,   170,
    -118,  -118,   150,   260,  -118,  -118,   263,   262,    -2,   204,
     206,     3,    33,   266,  -118,  -118,   264,  -118,   267,   208,
     153,   271,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   154,
     172,  -118,  -118,   274,  -118,   265,  -118,   268,   269,  -118,
     272,   273,   266,   270,   157,   275,  -118,   276,    95,  -118,
    -118,  -118,   277,   278,   279,   280,   281,   282,     7,   286,
     287,  -118,  -118,   210,   291,  -118,  -118,   288,  -118,   284,
    -118,  -118,   285,  -118,  -118,   283,   214,  -118,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       1,     0,    30,    33,     0,    36,     0,     4,     0,    31,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    32,     0,     8,     0,     9,    52,     0,     2,    31,
      34,     0,    38,     0,    18,     0,     0,    35,    25,    12,
      10,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    20,    37,     0,    47,    39,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,    96,     0,    88,     0,
       0,     0,    51,     0,    53,    19,     0,     0,    48,    28,
       0,     0,     0,    26,    15,     0,    11,     0,    84,    83,
       0,    81,    69,    62,    61,    67,    82,    56,    55,    57,
      59,     0,     0,   132,     0,     0,     0,     0,     0,     0,
       0,    54,    50,    41,     0,     0,    21,    27,     0,    14,
       0,     0,     0,     0,    62,    67,    58,    70,    79,    60,
      63,    65,    71,    73,    75,    77,     0,     0,   135,   136,
     137,     0,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    97,     0,    90,     0,
       0,   115,   114,   123,   122,   131,   130,   119,   118,   127,
     126,   113,   112,   121,   120,   129,   128,   117,   116,   125,
     124,    52,     0,     0,    52,    52,    29,     0,     0,     0,
      22,    16,     0,    85,    68,    80,    64,    66,    72,    74,
      76,    78,     0,     0,   134,    91,    92,     0,     0,     0,
       0,     0,     0,    42,    40,    23,     0,    99,     0,     0,
       0,     0,   105,   109,   111,   110,   108,   106,   107,     0,
       0,    43,    87,     0,   101,   102,    94,     0,     0,    45,
       0,     0,     0,     0,     0,     0,    93,     0,   138,    44,
     100,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    46,     0,     0,   145,    24,     0,   139,     0,
     142,   141,     0,   140,   104,     0,     0,   144,   143
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,   290,  -118,   168,  -118,
     289,  -118,   113,  -118,   292,   293,    41,  -118,    25,  -118,
     175,  -118,  -117,  -118,  -118,  -118,  -101,  -118,  -118,  -118,
    -107,  -118,  -118,  -118,  -118,  -118,   -58,  -118,  -118,   294,
    -118,   112,  -118,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,    21,    22,    70,    71,    43,
      44,   171,   172,    67,    68,     8,     9,   260,   261,    87,
      88,    38,    58,   106,   107,   108,   109,   179,   180,   132,
     110,   181,   182,   183,   184,   133,    59,    75,   119,   117,
     151,   152,   288,   289
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   139,    51,    52,    53,    25,   136,    51,    52,    53,
       1,   285,    54,   286,   102,   103,    41,    54,    10,    66,
     104,   287,    11,    55,    56,    57,   178,   170,    55,    56,
      57,   177,   102,   137,    91,    26,   134,    51,    52,    53,
     -70,   104,    27,    20,   218,    16,   252,    54,   105,    18,
      15,   257,    42,    24,    33,   296,     4,     5,    55,    56,
      57,    17,   148,   149,    37,   150,   138,    19,     6,   135,
     -70,   -70,   -70,   -70,   228,   229,   230,   231,   226,   227,
      20,   258,    51,    52,    53,    51,    52,    53,    28,    82,
       4,     5,    54,    36,   238,    54,    29,   241,   242,   285,
      30,   286,     6,    55,    56,    57,    55,    56,    57,   287,
      72,    73,    31,    98,    99,    13,   100,    14,    74,   101,
     142,   143,   144,   145,    89,   225,    90,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    35,   142,   143,
     144,   145,   235,   236,    -5,   237,   224,   140,   141,    94,
     111,    95,   112,   174,   247,   175,   248,   266,   269,   267,
     270,   281,    32,   282,    62,    63,    96,    97,   115,   116,
     123,   124,   140,   141,   185,   186,    39,   188,   189,    40,
      83,   191,   192,    83,    83,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   212,   213,   144,   145,   253,   254,   255,
     256,   264,   265,   300,   301,   271,   272,   307,   308,    45,
      46,    47,    48,    -6,    61,    49,    50,    65,    60,    66,
      69,    64,    76,    78,    41,    79,    77,    80,    86,    81,
      84,   114,   126,    93,   118,   113,   121,   122,   -79,   146,
     130,   165,   127,   169,   125,   170,   173,   128,   131,   176,
     187,   147,   217,   190,   246,   129,   232,   153,   164,   166,
     297,   211,   249,   259,   268,   167,   220,   273,   283,   284,
     214,   215,   216,   250,   219,   274,   295,   221,   223,   222,
     299,   243,   293,   233,   302,   306,   239,   279,   240,   168,
     245,   234,     0,   244,     0,    23,     0,   251,     0,     0,
     262,    34,   263,   275,     0,   276,   280,   277,     0,     0,
     278,     0,   290,     0,   291,   292,   294,   298,     0,   303,
     304,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
      58,   108,     4,     5,     6,    12,   107,     4,     5,     6,
      15,     4,    14,     6,     3,     4,     7,    14,     0,     7,
       9,    14,    17,    25,    26,    27,   133,     7,    25,    26,
      27,   132,     3,     4,    22,    42,     4,     4,     5,     6,
       3,     9,    49,     7,    24,     5,    48,    14,    37,     8,
       4,    48,    43,    12,    18,    48,     7,     8,    25,    26,
      27,    16,     3,     4,    23,     6,    37,    41,    19,    37,
      33,    34,    35,    36,   181,   182,   183,   184,   179,   180,
       7,    48,     4,     5,     6,     4,     5,     6,    45,    11,
       7,     8,    14,    10,   211,    14,    12,   214,   215,     4,
      47,     6,    19,    25,    26,    27,    25,    26,    27,    14,
      12,    13,    41,     3,     4,     4,     6,     6,    20,     9,
      33,    34,    35,    36,     4,    38,     6,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    41,    33,    34,
      35,    36,     3,     4,    16,     6,    38,    39,    40,     4,
       4,     6,     6,     4,     4,     6,     6,     4,     4,     6,
       6,     4,     4,     6,    43,    44,    43,    44,     3,     4,
      43,    44,    39,    40,     3,     4,    41,    43,    44,     3,
     238,     3,     4,   241,   242,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,    35,    36,     3,     4,     3,
       4,     3,     4,     3,     4,    43,    44,     3,     4,     4,
       3,     3,    21,    16,     4,    42,    41,    46,    41,     7,
       7,    42,     4,     4,     7,    42,    45,    42,     7,    42,
      41,     3,    23,    41,     4,    42,    41,     4,     3,    12,
      20,    12,    41,     3,    45,     7,     3,    45,    45,     3,
       3,    45,     4,    12,     3,    97,    20,    46,    43,    43,
     288,    47,    12,     7,     3,    43,    41,     3,     3,     3,
      47,    47,    46,    20,   171,    20,     4,    46,    46,    45,
       3,    42,    12,    46,     3,    12,    44,   272,    44,   124,
      41,   189,    -1,    48,    -1,    12,    -1,    45,    -1,    -1,
      46,    21,    45,    45,    -1,    46,    46,    45,    -1,    -1,
      47,    -1,    45,    -1,    46,    46,    45,    41,    -1,    41,
      46,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    51,    52,     7,     8,    19,    53,    65,    66,
       0,    17,    54,     4,     6,     4,     5,    16,    66,    41,
       7,    55,    56,    65,    66,    12,    42,    49,    45,    12,
      47,    41,     4,    18,    56,    41,    10,    66,    71,    41,
       3,     7,    43,    59,    60,     4,     3,     3,    21,    42,
      41,     4,     5,     6,    14,    25,    26,    27,    72,    86,
      41,     4,    43,    44,    42,    46,     7,    63,    64,     7,
      57,    58,    12,    13,    20,    87,     4,    45,     4,    42,
      42,    42,    11,    86,    41,    60,     7,    69,    70,     4,
       6,    22,    64,    41,     4,     6,    43,    44,     3,     4,
       6,     9,     3,     4,     9,    37,    73,    74,    75,    76,
      80,     4,     6,    42,     3,     3,     4,    89,     4,    88,
      89,    41,     4,    43,    44,    45,    23,    41,    45,    58,
      20,    45,    79,    85,     4,    37,    76,     4,    37,    80,
      39,    40,    33,    34,    35,    36,    12,    45,     3,     4,
       6,    90,    91,    46,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    43,    12,    43,    43,    70,     3,
       7,    61,    62,     3,     4,     6,     3,    76,    80,    77,
      78,    81,    82,    83,    84,     3,     4,     3,    43,    44,
      12,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,    47,     3,     4,    47,    47,    46,     4,    24,    62,
      41,    46,    45,    46,    38,    38,    76,    76,    80,    80,
      80,    80,    20,    46,    91,     3,     4,     6,    72,    44,
      44,    72,    72,    42,    48,    41,     3,     4,     6,    12,
      20,    45,    48,     3,     4,     3,     4,    48,    48,     7,
      67,    68,    46,    45,     3,     4,     4,     6,     3,     4,
       6,    43,    44,     3,    20,    45,    46,    45,    47,    68,
      46,     4,     6,     3,     3,     4,     6,    14,    92,    93,
      45,    46,    46,    12,    45,     4,    48,    93,    41,     3,
       3,     4,     3,    41,    46,    46,    12,     3,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    61,    61,    61,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      70,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    76,    78,    76,    79,    76,    80,
      80,    81,    80,    82,    80,    83,    80,    84,    80,    85,
      80,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     2,     3,     0,     3,     2,
       3,     5,     0,     1,     3,     2,     5,     0,     1,     3,
       2,     0,     2,     3,     8,     0,     2,     3,     2,     5,
       0,     2,     3,     2,     4,     4,     2,     5,     4,     5,
      10,     7,     0,     1,     3,     2,     5,     0,     1,     3,
       2,     3,     0,     2,     3,     1,     1,     1,     2,     1,
       2,     1,     1,     0,     4,     0,     4,     0,     4,     1,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     3,     3,     3,     3,     6,     5,     8,     2,     0,
       5,     6,     6,     9,     8,    11,     2,     5,     5,     7,
      10,     8,     8,    10,    13,     7,     7,     7,     5,     5,
       5,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     1,     3,     1,     1,     1,     0,     2,
       3,     3,     3,     6,     6,     2
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
#line 124 "limbaj.y"
                                           {printf("\nSuccesfully compiled!\n\n"); createSymbolTable();}
#line 1704 "y.tab.c"
    break;

  case 11:
#line 143 "limbaj.y"
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
#line 1720 "y.tab.c"
    break;

  case 15:
#line 161 "limbaj.y"
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
#line 1736 "y.tab.c"
    break;

  case 16:
#line 172 "limbaj.y"
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
#line 1752 "y.tab.c"
    break;

  case 24:
#line 199 "limbaj.y"
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
#line 1768 "y.tab.c"
    break;

  case 28:
#line 217 "limbaj.y"
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
#line 1786 "y.tab.c"
    break;

  case 29:
#line 230 "limbaj.y"
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
#line 1810 "y.tab.c"
    break;

  case 33:
#line 255 "limbaj.y"
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
#line 1826 "y.tab.c"
    break;

  case 34:
#line 266 "limbaj.y"
                              {
               char err[MAX_MSG];
               sprintf(err, "You can't assign a value there unless '%s' is of constant type!\n");
               MyError(err);
           }
#line 1836 "y.tab.c"
    break;

  case 35:
#line 271 "limbaj.y"
                               {
               variable[nr_vars].type = (yyvsp[-3].id);
               variable[nr_vars].key = (yyvsp[-2].id);
               variable[nr_vars].value = (yyvsp[0].val);
               nr_vars++;
           }
#line 1847 "y.tab.c"
    break;

  case 36:
#line 277 "limbaj.y"
                    {
               char err[MAX_MSG];
               sprintf(err, "Can't declare a constant without assigning a value to it!\n");
               MyError(err);
           }
#line 1857 "y.tab.c"
    break;

  case 39:
#line 284 "limbaj.y"
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
#line 1883 "y.tab.c"
    break;

  case 40:
#line 305 "limbaj.y"
                                                                                          {
               if(checkGroup(group, nr_groups, (yyvsp[-8].id))){
                    char err[MAX_MSG];
                    sprintf(err, "Group '%s' already declared previously!", (yyvsp[-8].id));
                    MyError(err);
               }
               group[nr_groups].name = (yyvsp[-8].id);
               nr_groups++;
           }
#line 1897 "y.tab.c"
    break;

  case 41:
#line 314 "limbaj.y"
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
#line 1924 "y.tab.c"
    break;

  case 45:
#line 343 "limbaj.y"
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
#line 1940 "y.tab.c"
    break;

  case 46:
#line 354 "limbaj.y"
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
#line 1956 "y.tab.c"
    break;

  case 50:
#line 372 "limbaj.y"
                            {
     
}
#line 1964 "y.tab.c"
    break;

  case 61:
#line 401 "limbaj.y"
                  {strcat(expression[nr_expr].expr, (yyvsp[0].id));}
#line 1970 "y.tab.c"
    break;

  case 62:
#line 402 "limbaj.y"
             { 
               int id = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(strcmp(variable[id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of boolean type!\n", (yyvsp[0].id));
                    MyError(err);
               }
               strcat(expression[nr_expr].expr, (yyvsp[0].id));
               expr_current_type = "bool";
          }
#line 1985 "y.tab.c"
    break;

  case 63:
#line 412 "limbaj.y"
                     {strcat(expression[nr_expr].expr, " && " );}
#line 1991 "y.tab.c"
    break;

  case 65:
#line 413 "limbaj.y"
                      {strcat(expression[nr_expr].expr, " || ");}
#line 1997 "y.tab.c"
    break;

  case 67:
#line 414 "limbaj.y"
                 {strcat(expression[nr_expr].expr, "((");}
#line 2003 "y.tab.c"
    break;

  case 68:
#line 414 "limbaj.y"
                                                                          {strcat(expression[nr_expr].expr, "))");}
#line 2009 "y.tab.c"
    break;

  case 69:
#line 417 "limbaj.y"
                {strcat(expression[nr_expr].expr, (yyvsp[0].val));}
#line 2015 "y.tab.c"
    break;

  case 70:
#line 418 "limbaj.y"
                {checkExprType((yyvsp[0].id)); strcat(expression[nr_expr].expr, (yyvsp[0].id));}
#line 2021 "y.tab.c"
    break;

  case 71:
#line 419 "limbaj.y"
                             {strcat(expression[nr_expr].expr, " + ");}
#line 2027 "y.tab.c"
    break;

  case 73:
#line 420 "limbaj.y"
                              {strcat(expression[nr_expr].expr, " - ");}
#line 2033 "y.tab.c"
    break;

  case 75:
#line 421 "limbaj.y"
                              {strcat(expression[nr_expr].expr, " * ");}
#line 2039 "y.tab.c"
    break;

  case 77:
#line 422 "limbaj.y"
                               {strcat(expression[nr_expr].expr, " / ");}
#line 2045 "y.tab.c"
    break;

  case 79:
#line 423 "limbaj.y"
                    {strcat(expression[nr_expr].expr, "((");}
#line 2051 "y.tab.c"
    break;

  case 80:
#line 423 "limbaj.y"
                                                                                {strcat(expression[nr_expr].expr, "))");}
#line 2057 "y.tab.c"
    break;

  case 81:
#line 426 "limbaj.y"
                             {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(strcmp(variable[id].type, "bool") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' is not of bool type!\n", (yyvsp[-2].id));
                    MyError(err);
               }
               variable[id].value = (yyvsp[0].id);
          }
#line 2071 "y.tab.c"
    break;

  case 82:
#line 435 "limbaj.y"
                                    {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(strcmp(variable[id].type, expr_current_type) != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign '%s' expression because the variable '%s' expects a type of '%s'!\n", expr_current_type, (yyvsp[-2].id), variable[id].type);
                    MyError(err);
               }
               expression[nr_expr].type = expr_current_type;
               expr_current_type = NULL;
               nr_expr++;
         }
#line 2087 "y.tab.c"
    break;

  case 83:
#line 446 "limbaj.y"
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
               
               variable[id].value = variable[id2].value;
               assignCheckTypes(variable, nr_vars, (yyvsp[-2].id), variable, nr_vars, (yyvsp[0].id));
          }
#line 2117 "y.tab.c"
    break;

  case 84:
#line 471 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(id == -1)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Variable '%s' not declared previously!", (yyvsp[-2].id));
                    MyError(err);
               }
               
               variable[id].value = (yyvsp[0].val);
               if(strcmp(variable[id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", (yyvsp[-2].id), variable[id].type);
                    MyError(err);
               }
                        
          }
#line 2139 "y.tab.c"
    break;

  case 85:
#line 488 "limbaj.y"
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
               assignCheckTypesArr(variable, nr_vars, (yyvsp[-5].id), array, nr_arrays, (yyvsp[-3].id));
               variable[id].value = array[vid].value[index];
         }
#line 2169 "y.tab.c"
    break;

  case 86:
#line 513 "limbaj.y"
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
               assignCheckTypes(variable, nr_vars, (yyvsp[-4].id), group[group_id].vars[obj_id], group[group_id].nr_vars, (yyvsp[0].id));
               variable[id].value = group[group_id].vars[obj_id][var_id].value;
         }
#line 2194 "y.tab.c"
    break;

  case 87:
#line 533 "limbaj.y"
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
               assignCheckTypesArr(variable, nr_vars, (yyvsp[-7].id), group[group_id].arrays[obj_id], group[group_id].nr_arrays, (yyvsp[-3].id));
               variable[id].value = group[group_id].arrays[obj_id][arr_id].value[index];
         }
#line 2227 "y.tab.c"
    break;

  case 89:
#line 562 "limbaj.y"
              { fnctId = getFunctionId(function, nr_functions, (yyvsp[0].id)); }
#line 2233 "y.tab.c"
    break;

  case 90:
#line 562 "limbaj.y"
                                                                                         {
               if(checkFunction(function, nr_functions, (yyvsp[-4].id)) == 0)
               {
                    char err[MAX_MSG];
                    sprintf(err, "Called function '%s' has not been defined!", (yyvsp[-4].id));
                    MyError(err);
               }
               function[fnctId].param_no = 0;
         }
#line 2247 "y.tab.c"
    break;

  case 91:
#line 571 "limbaj.y"
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
               if(strcmp(array[vid].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s[%d]' because it expects a value of type '%s'!\n", (yyvsp[-5].id), index, array[vid].type);
                    MyError(err);
               }
               array[vid].value[index] = (yyvsp[0].val);
         }
#line 2274 "y.tab.c"
    break;

  case 92:
#line 593 "limbaj.y"
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
               assignCheckTypesArr(variable, nr_vars, (yyvsp[0].id), array, nr_arrays, (yyvsp[-5].id));
               array[arr_id].value[index] = variable[var_id].value;
         }
#line 2305 "y.tab.c"
    break;

  case 93:
#line 619 "limbaj.y"
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
               assignCheckTypesArrArr(array, nr_arrays, (yyvsp[-8].id), array, nr_arrays, (yyvsp[-3].id));
               array[arr_id].value[index] = array[arr_id2].value[index2];
         }
#line 2343 "y.tab.c"
    break;

  case 94:
#line 652 "limbaj.y"
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
               assignCheckTypesArr(group[group_id].vars[obj_id], group[group_id].nr_vars, (yyvsp[0].id), array, nr_arrays, (yyvsp[-7].id));
               array[arr_id].value[index] = group[group_id].vars[obj_id][var_id].value;
         }
#line 2377 "y.tab.c"
    break;

  case 95:
#line 681 "limbaj.y"
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
               assignCheckTypesArrArr(group[group_id].arrays[obj_id], group[group_id].nr_arrays, (yyvsp[-3].id), array, nr_arrays, (yyvsp[-10].id));
               array[arr_id].value[index] = group[group_id].arrays[obj_id][arr_id2].value[index2];
         }
#line 2418 "y.tab.c"
    break;

  case 96:
#line 717 "limbaj.y"
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
#line 2437 "y.tab.c"
    break;

  case 97:
#line 731 "limbaj.y"
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
               assignCheckTypes(variable, nr_vars, (yyvsp[0].id), group[group_id].vars[obj_id], group[group_id].nr_vars, (yyvsp[-2].id));
               group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
#line 2462 "y.tab.c"
    break;

  case 98:
#line 751 "limbaj.y"
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
               if(strcmp(group[group_id].vars[obj_id][var_id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", (yyvsp[-2].id), group[group_id].vars[obj_id][var_id].type);
                    MyError(err);
               }
               group[group_id].vars[obj_id][var_id].value = (yyvsp[0].val);
         }
#line 2484 "y.tab.c"
    break;

  case 99:
#line 768 "limbaj.y"
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
               assignCheckTypes(group[group_id].vars[obj_id], group[group_id].nr_vars, (yyvsp[-4].id), group[group_id2].vars[obj_id2], group[group_id2].nr_vars, (yyvsp[0].id));
               group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2513 "y.tab.c"
    break;

  case 100:
#line 792 "limbaj.y"
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
               //TODO
               group[group_id].vars[obj_id][var_id].value = group[group_id2].arrays[obj_id2][arr_id2].value[index];
         }
#line 2549 "y.tab.c"
    break;

  case 101:
#line 823 "limbaj.y"
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
               if(strcmp(group[group_id].arrays[obj_id][arr_id].type, "int") != 0){
                    char err[MAX_MSG];
                    sprintf(err, "Cannot assign an integer value to '%s' because it expects a value of type '%s'!\n", (yyvsp[-5].id), group[group_id].arrays[obj_id][arr_id].type);
                    MyError(err);
               }
               group[group_id].arrays[obj_id][arr_id].value[index] = (yyvsp[0].val);
         }
#line 2579 "y.tab.c"
    break;

  case 102:
#line 848 "limbaj.y"
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
               assignCheckTypesArr(variable, nr_vars, (yyvsp[0].id), group[group_id].arrays[obj_id], group[group_id].nr_arrays, (yyvsp[-5].id));
               group[group_id].arrays[obj_id][arr_id].value[index] = variable[assign_id].value;
         }
#line 2612 "y.tab.c"
    break;

  case 103:
#line 876 "limbaj.y"
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
               assignCheckTypesArr(group[group_id2].vars[obj_id2], group[group_id2].nr_vars, (yyvsp[0].id), group[group_id].arrays[obj_id], group[group_id].nr_arrays, (yyvsp[-7].id));
               group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2648 "y.tab.c"
    break;

  case 104:
#line 907 "limbaj.y"
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
               assignCheckTypesArrArr(group[group_id].arrays[obj_id], group[group_id].nr_arrays, (yyvsp[-10].id), group[group_id2].arrays[obj_id2], group[group_id2].nr_arrays, (yyvsp[-3].id));
               group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].arrays[obj_id2][arr_id2].value[index2];
         }
#line 2691 "y.tab.c"
    break;

  case 108:
#line 950 "limbaj.y"
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
#line 2716 "y.tab.c"
    break;

  case 110:
#line 971 "limbaj.y"
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
#line 2735 "y.tab.c"
    break;

  case 111:
#line 985 "limbaj.y"
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
#line 2754 "y.tab.c"
    break;

  case 112:
#line 1001 "limbaj.y"
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
#line 2773 "y.tab.c"
    break;

  case 113:
#line 1015 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2786 "y.tab.c"
    break;

  case 114:
#line 1023 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2799 "y.tab.c"
    break;

  case 116:
#line 1032 "limbaj.y"
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
#line 2818 "y.tab.c"
    break;

  case 117:
#line 1046 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2831 "y.tab.c"
    break;

  case 118:
#line 1054 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2844 "y.tab.c"
    break;

  case 120:
#line 1063 "limbaj.y"
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
#line 2863 "y.tab.c"
    break;

  case 121:
#line 1077 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2876 "y.tab.c"
    break;

  case 122:
#line 1085 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2889 "y.tab.c"
    break;

  case 124:
#line 1094 "limbaj.y"
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
#line 2908 "y.tab.c"
    break;

  case 125:
#line 1108 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2921 "y.tab.c"
    break;

  case 126:
#line 1116 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2934 "y.tab.c"
    break;

  case 128:
#line 1125 "limbaj.y"
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
#line 2953 "y.tab.c"
    break;

  case 129:
#line 1139 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[-2].id));
          MyError(err);
     }
}
#line 2966 "y.tab.c"
    break;

  case 130:
#line 1147 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          char err[MAX_MSG];
          sprintf(err, "Variable '%s' used in control statement not declared!", (yyvsp[0].id));
          MyError(err);
     }
}
#line 2979 "y.tab.c"
    break;

  case 135:
#line 1162 "limbaj.y"
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
#line 3010 "y.tab.c"
    break;

  case 136:
#line 1188 "limbaj.y"
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
#line 3039 "y.tab.c"
    break;

  case 137:
#line 1212 "limbaj.y"
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
#line 3068 "y.tab.c"
    break;

  case 142:
#line 1344 "limbaj.y"
                               {}
#line 3074 "y.tab.c"
    break;

  case 143:
#line 1345 "limbaj.y"
                                        {}
#line 3080 "y.tab.c"
    break;

  case 144:
#line 1346 "limbaj.y"
                                        {}
#line 3086 "y.tab.c"
    break;


#line 3090 "y.tab.c"

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
#line 1351 "limbaj.y"

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

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}
