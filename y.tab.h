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
    SEMICO = 265,
    BGIN = 266,
    END = 267,
    ASSIGN = 268,
    ASSIGNEXP = 269,
    PRINT = 270,
    BGINGLOBAL = 271,
    ENDGLOBAL = 272,
    BGINFNCT = 273,
    ENDFNCT = 274,
    GROUP = 275,
    GROUP_ACCESS = 276,
    BGINFIELDS = 277,
    ENDFIELDS = 278,
    BGINMETHODS = 279,
    ENDMETHODS = 280,
    IF = 281,
    FOR = 282,
    WHILE = 283,
    CHECK = 284,
    LE = 285,
    GE = 286,
    LT = 287,
    GT = 288,
    PLUS = 289,
    MINUS = 290,
    TIMES = 291,
    DIVIDE = 292,
    LPAREN = 293,
    RPAREN = 294,
    OR = 295,
    AND = 296
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
#define SEMICO 265
#define BGIN 266
#define END 267
#define ASSIGN 268
#define ASSIGNEXP 269
#define PRINT 270
#define BGINGLOBAL 271
#define ENDGLOBAL 272
#define BGINFNCT 273
#define ENDFNCT 274
#define GROUP 275
#define GROUP_ACCESS 276
#define BGINFIELDS 277
#define ENDFIELDS 278
#define BGINMETHODS 279
#define ENDMETHODS 280
#define IF 281
#define FOR 282
#define WHILE 283
#define CHECK 284
#define LE 285
#define GE 286
#define LT 287
#define GT 288
#define PLUS 289
#define MINUS 290
#define TIMES 291
#define DIVIDE 292
#define LPAREN 293
#define RPAREN 294
#define OR 295
#define AND 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 95 "limbaj.y"

     char* id;
     char* val;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
