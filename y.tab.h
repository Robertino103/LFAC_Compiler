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

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
