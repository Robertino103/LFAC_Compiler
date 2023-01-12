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


#line 148 "y.tab.c"

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
    PRINT = 266,
    BGINGLOBAL = 267,
    ENDGLOBAL = 268,
    BGINFNCT = 269,
    ENDFNCT = 270,
    GROUP = 271,
    GROUP_ACCESS = 272,
    BGINFIELDS = 273,
    ENDFIELDS = 274,
    BGINMETHODS = 275,
    ENDMETHODS = 276,
    IF = 277,
    FOR = 278,
    WHILE = 279,
    CHECK = 280,
    LE = 281,
    GE = 282,
    LT = 283,
    GT = 284
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
#define PRINT 266
#define BGINGLOBAL 267
#define ENDGLOBAL 268
#define BGINFNCT 269
#define ENDFNCT 270
#define GROUP 271
#define GROUP_ACCESS 272
#define BGINFIELDS 273
#define ENDFIELDS 274
#define BGINMETHODS 275
#define ENDMETHODS 276
#define IF 277
#define FOR 278
#define WHILE 279
#define CHECK 280
#define LE 281
#define GE 282
#define LT 283
#define GT 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "limbaj.y"

     char* id;
     char* val;

#line 263 "y.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

#define YYUNDEFTOK  2
#define YYMAXUTOK   284


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
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    96,    97,   100,   101,   104,   105,   108,
     109,   112,   123,   124,   125,   128,   137,   148,   149,   150,
     153,   156,   157,   158,   162,   173,   174,   175,   178,   189,
     215,   216,   217,   219,   228,   229,   230,   253,   257,   281,
     282,   283,   286,   295,   306,   307,   308,   311,   317,   321,
     322,   323,   328,   340,   348,   349,   349,   356,   365,   379,
     396,   413,   433,   445,   457,   466,   482,   495,   511,   530,
     552,   553,   554,   557,   571,   572,   582,   594,   604,   610,
     616,   617,   627,   633,   639,   640,   650,   656,   662,   663,
     673,   679,   685,   686,   696,   702,   708,   711,   712,   713,
     715,   735,   753,   772,   773,   774,   777,   778,   779,   780,
     781
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NR", "ID", "GID", "VID", "TIP", "BGIN",
  "END", "ASSIGN", "PRINT", "BGINGLOBAL", "ENDGLOBAL", "BGINFNCT",
  "ENDFNCT", "GROUP", "GROUP_ACCESS", "BGINFIELDS", "ENDFIELDS",
  "BGINMETHODS", "ENDMETHODS", "IF", "FOR", "WHILE", "CHECK", "LE", "GE",
  "LT", "GT", "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'",
  "':'", "$accept", "progr", "global", "global_defs", "function_def",
  "functions", "function", "fnct_list_param", "fnct_param", "lista_param",
  "param", "methods", "method", "fields", "field", "declaratii",
  "declaratie", "method_list_param", "method_param",
  "method_check_list_param", "method_check_param", "bloc", "list",
  "statement", "$@1", "for_statement", "ctrl_statement", "lista_apel",
  "apel", "group_statement_list", "group_statement", YY_NULLPTR
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
      59,    40,    41,    44,    91,    93,   123,   125,    58
};
# endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    57,    18,    22,    91,    37,    26,    57,    30,  -155,
      69,    57,    28,    31,    16,  -155,    51,   150,   126,    55,
     132,    47,   134,     6,   161,   163,   152,   154,   138,  -155,
     142,  -155,    45,   144,  -155,  -155,   164,  -155,    78,  -155,
     140,   146,   166,   168,  -155,    65,   172,   148,   173,   153,
     156,   158,    24,   160,  -155,  -155,  -155,   171,   176,  -155,
      94,    34,   162,    95,    80,  -155,   111,    98,   165,  -155,
     177,  -155,   113,   175,   113,  -155,   167,  -155,  -155,   181,
      86,  -155,  -155,   159,   174,   169,  -155,  -155,   170,  -155,
     168,  -155,  -155,   178,   179,    74,   180,    58,    63,   182,
     185,   184,   186,  -155,  -155,  -155,   176,   183,   191,  -155,
     188,  -155,   117,   197,  -155,  -155,  -155,    92,  -155,   192,
     119,   123,   125,   129,   133,   135,   137,   139,   141,   143,
     187,   145,   189,   190,  -155,   193,   199,    10,   194,   195,
    -155,   200,   196,  -155,    74,    90,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,    45,   201,   202,    45,
      45,  -155,   198,   203,   206,  -155,  -155,   204,   209,  -155,
    -155,   205,   207,    -3,   147,   149,     0,    21,   213,  -155,
    -155,  -155,   151,    99,   208,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   102,   124,  -155,  -155,   210,  -155,   211,   212,
    -155,   214,   215,   213,   103,   218,  -155,   229,    68,  -155,
    -155,   216,   217,   219,   223,   221,   233,     3,   226,   235,
    -155,  -155,   155,   236,  -155,  -155,   227,  -155,   224,  -155,
    -155,   225,  -155,  -155,   232,   157,  -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     7,     0,     0,     0,     0,     0,     1,
       0,    30,    33,     0,     0,     4,     0,    31,     0,     0,
       0,     0,     0,    17,     0,     0,     0,    32,     0,     8,
       0,     9,    49,     0,     2,    31,     0,    35,     0,    18,
       0,     0,    25,    12,    10,    55,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    20,    34,     0,    44,    36,
       0,     0,     0,     0,     0,    13,     0,     0,     0,    62,
       0,    54,     0,     0,     0,    48,     0,    50,    19,     0,
       0,    45,    28,     0,     0,     0,    26,    15,     0,    11,
       0,    53,    52,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,    51,    47,    38,     0,     0,    21,    27,
       0,    14,     0,     0,   100,   101,   102,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      64,    63,     0,    56,     0,     0,    80,    79,    88,    87,
      96,    95,    84,    83,    92,    91,    78,    77,    86,    85,
      94,    93,    82,    81,    90,    89,    49,     0,     0,    49,
      49,    29,     0,     0,     0,    22,    16,     0,     0,    99,
      57,    58,     0,     0,     0,     0,     0,     0,    39,    37,
      23,    65,     0,     0,     0,    70,    74,    76,    75,    73,
      71,    72,     0,     0,    40,    66,    67,    60,     0,     0,
      42,     0,     0,     0,     0,     0,    59,     0,   103,    41,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    43,     0,     0,   110,    24,     0,   104,     0,   107,
     106,     0,   105,    69,     0,     0,   109,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,  -155,  -155,   230,  -155,   115,  -155,
     220,  -155,    64,  -155,   222,   242,    50,  -155,    -7,  -155,
     101,  -155,  -154,   -52,  -155,  -155,   136,  -155,   100,  -155,
     -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    11,    19,    20,    64,    65,    38,
      39,   137,   138,    61,    62,     7,     8,   203,   204,    80,
      81,    34,    52,    53,    68,   101,    99,   117,   118,   227,
     228
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    45,    46,    47,    45,    46,    47,   224,    48,   225,
       1,    48,   183,    36,   226,   186,   187,   136,     9,    49,
      50,    51,    49,    50,    51,    45,    46,    47,    45,    46,
      47,   173,    48,    75,   195,    48,    10,   200,    37,    15,
     235,    60,    14,    49,    50,    51,    49,    50,    51,    45,
      46,    47,    26,    84,     4,    32,    48,    16,   201,    23,
      17,    22,    18,     5,     4,    25,    24,    49,    50,    51,
      29,    33,   224,     5,   225,    66,    18,   114,   115,   226,
     116,    27,    67,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   180,   181,    12,   182,    13,    82,    87,
      83,    88,    93,   207,    94,   208,   210,   220,   211,   221,
      56,    57,    89,    90,    91,    92,    97,    98,   105,   106,
     140,   141,   146,   147,   143,   144,   148,   149,   150,   151,
      28,    76,   152,   153,    76,    76,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   167,   168,
     196,   197,   198,   199,   205,   206,   212,   213,   239,   240,
     246,   247,    31,    -5,    35,    40,    41,    -6,    55,    43,
      42,    58,    44,    60,    54,    63,    69,    71,    36,   100,
      96,    59,    70,    79,    72,   104,   135,    73,   112,    74,
      77,   139,    86,   107,   108,   131,    95,   103,   136,   109,
     142,   174,   145,   172,   110,   111,   219,   134,   191,   236,
     102,   209,     0,   113,   130,   119,   132,   177,   133,   192,
     202,   222,   193,   166,   175,   169,   170,   214,   171,   188,
     176,   178,   223,   232,   184,   185,   190,   234,   238,   241,
     189,   194,   245,     0,   179,   215,     0,   216,   217,    30,
     229,   218,   230,    21,   231,   233,   237,   242,     0,   243,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
      52,     4,     5,     6,     4,     5,     6,     4,    11,     6,
      12,    11,   166,     7,    11,   169,   170,     7,     0,    22,
      23,    24,    22,    23,    24,     4,     5,     6,     4,     5,
       6,    21,    11,     9,    37,    11,    14,    37,    32,    13,
      37,     7,     5,    22,    23,    24,    22,    23,    24,     4,
       5,     6,    36,    19,     7,     8,    11,     7,    37,    31,
      30,    11,     7,    16,     7,    34,    38,    22,    23,    24,
      15,    21,     4,    16,     6,    10,     7,     3,     4,    11,
       6,    30,    17,    25,    26,    27,    28,    29,    25,    26,
      27,    28,    29,     3,     4,     4,     6,     6,     4,     4,
       6,     6,     4,     4,     6,     6,     4,     4,     6,     6,
      32,    33,    32,    33,     3,     4,     3,     4,    32,    33,
       3,     4,     3,     4,    32,    33,     3,     4,     3,     4,
       4,   183,     3,     4,   186,   187,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,    32,    33,     3,     4,
       3,     4,    30,    13,    30,     4,     3,    13,     4,    31,
      18,    31,    30,     7,    30,     7,     4,     4,     7,     4,
       3,    35,    34,     7,    31,     4,     3,    31,    10,    31,
      30,     3,    30,    34,    20,    10,    31,    30,     7,    30,
       3,   137,    10,     4,    34,    90,   213,   106,     4,   227,
      74,     3,    -1,    34,    32,    35,    32,    17,    32,    10,
       7,     3,    17,    36,    30,    36,    36,    17,    35,    31,
      35,    35,     3,    10,    33,    33,    30,     4,     3,     3,
      37,    34,    10,    -1,   144,    34,    -1,    35,    34,    19,
      34,    36,    35,    11,    35,    34,    30,    30,    -1,    35,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    40,    41,     7,    16,    42,    54,    55,     0,
      14,    43,     4,     6,     5,    13,    55,    30,     7,    44,
      45,    54,    55,    31,    38,    34,    36,    30,     4,    15,
      45,    30,     8,    55,    60,    30,     7,    32,    48,    49,
       4,     3,    18,    31,    30,     4,     5,     6,    11,    22,
      23,    24,    61,    62,    30,     4,    32,    33,    31,    35,
       7,    52,    53,     7,    46,    47,    10,    17,    63,     4,
      34,     4,    31,    31,    31,     9,    62,    30,    49,     7,
      58,    59,     4,     6,    19,    53,    30,     4,     6,    32,
      33,     3,     4,     4,     6,    31,     3,     3,     4,    65,
       4,    64,    65,    30,     4,    32,    33,    34,    20,    30,
      34,    47,    10,    34,     3,     4,     6,    66,    67,    35,
      25,    26,    27,    28,    29,    25,    26,    27,    28,    29,
      32,    10,    32,    32,    59,     3,     7,    50,    51,     3,
       3,     4,     3,    32,    33,    10,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     3,     4,    36,     3,     4,    36,
      36,    35,     4,    21,    51,    30,    35,    17,    35,    67,
       3,     4,     6,    61,    33,    33,    61,    61,    31,    37,
      30,     4,    10,    17,    34,    37,     3,     4,     3,     4,
      37,    37,     7,    56,    57,     3,     4,     4,     6,     3,
       4,     6,    32,    33,    17,    34,    35,    34,    36,    57,
       4,     6,     3,     3,     4,     6,    11,    68,    69,    34,
      35,    35,    10,    34,     4,    37,    69,    30,     3,     3,
       4,     3,    30,    35,    35,    10,     3,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    46,    47,    47,    48,    48,    48,
      49,    50,    50,    50,    51,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    61,
      61,    61,    62,    62,    62,    63,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      67,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     2,     3,     0,     3,     2,
       3,     5,     0,     1,     3,     2,     5,     0,     1,     3,
       2,     0,     2,     3,     8,     0,     2,     3,     2,     5,
       0,     2,     3,     2,     5,     4,     5,    10,     7,     0,
       1,     3,     2,     5,     0,     1,     3,     2,     3,     0,
       2,     3,     3,     3,     2,     0,     5,     6,     6,     9,
       8,    11,     2,     5,     5,     7,     8,     8,    10,    13,
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
#line 93 "limbaj.y"
                                           {printf("\nSuccesfully compiled!\n"); createSymbolTable();}
#line 1608 "y.tab.c"
    break;

  case 11:
#line 112 "limbaj.y"
                                          {
     if(checkFunction(function, nr_functions, (yyvsp[-3].id)))
     {
          MyError("A function with the same name was already declared !");
     }
     function[nr_functions].type = (yyvsp[-4].id);
     function[nr_functions].name = (yyvsp[-3].id);
     nr_functions++;
}
#line 1622 "y.tab.c"
    break;

  case 15:
#line 128 "limbaj.y"
                    { 
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, (yyvsp[0].id)))
     {
          MyError("Duplicate parameter used!");
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = (yyvsp[-1].id);
     function[nr_functions].params[function[nr_functions].nr_params].key = (yyvsp[0].id);
     function[nr_functions].nr_params++;
}
#line 1636 "y.tab.c"
    break;

  case 16:
#line 137 "limbaj.y"
                              {
     if (checkVar(function[nr_functions].params, function[nr_functions].nr_params, (yyvsp[-3].id)))
     {
          MyError("Duplicate parameter used!");
     }
     function[nr_functions].params[function[nr_functions].nr_params].type = (yyvsp[-4].id);
     function[nr_functions].params[function[nr_functions].nr_params].key = (yyvsp[-3].id);
     function[nr_functions].nr_params++;
}
#line 1650 "y.tab.c"
    break;

  case 24:
#line 162 "limbaj.y"
                                                                 {
         if(checkMethod(group[nr_groups].methods, group[nr_groups].nr_methods, (yyvsp[-6].id)))
         {
               MyError("Method already defined!");
         }
         group[nr_groups].methods[group[nr_groups].nr_methods].name = (yyvsp[-6].id);
         group[nr_groups].methods[group[nr_groups].nr_methods].type = (yyvsp[-7].id);
         group[nr_groups].nr_methods++;
         }
#line 1664 "y.tab.c"
    break;

  case 28:
#line 178 "limbaj.y"
               {
          if(checkVar(group[nr_groups].vars[0], group[nr_groups].nr_vars, (yyvsp[0].id)))
          {
               MyError("Field variable already declared!");
          }
          for(int i = 0; i < MAX_OBJECTS; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = (yyvsp[-1].id);
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = (yyvsp[0].id);
          }
          group[nr_groups].nr_vars++; 
          }
#line 1680 "y.tab.c"
    break;

  case 29:
#line 189 "limbaj.y"
                        {
          if(getInt((yyvsp[-1].val)) > MAX_EL_ARRAY)
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
#line 1709 "y.tab.c"
    break;

  case 33:
#line 219 "limbaj.y"
                    {
               if(checkVar(variable, nr_vars, (yyvsp[0].id)))
               {
                    MyError("Variable already declared!");
               }
               variable[nr_vars].type = (yyvsp[-1].id);
               variable[nr_vars].key = (yyvsp[0].id);
               nr_vars++;     
          }
#line 1723 "y.tab.c"
    break;

  case 36:
#line 230 "limbaj.y"
                            {
               if(checkArr(array, nr_arrays, (yyvsp[-3].id))){
                    MyError("Array already declared!");
               }
               int val = getInt((yyvsp[-1].val));
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

               array[nr_arrays].key = (yyvsp[-3].id);
               array[nr_arrays].size = val;
               array[nr_arrays].type = (yyvsp[-4].id);
               for(int i = 0; i < val; i++)
                    array[nr_arrays].value[i] = "0";
               nr_arrays++;
           }
#line 1751 "y.tab.c"
    break;

  case 37:
#line 253 "limbaj.y"
                                                                                          {
               group[nr_groups].name = (yyvsp[-8].id);
               nr_groups++;
           }
#line 1760 "y.tab.c"
    break;

  case 38:
#line 257 "limbaj.y"
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
#line 1787 "y.tab.c"
    break;

  case 42:
#line 286 "limbaj.y"
                      {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, (yyvsp[0].id)))
     {
          MyError("Duplicate parameter used!");
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-1].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[0].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
#line 1801 "y.tab.c"
    break;

  case 43:
#line 295 "limbaj.y"
                                {
     if (checkVar(group[nr_groups].methods[group[nr_groups].nr_methods].params, group[nr_groups].methods[group[nr_groups].nr_methods].nr_params, (yyvsp[-3].id)))
     {
          MyError("Duplicate parameter used!");
     }
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-4].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[-3].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
     }
#line 1815 "y.tab.c"
    break;

  case 47:
#line 311 "limbaj.y"
                            {
     
}
#line 1823 "y.tab.c"
    break;

  case 52:
#line 328 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               int id2 = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(id == -1)
                    MyError("First variable not found!\n");
               else if(id2 == -1)
                    MyError("Second variable not found!\n");
               else if(variable[id2].value == NULL)
                    MyError("Second variable does not store a value!\n");
               else
                    variable[id].value = variable[id2].value;
          }
#line 1840 "y.tab.c"
    break;

  case 53:
#line 340 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(id == -1)
                    MyError("Variable not found!\n");
               else
                    variable[id].value = (yyvsp[0].val);
                        
          }
#line 1853 "y.tab.c"
    break;

  case 55:
#line 349 "limbaj.y"
              { fnctId = getFunctionId(function, nr_functions, (yyvsp[0].id)); }
#line 1859 "y.tab.c"
    break;

  case 56:
#line 349 "limbaj.y"
                                                                                         {
               if(checkFunction(function, nr_functions, (yyvsp[-4].id)) == 0)
               {
                    MyError("Called function has not been defined in the function definition section!");
               }
               param_no = 0;
         }
#line 1871 "y.tab.c"
    break;

  case 57:
#line 356 "limbaj.y"
                                 {
               int vid = getVecId(array, nr_arrays, (yyvsp[-5].id));
               int index = getInt((yyvsp[-3].val));
               if(vid == -1)
                    MyError("Array not found!\n");
               if(index < 0 || index >= array[vid].size)
                    MyError("Segmentation fault! (core dumped)\n");
               array[vid].value[index] = (yyvsp[0].val);
         }
#line 1885 "y.tab.c"
    break;

  case 58:
#line 365 "limbaj.y"
                                 {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-5].id));
               int var_id = getVarId(variable, nr_vars, (yyvsp[0].id));
               int index = getInt((yyvsp[-3].val));

               if(arr_id == -1)
                    MyError("Array not found!\n");
               if(var_id == -1)
                    MyError("Variable not found!\n");
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = variable[var_id].value;
         }
#line 1904 "y.tab.c"
    break;

  case 59:
#line 379 "limbaj.y"
                                         {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-8].id));
               int index = getInt((yyvsp[-6].val));
               int arr_id2 = getVecId(array, nr_arrays, (yyvsp[-3].id));
               int index2 = getInt((yyvsp[-1].val));

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
#line 1926 "y.tab.c"
    break;

  case 60:
#line 396 "limbaj.y"
                                                {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-7].id));
               int index = getInt((yyvsp[-5].val));

               int group_id = getObjGroupId((yyvsp[-2].id));
               int obj_id = getObjId((yyvsp[-2].id), group_id);
               int var_id = getObjVarId((yyvsp[0].id), group_id, obj_id);

               if(arr_id == -1)
                    MyError("First array not found!\n");
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");  
               if(index < 0 || index >= array[arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               
               array[arr_id].value[index] = group[group_id].vars[obj_id][var_id].value;
         }
#line 1948 "y.tab.c"
    break;

  case 61:
#line 413 "limbaj.y"
                                                         {
               int arr_id = getVecId(array, nr_arrays, (yyvsp[-10].id));
               int index = getInt((yyvsp[-8].val));

               int group_id = getObjGroupId((yyvsp[-5].id));
               int obj_id = getObjId((yyvsp[-5].id), group_id);
               int arr_id2 = getObjVecId((yyvsp[-3].id), group_id, obj_id);
               int index2 = getInt((yyvsp[-1].val));

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
#line 1973 "y.tab.c"
    break;

  case 62:
#line 433 "limbaj.y"
                  {
               int group_id = getGroupId((yyvsp[-1].id));
               if(group_id == -1)
               {
                    MyError("No such group defined!");
               }
               else{
                    group[group_id].object[group[group_id].nr_objects].key = (yyvsp[0].id);
                    group[group_id].object[group[group_id].nr_objects].type = (yyvsp[-1].id);
                    group[group_id].nr_objects++;
               }
         }
#line 1990 "y.tab.c"
    break;

  case 63:
#line 445 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               int assign_id = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the first variable does not exist!\n");
               if(assign_id == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
#line 2007 "y.tab.c"
    break;

  case 64:
#line 457 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = (yyvsp[0].val);
         }
#line 2021 "y.tab.c"
    break;

  case 65:
#line 466 "limbaj.y"
                                                        {
               int group_id = getObjGroupId((yyvsp[-6].id));
               int obj_id = getObjId((yyvsp[-6].id), group_id);
               int var_id = getObjVarId((yyvsp[-4].id), group_id, obj_id);
               
               int group_id2 = getObjGroupId((yyvsp[-2].id));
               int obj_id2 = getObjId((yyvsp[-2].id), group_id2);
               int var_id2 = getObjVarId((yyvsp[0].id), group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the first variable does not exist!\n");
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the second variable does not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2042 "y.tab.c"
    break;

  case 66:
#line 482 "limbaj.y"
                                                {
               int group_id = getObjGroupId((yyvsp[-7].id));
               int obj_id = getObjId((yyvsp[-7].id), group_id);
               int arr_id = getObjVecId((yyvsp[-5].id), group_id, obj_id);
               int index = getInt((yyvsp[-3].val));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = (yyvsp[0].val);
         }
#line 2060 "y.tab.c"
    break;

  case 67:
#line 495 "limbaj.y"
                                                {
               int group_id = getObjGroupId((yyvsp[-7].id));
               int obj_id = getObjId((yyvsp[-7].id), group_id);
               int arr_id = getObjVecId((yyvsp[-5].id), group_id, obj_id);
               int index = getInt((yyvsp[-3].val));
               int assign_id = getVarId(variable, nr_vars, (yyvsp[0].id));

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(assign_id == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = variable[assign_id].value;
         }
#line 2081 "y.tab.c"
    break;

  case 68:
#line 511 "limbaj.y"
                                                                 {
               int group_id = getObjGroupId((yyvsp[-9].id));
               int obj_id = getObjId((yyvsp[-9].id), group_id);
               int arr_id = getObjVecId((yyvsp[-7].id), group_id, obj_id);
               int index = getInt((yyvsp[-5].val));

               int group_id2 = getObjGroupId((yyvsp[-2].id));
               int obj_id2 = getObjId((yyvsp[-2].id), group_id2);
               int var_id2 = getObjVarId((yyvsp[0].id), group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || arr_id == -1)
                    MyError("Can't assign that becah the vector does not exist!\n");
               if(index < 0 || index > group[group_id].arrays[obj_id][arr_id].size)
                    MyError("Segmentation fault! (core dumped)\n");
               if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the variable does not exist!\n");
               else
                    group[group_id].arrays[obj_id][arr_id].value[index] = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 2105 "y.tab.c"
    break;

  case 69:
#line 530 "limbaj.y"
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
#line 2132 "y.tab.c"
    break;

  case 73:
#line 557 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2151 "y.tab.c"
    break;

  case 75:
#line 572 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2166 "y.tab.c"
    break;

  case 76:
#line 582 "limbaj.y"
                                    {
     if(!checkVar(variable, nr_vars, (yyvsp[-4].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2181 "y.tab.c"
    break;

  case 77:
#line 594 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2196 "y.tab.c"
    break;

  case 78:
#line 604 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2207 "y.tab.c"
    break;

  case 79:
#line 610 "limbaj.y"
                            {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2218 "y.tab.c"
    break;

  case 81:
#line 617 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2233 "y.tab.c"
    break;

  case 82:
#line 627 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2244 "y.tab.c"
    break;

  case 83:
#line 633 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2255 "y.tab.c"
    break;

  case 85:
#line 640 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2270 "y.tab.c"
    break;

  case 86:
#line 650 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2281 "y.tab.c"
    break;

  case 87:
#line 656 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2292 "y.tab.c"
    break;

  case 89:
#line 663 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2307 "y.tab.c"
    break;

  case 90:
#line 673 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2318 "y.tab.c"
    break;

  case 91:
#line 679 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2329 "y.tab.c"
    break;

  case 93:
#line 686 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2344 "y.tab.c"
    break;

  case 94:
#line 696 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[-2].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2355 "y.tab.c"
    break;

  case 95:
#line 702 "limbaj.y"
                         {
     if(!checkVar(variable, nr_vars, (yyvsp[0].id)))
     {
          MyError("Variable used in control statement not declared!");
     }
}
#line 2366 "y.tab.c"
    break;

  case 100:
#line 715 "limbaj.y"
          {
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
               int nr_int = getInt((yyvsp[0].val));
               if (nr_int != 0 && nr_int != 1)
               {
                    MyError("The type of the variable in the function call does not match the function definition!");
               }
          }
          param_no++;
     }
#line 2391 "y.tab.c"
    break;

  case 101:
#line 735 "limbaj.y"
          {
          if(isArray(function[fnctId].params, function[fnctId].nr_params, param_no))
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, param_no);
          if(checkVar(variable, nr_vars, (yyvsp[0].id)) == 0)
          {
               MyError("The variable used in the function call is not declared!");
          }
          int current_var_id = getVarId(variable, nr_vars, (yyvsp[0].id));
          char *current_type = getVarType(variable, nr_vars, current_var_id);
          if (strcmp(def_type, current_type) != 0)
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          param_no++;
     }
#line 2414 "y.tab.c"
    break;

  case 102:
#line 753 "limbaj.y"
           {
          if(!isArray(function[fnctId].params, function[fnctId].nr_params, param_no))
          {
               MyError("The type of the variable in the function call does not match the function definition!");
          }
          char *def_type = getVarType(function[fnctId].params, function[fnctId].nr_params, param_no);
          if(checkArr(array, nr_arrays, (yyvsp[0].id)) == 0)
          {
               MyError("The array used in the function call is not declared!");
          }
          int current_arr_id = getVecId(array, nr_arrays, (yyvsp[0].id));
          char *current_type = getArrType(array, nr_arrays, current_arr_id);
          if (strcmp(def_type, current_type) != 0)
          {
               MyError("The type of the array in the function call does not match the function definition!");
          }
          param_no++;
     }
#line 2437 "y.tab.c"
    break;

  case 107:
#line 778 "limbaj.y"
                               {}
#line 2443 "y.tab.c"
    break;

  case 108:
#line 779 "limbaj.y"
                                        {}
#line 2449 "y.tab.c"
    break;

  case 109:
#line 780 "limbaj.y"
                                        {}
#line 2455 "y.tab.c"
    break;


#line 2459 "y.tab.c"

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
#line 785 "limbaj.y"

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
