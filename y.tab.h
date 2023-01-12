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
#line 93 "limbaj.y"

     char* id;
     char* val;

#line 134 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
