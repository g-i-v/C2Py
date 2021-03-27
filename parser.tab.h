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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    NAME = 258,
    STRING_TOKEN = 259,
    INTEGER = 260,
    FLOAT = 261,
    GT = 262,
    LT = 263,
    NE = 264,
    EQ = 265,
    GE = 266,
    LE = 267,
    TOKEN_ASS = 268,
    TOKEN_ADD = 269,
    TOKEN_SUB = 270,
    TOKEN_MUL = 271,
    TOKEN_DIV = 272,
    LB = 273,
    RB = 274,
    LSB = 275,
    RSB = 276,
    LCB = 277,
    RCB = 278,
    PRINT = 279,
    SCAN = 280,
    PRINT_INT = 281,
    PRINT_STRING = 282,
    PRINT_FLOAT = 283,
    INT_TOKEN = 284,
    CHAR_TOKEN = 285,
    FLOAT_TOKEN = 286,
    TOKEN_COL = 287,
    TOKEN_COM = 288,
    TOKEN_SEM = 289,
    TOKEN_QUO = 290,
    TOKEN_E = 291,
    IO_VAR = 292,
    EOL = 293,
    FOR = 294,
    IO_FLOAT = 295,
    IO_INT = 296,
    IO_STRING = 297,
    IF = 298,
    ELSE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parser.y" /* yacc.c:1909  */

    struct statement* stat;
    struct expression* express;
    struct symbol* symb;
    char* string_lit;
    int int_lit;
    float float_lit;
		struct in_out* in_out;

#line 109 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
