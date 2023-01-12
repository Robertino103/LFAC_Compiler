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
    GT = 284,
    PLUS = 285,
    MINUS = 286,
    TIMES = 287,
    DIVIDE = 288,
    LPAREN = 289,
    RPAREN = 290
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
#define PLUS 285
#define MINUS 286
#define TIMES 287
#define DIVIDE 288
#define LPAREN 289
#define RPAREN 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "limbaj.y"

     char* id;
     char* val;

#line 132 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
