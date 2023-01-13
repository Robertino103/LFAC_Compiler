/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    FNR = 259,
    STRING = 260,
    CHAR = 261,
    ID = 262,
    GID = 263,
    VID = 264,
    TIP = 265,
    CTIP = 266,
    BOOLVAL = 267,
    BGIN = 268,
    END = 269,
    ASSIGN = 270,
    ASSIGNEXP = 271,
    PRINT = 272,
    BGINGLOBAL = 273,
    ENDGLOBAL = 274,
    BGINFNCT = 275,
    ENDFNCT = 276,
    GROUP = 277,
    GROUP_ACCESS = 278,
    BGINFIELDS = 279,
    ENDFIELDS = 280,
    BGINMETHODS = 281,
    ENDMETHODS = 282,
    IF = 283,
    FOR = 284,
    WHILE = 285,
    CHECK = 286,
    LE = 287,
    GE = 288,
    LT = 289,
    GT = 290,
    PLUS = 291,
    MINUS = 292,
    TIMES = 293,
    DIVIDE = 294,
    LPAREN = 295,
    RPAREN = 296,
    OR = 297,
    AND = 298,
    TYPEOF = 299,
    EVAL = 300
  };
#endif
/* Tokens.  */
#define NR 258
#define FNR 259
#define STRING 260
#define CHAR 261
#define ID 262
#define GID 263
#define VID 264
#define TIP 265
#define CTIP 266
#define BOOLVAL 267
#define BGIN 268
#define END 269
#define ASSIGN 270
#define ASSIGNEXP 271
#define PRINT 272
#define BGINGLOBAL 273
#define ENDGLOBAL 274
#define BGINFNCT 275
#define ENDFNCT 276
#define GROUP 277
#define GROUP_ACCESS 278
#define BGINFIELDS 279
#define ENDFIELDS 280
#define BGINMETHODS 281
#define ENDMETHODS 282
#define IF 283
#define FOR 284
#define WHILE 285
#define CHECK 286
#define LE 287
#define GE 288
#define LT 289
#define GT 290
#define PLUS 291
#define MINUS 292
#define TIMES 293
#define DIVIDE 294
#define LPAREN 295
#define RPAREN 296
#define OR 297
#define AND 298
#define TYPEOF 299
#define EVAL 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 186 "limbaj.y"

     char* id;
     char* val;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
