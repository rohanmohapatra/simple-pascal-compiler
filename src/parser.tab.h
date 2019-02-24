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
    T_USES = 258,
    T_WHILE = 259,
    T_PROGRAM = 260,
    T_VAR = 261,
    T_TYPE = 262,
    T_IF = 263,
    T_BEGIN = 264,
    T_END = 265,
    T_CONST = 266,
    T_WRITELN = 267,
    T_PROCEDURE = 268,
    T_FUNCTION = 269,
    T_FOR = 270,
    T_DO = 271,
    T_TO = 272,
    T_DOWNTO = 273,
    T_BOOL_AND = 274,
    T_BOOL_OR = 275,
    T_BOOL_NOT = 276,
    T_REL_LE = 277,
    T_REL_GE = 278,
    T_REL_NE = 279,
    T_SINGLEEQ = 280,
    T_BIT_LS = 281,
    T_BIT_RS = 282,
    T_ASOP = 283,
    T_AS_PE = 284,
    T_AS_SE = 285,
    T_AS_MULE = 286,
    T_AS_DIVE = 287,
    T_ARRAY = 288,
    T_IDENTIFIER = 289,
    T_DATATYPE = 290,
    T_INTVAL = 291,
    T_FLOATVAL = 292,
    T_BOOLVAL = 293,
    T_STRINGVAL = 294
  };
#endif
/* Tokens.  */
#define T_USES 258
#define T_WHILE 259
#define T_PROGRAM 260
#define T_VAR 261
#define T_TYPE 262
#define T_IF 263
#define T_BEGIN 264
#define T_END 265
#define T_CONST 266
#define T_WRITELN 267
#define T_PROCEDURE 268
#define T_FUNCTION 269
#define T_FOR 270
#define T_DO 271
#define T_TO 272
#define T_DOWNTO 273
#define T_BOOL_AND 274
#define T_BOOL_OR 275
#define T_BOOL_NOT 276
#define T_REL_LE 277
#define T_REL_GE 278
#define T_REL_NE 279
#define T_SINGLEEQ 280
#define T_BIT_LS 281
#define T_BIT_RS 282
#define T_ASOP 283
#define T_AS_PE 284
#define T_AS_SE 285
#define T_AS_MULE 286
#define T_AS_DIVE 287
#define T_ARRAY 288
#define T_IDENTIFIER 289
#define T_DATATYPE 290
#define T_INTVAL 291
#define T_FLOATVAL 292
#define T_BOOLVAL 293
#define T_STRINGVAL 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "parser.y" /* yacc.c:1909  */

	char *str;
	char *type;
	int intval;
	float floatval;

#line 139 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
