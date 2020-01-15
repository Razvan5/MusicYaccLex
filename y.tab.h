/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    OBIECT = 258,
    FUNCTIE = 259,
    BOX = 260,
    DEFAULT = 261,
    CASE = 262,
    ELSE = 263,
    INCLUDE = 264,
    LOWT = 265,
    BIGT = 266,
    LEQ = 267,
    BEQ = 268,
    EQUAL = 269,
    NOTEQUAL = 270,
    INCREMENT = 271,
    DECREMENT = 272,
    IN = 273,
    MAIN = 274,
    PROG_BEGIN = 275,
    PROG_END = 276,
    INT = 277,
    INT_NR = 278,
    FLOAT = 279,
    FLOAT_NR = 280,
    CHAR = 281,
    CHAR_VAL = 282,
    STRING = 283,
    STRING_VAL = 284,
    BOOL = 285,
    BOOL_VAL = 286,
    CLASS = 287,
    METODE = 288,
    STRUCT = 289,
    ASSIGN = 290,
    DEFINE = 291,
    IF = 292,
    SWITCH = 293,
    WHILE = 294,
    FOR = 295,
    OR = 296,
    AND = 297,
    NOT = 298,
    SOL = 299,
    ENDSOL = 300,
    ID = 301,
    EVAL = 302,
    RETURN = 303
  };
#endif
/* Tokens.  */
#define OBIECT 258
#define FUNCTIE 259
#define BOX 260
#define DEFAULT 261
#define CASE 262
#define ELSE 263
#define INCLUDE 264
#define LOWT 265
#define BIGT 266
#define LEQ 267
#define BEQ 268
#define EQUAL 269
#define NOTEQUAL 270
#define INCREMENT 271
#define DECREMENT 272
#define IN 273
#define MAIN 274
#define PROG_BEGIN 275
#define PROG_END 276
#define INT 277
#define INT_NR 278
#define FLOAT 279
#define FLOAT_NR 280
#define CHAR 281
#define CHAR_VAL 282
#define STRING 283
#define STRING_VAL 284
#define BOOL 285
#define BOOL_VAL 286
#define CLASS 287
#define METODE 288
#define STRUCT 289
#define ASSIGN 290
#define DEFINE 291
#define IF 292
#define SWITCH 293
#define WHILE 294
#define FOR 295
#define OR 296
#define AND 297
#define NOT 298
#define SOL 299
#define ENDSOL 300
#define ID 301
#define EVAL 302
#define RETURN 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "limbaj.y" /* yacc.c:1909  */

  char* strval;

#line 154 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
