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
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
#define MAX_EL_ARRAY 1000
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
typedef struct{
     char *type;
     char *key;
<<<<<<< HEAD
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


#line 132 "y.tab.c"
=======
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
     vecmap arrays[50];
     methodmap methods[100];
     varmap object[100];
} groupmap;
groupmap group[100];

void printAll();
void MyError(char *err);
int nr_vars = 0;
int nr_arrays = 0;
int nr_groups = 0;


#line 122 "y.tab.c"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

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
<<<<<<< HEAD
    STRING = 259,
    ID = 260,
=======
    ID = 259,
    GID = 260,
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
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
    ENDMETHODS = 276
  };
#endif
/* Tokens.  */
#define NR 258
<<<<<<< HEAD
#define STRING 259
#define ID 260
=======
#define ID 259
#define GID 260
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
<<<<<<< HEAD
#line 62 "limbaj.y"
=======
#line 52 "limbaj.y"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

     char* id;
     char* val;

<<<<<<< HEAD
#line 232 "y.tab.c"
=======
#line 221 "y.tab.c"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

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
<<<<<<< HEAD
#define YYLAST   161
=======
#define YYLAST   170
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142
=======
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

#define YYUNDEFTOK  2
#define YYMAXUTOK   276


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
      23,    24,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    22,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
<<<<<<< HEAD
       0,    77,    77,    80,    81,    84,    85,    88,    89,    92,
      93,    96,    99,   100,   101,   105,   113,   114,   115,   118,
     120,   127,   128,   129,   131,   133,   134,   135,   140,   155,
     178,   179,   180,   183,   186,   187,   188,   191,   199,   200,
     201,   204,   210,   214,   215,   216,   220,   221,   222,   224,
     225,   226,   227,   228,   253,   254,   270,   271,   274,   275,
     276,   279,   280,   284,   285,   286,   288
=======
       0,    66,    66,    69,    70,    73,    74,    77,    78,    81,
      82,    85,    88,    89,    90,    94,   101,   102,   103,   106,
     113,   119,   120,   121,   123,   128,   129,   130,   142,   146,
     169,   170,   171,   174,   177,   178,   179,   182,   189,   190,
     191,   194,   200,   204,   205,   206,   210,   222,   230,   231,
     232,   233,   234,   243,   255,   265,   274,   292,   293,   296,
     297,   298,   301,   302,   304,   305,   306,   307
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
<<<<<<< HEAD
  "$end", "error", "$undefined", "NR", "STRING", "ID", "VID", "TIP",
  "BGIN", "END", "ASSIGN", "PRINT", "BGINGLOBAL", "ENDGLOBAL", "BGINFNCT",
=======
  "$end", "error", "$undefined", "NR", "ID", "GID", "VID", "TIP", "BGIN",
  "END", "ASSIGN", "PRINT", "BGINGLOBAL", "ENDGLOBAL", "BGINFNCT",
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
  "ENDFNCT", "GROUP", "GROUP_ACCESS", "BGINFIELDS", "ENDFIELDS",
  "BGINMETHODS", "ENDMETHODS", "';'", "'('", "')'", "'{'", "'}'", "'['",
  "']'", "':'", "','", "$accept", "progr", "global", "global_defs",
  "function_def", "functions", "function", "methods", "method", "fields",
  "field", "declaratii", "declaratie", "lista_param", "param",
  "method_list_param", "method_param", "method_check_list_param",
  "method_check_param", "bloc", "list", "statement", "lista_apel",
  "group_statement_list", "group_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    40,    41,   123,   125,    91,    93,    58,
      44
};
# endif

#define YYPACT_NINF (-11)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
<<<<<<< HEAD
      -8,     9,     8,     1,    56,    27,    52,     9,    44,   -11,
      32,     9,    15,    40,    45,   -11,    46,    59,    64,    11,
      51,     3,    53,    -2,    66,    71,    60,    63,    57,   -11,
      61,   -11,    24,    62,   -11,   -11,    72,   -11,    10,   -11,
      65,    67,    74,    75,   -11,    -3,    69,    80,    22,    68,
     -11,   -11,   -11,    75,    79,   -11,    58,     5,    70,    17,
     -11,    43,    82,    76,    86,   -11,   -11,    77,   -11,   -11,
      88,    19,   -11,   -11,    73,    78,    81,   -11,   -11,   -11,
     -11,    84,   -11,    21,    83,   -11,   -11,   -11,    79,    94,
      95,   -11,    49,   -11,    98,    96,   -11,    85,    99,    -4,
      87,   -11,   -11,   -11,    50,   -11,    89,    90,    92,   -11,
     -11,   -11,   100,   -11,   -11,   103,    26,   -11,   -11,    93,
     100,    31,   -11,   105,    97,   112,    -5,   101,    54,   102,
     -11,   -11,   104,   -11,   -11,   -11,    91,   -11,   110,    55,
     -11,   -11
=======
      -8,     1,    29,    24,    48,    20,    45,     1,     8,   -11,
      36,     1,    19,    41,    44,   -11,    49,    60,    66,    17,
      50,     5,    52,    -6,    71,    73,    62,    64,    55,   -11,
      65,   -11,    30,    67,   -11,   -11,    75,   -11,    16,   -11,
      58,    54,    76,    77,   -11,    -7,    81,    68,    82,    22,
      69,   -11,   -11,   -11,    77,    83,   -11,    53,     4,    70,
      21,    11,    84,    90,   -11,    91,   -11,   -11,    74,   -11,
     -11,    93,    23,   -11,   -11,    72,    78,    79,   -11,   -11,
     -11,   -11,    92,   -11,    25,    80,   -11,   -11,   -11,    83,
      97,    96,   -11,    57,   -11,   101,    95,   -11,    85,   102,
      -1,    87,   -11,    94,   -11,    59,   -11,    89,    88,    98,
     -11,   103,   -11,   -11,   108,   -11,   -11,   -11,   106,    26,
     -11,   -11,    99,   108,    33,   -11,   107,   100,   112,    -4,
     104,    61,   115,   -11,   -11,   109,   -11,   -11,   -11,   105,
     -11,   111,    63,   -11,   -11
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     7,     0,     0,     0,     0,     0,     1,
       0,    21,    24,     0,     0,     4,     0,    22,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    23,     0,     8,
       0,     9,    43,     0,     2,    22,     0,    26,     0,    31,
<<<<<<< HEAD
       0,     0,    16,    30,    10,     0,     0,    49,     0,     0,
      23,    33,    25,     0,    38,    27,     0,     0,     0,     0,
      53,     0,     0,     0,     0,    48,    42,     0,    44,    32,
       0,     0,    39,    19,     0,     0,     0,    17,    11,    47,
      46,     0,    56,     0,     0,    45,    41,    29,     0,     0,
      12,    18,     0,    50,     0,     0,    40,     0,     0,     0,
       0,    55,    54,    57,     0,    20,     0,     0,     0,    13,
      52,    51,    34,    28,    14,     0,     0,    35,    37,     0,
       0,    58,    36,     0,     0,    66,     0,     0,     0,     0,
      65,    15,     0,    59,    62,    61,     0,    60,     0,     0,
      64,    63
=======
       0,     0,    16,    30,    10,     0,     0,     0,    49,     0,
       0,    23,    33,    25,     0,    38,    27,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    48,    42,     0,    44,
      32,     0,     0,    39,    19,     0,     0,     0,    17,    11,
      47,    46,     0,    57,     0,     0,    45,    41,    29,     0,
       0,    12,    18,     0,    50,     0,     0,    40,     0,     0,
       0,     0,    55,    54,    58,     0,    20,     0,     0,     0,
      13,     0,    52,    51,    34,    28,    14,    56,     0,     0,
      35,    37,     0,     0,    59,    36,     0,     0,    67,     0,
       0,     0,     0,    66,    15,     0,    60,    63,    62,     0,
      61,     0,     0,    65,    64
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -11,   -11,   -11,   -11,   -11,   -11,   106,   -11,    23,   -11,
      34,   116,     2,   107,   108,   -11,   -10,   -11,    33,   -11,
     -11,   109,   -11,   -11,     4
=======
     -11,   -11,   -11,   -11,   -11,   -11,   110,   -11,    28,   -11,
      86,   114,    -2,   113,   116,   -11,     0,   -11,    43,   -11,
     -11,   117,   -11,   -11,   -10
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     2,     3,     6,    11,    19,    20,    99,   100,    57,
      58,     7,     8,    38,    39,   116,   117,    71,    72,    34,
      48,    49,    83,   126,   127
=======
      -1,     2,     3,     6,    11,    19,    20,   100,   101,    58,
      59,     7,     8,    38,    39,   119,   120,    72,    73,    34,
      49,    50,    84,   129,   130
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
     123,   124,    60,    98,     1,    36,   125,    61,     9,    16,
       4,    32,    56,    22,    62,    10,     4,   107,    18,     5,
      63,   131,    37,    33,    75,     5,    29,    45,    46,    45,
      46,    66,    14,    47,    52,    47,   123,   124,    23,    18,
      53,    78,   125,    87,    24,    93,    79,    53,    80,    88,
     119,    94,   101,   110,   102,   111,   120,   134,   140,   135,
     141,    12,    13,    73,    74,    15,    17,    25,    27,    28,
      26,    40,    -5,    31,    41,    35,    -6,    51,    42,    82,
      43,    56,    36,    44,    50,    65,    70,    81,    54,    84,
      68,    76,    77,    86,    92,    55,    64,    97,    90,    85,
      89,   103,    98,    91,   106,   136,   104,   115,   118,   109,
     122,    95,   112,   105,   114,   128,   113,   130,   121,   138,
     139,    96,   108,   133,   129,    30,   137,    21,     0,     0,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,    69
=======
     126,    36,   127,    61,     1,    16,    99,   128,     4,    22,
      62,    57,     4,    32,    80,    81,    63,     5,    37,    33,
     108,     5,   134,    76,    18,    14,    45,    46,    47,     9,
      17,    67,    29,    48,    45,    46,    47,   126,    10,   127,
      53,    48,    23,    18,   128,    79,    54,    88,    24,    94,
     122,    54,    12,    89,    13,    95,   123,    74,    15,    75,
     102,   103,   112,   113,   137,   138,   143,   144,    25,    26,
      28,    27,    31,    -5,    35,    40,    41,    -6,    43,    52,
      42,    55,    56,    57,    36,    64,    66,    44,    82,    51,
      71,    69,    78,    83,    85,    65,    86,    87,    91,    90,
      98,    92,    93,    99,   104,   105,   107,   117,    96,   110,
     121,   111,   114,   106,   115,   118,   133,   131,   139,   135,
     116,   142,     0,   125,   124,    21,   136,   132,   109,    30,
       0,   140,    97,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
      70
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       5,     6,     5,     7,    12,     7,    11,    10,     0,     7,
       7,     8,     7,    11,    17,    14,     7,    21,     7,    16,
      23,    26,    24,    21,    19,    16,    15,     5,     6,     5,
       6,     9,     5,    11,    24,    11,     5,     6,    23,     7,
      30,    24,    11,    24,    29,    24,     3,    30,     5,    30,
      24,    30,     3,     3,     5,     5,    30,     3,     3,     5,
       5,     5,     6,     5,     6,    13,    22,    27,    22,     5,
      25,     5,    13,    22,     3,    22,    13,     5,    18,     3,
      23,     7,     7,    22,    22,     5,     7,     5,    23,     3,
      22,    57,    22,     5,    10,    28,    27,     3,    20,    22,
      27,     3,     7,    22,     5,     3,    10,     7,     5,    22,
     120,    28,    23,    28,    22,    10,    26,     5,    25,    28,
      10,    88,    99,    22,    27,    19,    22,    11,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    53
=======
       4,     7,     6,    10,    12,     7,     7,    11,     7,    11,
      17,     7,     7,     8,     3,     4,    23,    16,    24,    21,
      21,    16,    26,    19,     7,     5,     4,     5,     6,     0,
      22,     9,    15,    11,     4,     5,     6,     4,    14,     6,
      24,    11,    23,     7,    11,    24,    30,    24,    29,    24,
      24,    30,     4,    30,     6,    30,    30,     4,    13,     6,
       3,     4,     3,     4,     3,     4,     3,     4,    27,    25,
       4,    22,    22,    13,    22,     4,     3,    13,    23,     4,
      18,    23,    28,     7,     7,     4,     4,    22,     4,    22,
       7,    22,    22,     3,     3,    27,    22,     4,    20,    27,
       3,    22,    10,     7,     3,    10,     4,     4,    28,    22,
       4,    17,    23,    28,    26,     7,     4,    10,     3,   129,
      22,    10,    -1,   123,    25,    11,    22,    27,   100,    19,
      -1,    22,    89,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      54
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    32,    33,     7,    16,    34,    42,    43,     0,
<<<<<<< HEAD
      14,    35,     5,     6,     5,    13,    43,    22,     7,    36,
      37,    42,    43,    23,    29,    27,    25,    22,     5,    15,
      37,    22,     8,    43,    50,    22,     7,    24,    44,    45,
       5,     3,    18,    23,    22,     5,     6,    11,    51,    52,
      22,     5,    24,    30,    23,    28,     7,    40,    41,    44,
       5,    10,    17,    23,    27,     5,     9,    52,    22,    45,
       7,    48,    49,     5,     6,    19,    41,    22,    24,     3,
       5,     5,     3,    53,     3,    22,     5,    24,    30,    27,
      20,    22,    10,    24,    30,    28,    49,     3,     7,    38,
      39,     3,     5,     3,    10,    28,     5,    21,    39,    22,
       3,     5,    23,    26,    22,     7,    46,    47,     5,    24,
      30,    25,    47,     5,     6,    11,    54,    55,    10,    27,
       5,    26,    55,    22,     3,     5,     3,    22,    28,    10,
       3,     5
=======
      14,    35,     4,     6,     5,    13,    43,    22,     7,    36,
      37,    42,    43,    23,    29,    27,    25,    22,     4,    15,
      37,    22,     8,    43,    50,    22,     7,    24,    44,    45,
       4,     3,    18,    23,    22,     4,     5,     6,    11,    51,
      52,    22,     4,    24,    30,    23,    28,     7,    40,    41,
      44,    10,    17,    23,     4,    27,     4,     9,    52,    22,
      45,     7,    48,    49,     4,     6,    19,    41,    22,    24,
       3,     4,     4,     3,    53,     3,    22,     4,    24,    30,
      27,    20,    22,    10,    24,    30,    28,    49,     3,     7,
      38,    39,     3,     4,     3,    10,    28,     4,    21,    39,
      22,    17,     3,     4,    23,    26,    22,     4,     7,    46,
      47,     4,    24,    30,    25,    47,     4,     6,    11,    54,
      55,    10,    27,     4,    26,    55,    22,     3,     4,     3,
      22,    28,    10,     3,     4
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    38,    39,    40,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      44,    44,    44,    45,    46,    46,    46,    47,    48,    48,
      48,    49,    50,    51,    51,    51,    52,    52,    52,    52,
<<<<<<< HEAD
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    55,    55,    55,    55
=======
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    55,    55
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     2,     3,     0,     3,     2,
       3,     5,     0,     2,     3,     8,     0,     2,     3,     2,
       5,     0,     2,     3,     2,     5,     4,     5,    10,     7,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     3,     0,     2,     3,     3,     3,     2,     1,
<<<<<<< HEAD
       4,     6,     6,     2,     5,     5,     1,     3,     0,     2,
       3,     3,     3,     6,     6,     2,     1
=======
       4,     6,     6,     2,     5,     5,     7,     1,     3,     0,
       2,     3,     3,     3,     6,     6,     2,     1
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
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
<<<<<<< HEAD
#line 77 "limbaj.y"
                                           {printf("program corect sintactic\n");}
#line 1503 "y.tab.c"
    break;

  case 15:
#line 105 "limbaj.y"
                                                                 {
         group[nr_groups].group_methods[group[nr_groups].nr_methods].method_name = (yyvsp[-6].id);
         group[nr_groups].group_methods[group[nr_groups].nr_methods].type = (yyvsp[-7].id);
         group[nr_groups].group_methods[group[nr_groups].nr_methods].group_id = nr_groups;
         group[nr_groups].nr_methods++;
         }
#line 1514 "y.tab.c"
    break;

  case 19:
#line 118 "limbaj.y"
               { assignValue(group[nr_groups].group_vars, group[nr_groups].nr_vars, (yyvsp[0].id), 0);
                 group[nr_groups].nr_vars++; }
#line 1521 "y.tab.c"
    break;

  case 20:
#line 120 "limbaj.y"
                        { for(int i=0; i<(yyvsp[-1].int_val); i++)
                              assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, (yyvsp[-3].id), i, 0);
                          group[nr_groups].group_arrays[group[nr_groups].nr_arrays].size = (yyvsp[-1].int_val);
                          group[nr_groups].nr_arrays++; 
                        }
#line 1531 "y.tab.c"
    break;

  case 24:
#line 131 "limbaj.y"
                    { assignValue(variable, nr_vars, (yyvsp[0].id), 0);
                      nr_vars++; }
#line 1538 "y.tab.c"
    break;

  case 27:
#line 135 "limbaj.y"
                             {for(int i=0; i<(yyvsp[-1].int_val); i++)
                                   assignArrValue(array, nr_arrays, (yyvsp[-3].id), i, 0);
                              array[nr_arrays].size = (yyvsp[-1].int_val);
                              nr_arrays++;     
                              }
#line 1548 "y.tab.c"
    break;

  case 28:
#line 140 "limbaj.y"
                                                                                         {
               group[nr_groups].group_name = (yyvsp[-8].id);
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
#line 1568 "y.tab.c"
    break;

  case 29:
#line 155 "limbaj.y"
=======
#line 66 "limbaj.y"
                                           {printf("\nSuccesfully compiled!\n");}
#line 1494 "y.tab.c"
    break;

  case 15:
#line 94 "limbaj.y"
                                                                 {
         group[nr_groups].methods[group[nr_groups].nr_methods].name = (yyvsp[-6].id);
         group[nr_groups].methods[group[nr_groups].nr_methods].type = (yyvsp[-7].id);
         group[nr_groups].nr_methods++;
         }
#line 1504 "y.tab.c"
    break;

  case 19:
#line 106 "limbaj.y"
               {
          for(int i = 0; i < 50; i++){
               group[nr_groups].vars[i][group[nr_groups].nr_vars].type = (yyvsp[-1].id);
               group[nr_groups].vars[i][group[nr_groups].nr_vars].key = (yyvsp[0].id);
          }
          group[nr_groups].nr_vars++; 
          }
#line 1516 "y.tab.c"
    break;

  case 20:
#line 113 "limbaj.y"
                        { 
               group[nr_groups].arrays[group[nr_groups].nr_arrays].size = (yyvsp[-1].val);
               group[nr_groups].nr_arrays++;
          }
#line 1525 "y.tab.c"
    break;

  case 24:
#line 123 "limbaj.y"
                    {
               variable[nr_vars].type = (yyvsp[-1].id);
               variable[nr_vars].key = (yyvsp[0].id);
               nr_vars++;     
          }
#line 1535 "y.tab.c"
    break;

  case 27:
#line 130 "limbaj.y"
                            {
               int val = getInt((yyvsp[-1].val));
               if(val > 50)
                    MyError("Sorry! We can't hold more than 50 elements in an array! Go try RUST!\n");

               array[nr_arrays].key = (yyvsp[-3].id);
               array[nr_arrays].size = val;
               array[nr_arrays].type = (yyvsp[-4].id);
               for(int i = 0; i < val; i++)
                    array[nr_arrays].value[i] = "0";
               nr_arrays++;
           }
#line 1552 "y.tab.c"
    break;

  case 28:
#line 142 "limbaj.y"
                                                                                          {
               group[nr_groups].name = (yyvsp[-8].id);
               nr_groups++;
           }
#line 1561 "y.tab.c"
    break;

  case 29:
#line 146 "limbaj.y"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
                                                       {
               bool found_class = 0;
               bool found_method = 0;
               for(int i=0; i<nr_groups; i++)
               {
<<<<<<< HEAD
                    if(strcmp((yyvsp[-5].id), group[i].group_name) == 0)
=======
                    if(strcmp((yyvsp[-5].id), group[i].name) == 0)
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
                    {
                         found_class = 1;
                         for(int j=0; j<group[nr_groups].nr_methods; j++)
                         {
<<<<<<< HEAD
                              if(strcmp((yyvsp[-3].id), group[i].group_methods[j].method_name) == 0)
=======
                              if(strcmp((yyvsp[-3].id), group[i].methods[j].name) == 0)
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
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
<<<<<<< HEAD
#line 1595 "y.tab.c"
    break;

  case 37:
#line 191 "limbaj.y"
                      {
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-1].id);
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[0].id);
     group[nr_groups].group_methods[group[nr_groups].nr_methods].params[group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params].value = 0;
     group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params++;
}
#line 1606 "y.tab.c"
    break;

  case 41:
#line 204 "limbaj.y"
                            {
     
}
#line 1614 "y.tab.c"
    break;

  case 47:
#line 221 "limbaj.y"
                        { assignValue(variable, nr_vars, (yyvsp[-2].id), (yyvsp[0].int_val));}
#line 1620 "y.tab.c"
    break;

  case 48:
#line 222 "limbaj.y"
                    {    char *current_id = (yyvsp[0].id);
                         printf("%d\n", getValue(variable, nr_vars, current_id));}
#line 1627 "y.tab.c"
    break;

  case 49:
#line 224 "limbaj.y"
                 {printAll(variable, nr_vars);}
#line 1633 "y.tab.c"
    break;

  case 51:
#line 226 "limbaj.y"
                                 {assignArrValue(array, nr_arrays, (yyvsp[-5].id), (yyvsp[-3].int_val), getValue(variable, nr_vars, (yyvsp[0].id)));}
#line 1639 "y.tab.c"
    break;

  case 52:
#line 227 "limbaj.y"
                                 {assignArrValue(array, nr_arrays, (yyvsp[-5].id), (yyvsp[-3].int_val), (yyvsp[0].int_val));}
#line 1645 "y.tab.c"
    break;

  case 53:
#line 228 "limbaj.y"
                 {
=======
#line 1588 "y.tab.c"
    break;

  case 37:
#line 182 "limbaj.y"
                      {
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].type = (yyvsp[-1].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].params[group[nr_groups].methods[group[nr_groups].nr_methods].nr_params].key = (yyvsp[0].id);
     group[nr_groups].methods[group[nr_groups].nr_methods].nr_params++;
}
#line 1598 "y.tab.c"
    break;

  case 41:
#line 194 "limbaj.y"
                            {
     
}
#line 1606 "y.tab.c"
    break;

  case 46:
#line 210 "limbaj.y"
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
#line 1623 "y.tab.c"
    break;

  case 47:
#line 222 "limbaj.y"
                        {
               int id = getVarId(variable, nr_vars, (yyvsp[-2].id));
               if(id == -1)
                    MyError("Variable not found!\n");
               else
                    variable[id].value = (yyvsp[0].val);
                        
          }
#line 1636 "y.tab.c"
    break;

  case 49:
#line 231 "limbaj.y"
                 { printAll(variable, nr_vars); }
#line 1642 "y.tab.c"
    break;

  case 52:
#line 234 "limbaj.y"
                                 {
               int vid = getVecId(array, nr_arrays, (yyvsp[-5].id));
               int index = getInt((yyvsp[-3].val));
               if(vid == -1)
                    MyError("Array not found!\n");
               if(index < 0 || index >= array[vid].size)
                    MyError("Segmentation fault! (core dumped)\n");
               array[vid].value[index] = (yyvsp[0].val);
         }
#line 1656 "y.tab.c"
    break;

  case 53:
#line 243 "limbaj.y"
                  {
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
               int group_id = getGroupId((yyvsp[-1].id));
               if(group_id == -1)
               {
                    MyError("No such group defined!");
               }
<<<<<<< HEAD
               else
               {
                    group[group_id].object[group[group_id].nr_objects].name = (yyvsp[0].id);
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
#line 1675 "y.tab.c"
    break;

  case 55:
#line 254 "limbaj.y"
                                        {
               int group_id = getObjType((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id));
               if(group_id == -1) MyError("No such object found!");
               int ok = IsMethod((yyvsp[-2].id), group_id);
               if(ok==0)
               {
                    MyError("No such method found!");
               }
               else
               {
                    assignValue(group[group_id].object[obj_id].group_vars, group[group_id].nr_vars, (yyvsp[-2].id), (yyvsp[0].int_val));
               }
         }
#line 1694 "y.tab.c"
    break;

  case 62:
#line 280 "limbaj.y"
                               {   if(!assignValueMethod(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, (yyvsp[-2].id), (yyvsp[0].int_val)))
                                        if (!assignValueMethod(variable, nr_vars, (yyvsp[-2].id), (yyvsp[0].int_val)))
                                             MyError("Variable %s not found!", (yyvsp[-2].id));
                               }
#line 1703 "y.tab.c"
    break;

  case 63:
#line 284 "limbaj.y"
                                        {assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, (yyvsp[-5].id), (yyvsp[-3].int_val), getValue(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, (yyvsp[0].id)));}
#line 1709 "y.tab.c"
    break;

  case 64:
#line 285 "limbaj.y"
                                        {assignArrValue(group[nr_groups].group_arrays, group[nr_groups].nr_arrays, (yyvsp[-5].id), (yyvsp[-3].int_val), (yyvsp[0].int_val));}
#line 1715 "y.tab.c"
    break;

  case 65:
#line 286 "limbaj.y"
                           {    char *current_id = (yyvsp[0].id);
                                printf("%d\n", getValue(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params, current_id));}
#line 1722 "y.tab.c"
    break;

  case 66:
#line 288 "limbaj.y"
                        {printAll(group[nr_groups].group_methods[group[nr_groups].nr_methods].params, group[nr_groups].group_methods[group[nr_groups].nr_methods].nr_params);}
#line 1728 "y.tab.c"
    break;


#line 1732 "y.tab.c"
=======
               else{
                    group[group_id].object[group[group_id].nr_objects].key = (yyvsp[0].id);
                    group[group_id].object[group[group_id].nr_objects].type = (yyvsp[-1].id);
                    group[group_id].nr_objects++;
               }
         }
#line 1673 "y.tab.c"
    break;

  case 54:
#line 255 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               int assign_id = getVarId(variable, nr_vars, (yyvsp[0].id));
               if(assign_id == -1)
                    MyError("Can't assign that becah doesnt not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = variable[assign_id].value;
         }
#line 1688 "y.tab.c"
    break;

  case 55:
#line 265 "limbaj.y"
                                        {
               int group_id = getObjGroupId((yyvsp[-4].id));
               int obj_id = getObjId((yyvsp[-4].id), group_id);
               int var_id = getObjVarId((yyvsp[-2].id), group_id, obj_id);
               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the variable does not not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = (yyvsp[0].val);
         }
#line 1702 "y.tab.c"
    break;

  case 56:
#line 274 "limbaj.y"
                                                        {
               int group_id = getObjGroupId((yyvsp[-6].id));
               int obj_id = getObjId((yyvsp[-6].id), group_id);
               int var_id = getObjVarId((yyvsp[-4].id), group_id, obj_id);
               
               int group_id2 = getObjGroupId((yyvsp[-2].id));
               int obj_id2 = getObjId((yyvsp[-2].id), group_id2);
               int var_id2 = getObjVarId((yyvsp[0].id), group_id2, obj_id2);

               if(group_id == -1 || obj_id == -1 || var_id == -1)
                    MyError("Can't assign that becah the first variable does not not exist!\n");
               else if(group_id2 == -1 || obj_id2 == -1 || var_id2 == -1)
                    MyError("Can't assign that becah the second variable does not not exist!\n");
               else
                    group[group_id].vars[obj_id][var_id].value = group[group_id2].vars[obj_id2][var_id2].value;
         }
#line 1723 "y.tab.c"
    break;

  case 63:
#line 302 "limbaj.y"
                               {
                               }
#line 1730 "y.tab.c"
    break;

  case 64:
#line 304 "limbaj.y"
                                        {}
#line 1736 "y.tab.c"
    break;

  case 65:
#line 305 "limbaj.y"
                                        {}
#line 1742 "y.tab.c"
    break;


#line 1746 "y.tab.c"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

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
<<<<<<< HEAD
#line 292 "limbaj.y"
=======
#line 311 "limbaj.y"
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6

int yyerror(char * s){
     printf("eroare: %s la linia:%d\n",s,yylineno);
}

<<<<<<< HEAD
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
=======
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
          for(int j = 0; j < group[i].nr_arrays; j++)
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
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
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
<<<<<<< HEAD
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
=======
>>>>>>> 522b6ef5b65ee2c8a98d8e93a089d92f54954ac6
     return 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
