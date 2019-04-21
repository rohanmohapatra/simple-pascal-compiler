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

#ifndef YY_YY_PARSER_ICG_TAB_H_INCLUDED
# define YY_YY_PARSER_ICG_TAB_H_INCLUDED
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
    T_THEN = 264,
    T_ELSE = 265,
    T_BEGIN = 266,
    T_END = 267,
    T_CONST = 268,
    T_WRITELN = 269,
    T_PROCEDURE = 270,
    T_FUNCTION = 271,
    T_FOR = 272,
    T_DO = 273,
    T_TO = 274,
    T_OF = 275,
    T_DOWNTO = 276,
    T_BOOL_AND = 277,
    T_BOOL_OR = 278,
    T_BOOL_NOT = 279,
    T_REL_LE = 280,
    T_REL_GE = 281,
    T_REL_NE = 282,
    T_SINGLEEQ = 283,
    T_BIT_LS = 284,
    T_BIT_RS = 285,
    T_ASOP = 286,
    T_AS_PE = 287,
    T_AS_SE = 288,
    T_AS_MULE = 289,
    T_AS_DIVE = 290,
    T_ARRAY = 291,
    T_INDEXTYPE = 292,
    T_IDENTIFIER = 293,
    T_DATATYPE = 294,
    T_INTVAL = 295,
    T_FLOATVAL = 296,
    T_BOOLVAL = 297,
    T_STRINGVAL = 298
  };
#endif
/* Tokens.  */
#define T_USES 258
#define T_WHILE 259
#define T_PROGRAM 260
#define T_VAR 261
#define T_TYPE 262
#define T_IF 263
#define T_THEN 264
#define T_ELSE 265
#define T_BEGIN 266
#define T_END 267
#define T_CONST 268
#define T_WRITELN 269
#define T_PROCEDURE 270
#define T_FUNCTION 271
#define T_FOR 272
#define T_DO 273
#define T_TO 274
#define T_OF 275
#define T_DOWNTO 276
#define T_BOOL_AND 277
#define T_BOOL_OR 278
#define T_BOOL_NOT 279
#define T_REL_LE 280
#define T_REL_GE 281
#define T_REL_NE 282
#define T_SINGLEEQ 283
#define T_BIT_LS 284
#define T_BIT_RS 285
#define T_ASOP 286
#define T_AS_PE 287
#define T_AS_SE 288
#define T_AS_MULE 289
#define T_AS_DIVE 290
#define T_ARRAY 291
#define T_INDEXTYPE 292
#define T_IDENTIFIER 293
#define T_DATATYPE 294
#define T_INTVAL 295
#define T_FLOATVAL 296
#define T_BOOLVAL 297
#define T_STRINGVAL 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 105 "parser_icg.y" /* yacc.c:1909  */

	struct parse_node
	{
		char *str;
		char *type;
		int intval;
		float floatval;
		struct ast_node * ast;
	}s;

#line 151 "parser_icg.tab.h" /* yacc.c:1909  */
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

#endif /* !YY_YY_PARSER_ICG_TAB_H_INCLUDED  */
