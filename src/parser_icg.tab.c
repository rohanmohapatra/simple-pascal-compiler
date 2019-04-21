/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser_icg.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<stdlib.h>
	#include <time.h> //link with -lrt
	#include <string.h>
	#include "../uthash/src/uthash.h"
	#include "symbol_table.h"
	#include "ast_handle.h"
	#include "intermediate_code_generation.h"
	#include "var_type.h"
	#include "var.h"
	#include "type.h"
	#include "spc/utils.h"
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
	int successful=1;
lab1();
lab2();
lab3();
push();
push_i();
codegen();
codegen_umin();
codegen_assign();
    int yyerror();
    extern FILE *yyin;
    extern FILE *yyout;
    
    int yylex(void);

	char *var_name_stack[100];
	int var_name_stack_top = -1;

	char *assignment_name_stack[31];
	int assignment_name_stack_top = -1;
	
	char *curr_scope_level = "global";
	// struct var_info {
	// 	char var_name[31];
	// 	// YYLTYPE var_decl_loc;
	// 	char type[10];
	// 	int scope_level;
	// };
	struct variable_type_info var_type_information;
	


	struct symbol_table *SYMBOL_TABLE = NULL; /*Generic Symbol Table*/

	char *type_identifier_stack[10];
	int type_identifier_top = -1;

	struct type_table{
		char user_defined_name[31];
		char actual_type_name[31];
		UT_hash_handle hh;
	};
	struct type_table *TYPE_TABLE = NULL;


	/*Function Declarartions*/

	int dump_stack_in_symbol_table(char *type, int line_no, int col_no);
	int check_valid_identifier(char* var_name);
	union data get_identifier_data(char *var_name);
	struct symbol_table *get_symbol_node(char *var_name,char *curr_scope_level);
	struct variable_type_info get_identifier_type(char *var_name);
	int solution(int a,int b, char* operator);


	/********************************
	*	For Uses Block 	 			*
	*	We need to add all packages *
	*	to a Stack and then send 	*
	*	as a parameter				*
	********************************/
	char *uses_identifier_stack[10];
	int uses_identifier_top = -1;

	/********************************
	*	For Expression Block		*
	*	We need to add all packages *
	*	to a Stack and then send 	*
	*	as a parameter				*
	********************************/
	struct variable_type_info var_type_info_stack[50];
	int var_type_info_top = -1;

	struct ast_func_or_proc_node* ast_func_or_proc_list[10];
	int ast_func_or_proc_list_top = -1;

	int is_rel_op =0;

	struct ast_node *tree;
	/*Stores the AST Root*/

	struct ast_node* next;
	char *last_type;
	
	//int update_variable_value(char* var_name,union data )



#line 170 "parser_icg.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser_icg.tab.h".  */
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
#line 105 "parser_icg.y" /* yacc.c:355  */

	struct parse_node
	{
		char *str;
		char *type;
		int intval;
		float floatval;
		struct ast_node * ast;
	}s;

#line 307 "parser_icg.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 338 "parser_icg.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,     2,     2,    56,    59,     2,
      54,    55,    46,    44,    50,    45,    48,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    49,
      58,     2,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    60,     2,    61,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   179,   183,   187,   197,   196,   205,   210,
     209,   215,   219,   219,   223,   227,   227,   231,   245,   253,
     258,   252,   300,   307,   312,   320,   327,   319,   348,   356,
     369,   390,   407,   406,   411,   416,   415,   422,   426,   427,
     428,   433,   432,   441,   440,   451,   452,   453,   458,   457,
     470,   469,   484,   489,   483,   500,   501,   506,   505,   510,
     514,   522,   526,   527,   531,   532,   533,   537,   538,   542,
     542,   542,   549,   550,   551,   555,   559,   563,   564,   568,
     572,   575,   576,   580,   584,   585,   590,   589,   616,   629,
     641,   653,   669,   697,   703,   704,   747,   747,   754,   755,
     755,   759,   759,   759,   759,   759,   763,   764,   765,   766,
     767,   771,   771,   771,   771,   771,   771,   775,   775,   775,
     779,   779,   779,   779,   779,   779,   782,   782,   785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_USES", "T_WHILE", "T_PROGRAM",
  "T_VAR", "T_TYPE", "T_IF", "T_THEN", "T_ELSE", "T_BEGIN", "T_END",
  "T_CONST", "T_WRITELN", "T_PROCEDURE", "T_FUNCTION", "T_FOR", "T_DO",
  "T_TO", "T_OF", "T_DOWNTO", "T_BOOL_AND", "T_BOOL_OR", "T_BOOL_NOT",
  "T_REL_LE", "T_REL_GE", "T_REL_NE", "T_SINGLEEQ", "T_BIT_LS", "T_BIT_RS",
  "T_ASOP", "T_AS_PE", "T_AS_SE", "T_AS_MULE", "T_AS_DIVE", "T_ARRAY",
  "T_INDEXTYPE", "T_IDENTIFIER", "T_DATATYPE", "T_INTVAL", "T_FLOATVAL",
  "T_BOOLVAL", "T_STRINGVAL", "'+'", "'-'", "'*'", "'/'", "'.'", "';'",
  "','", "':'", "'['", "']'", "'('", "')'", "'%'", "'>'", "'<'", "'&'",
  "'|'", "'~'", "'!'", "$accept", "startPascal", "program", "prog_heading",
  "block", "uses_block", "$@1", "more_libs", "$@2", "constant_block",
  "const_definition", "more_const_definition", "type_block",
  "type_definition", "$@3", "$@4", "variable_block",
  "variable_declaration", "$@5", "$@6", "data_type",
  "more_type_identifiers", "$@7", "more_var_identifiers", "$@8",
  "function_and_procedure_block", "procedure_block", "$@9", "$@10",
  "param_list", "function_block", "$@11", "$@12", "function_param_list",
  "$@13", "$@14", "function_param_continue", "more_func_identifiers",
  "$@15", "fp_block", "execution_block", "execution_body", "statements",
  "structured_statements", "conditional_statement", "$@16", "$@17",
  "if_then_follow", "else_if_block", "else_block", "repetitive_statement",
  "while_statement", "for_statement", "for_list", "print_statements",
  "assignment_statements", "assignment_statement", "@18", "value",
  "expression", "boolean_expression", "$@19", "operator", "assignment_ops",
  "arithmetic_ops", "relational_ops", "boolean_ops", "bitwise_ops",
  "some_numeric_type", "epsilon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    43,    45,    42,    47,    46,    59,
      44,    58,    91,    93,    40,    41,    37,    62,    60,    38,
     124,   126,    33
};
# endif

#define YYPACT_NINF -219

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -23,    32,  -219,    40,   -25,  -219,     8,    -1,    38,
    -219,  -219,  -219,  -219,    16,    53,  -219,    11,    37,  -219,
      29,    56,  -219,    35,    36,  -219,   -10,  -219,  -219,  -219,
      45,    24,  -219,  -219,  -219,  -219,  -219,    42,    39,  -219,
    -219,  -219,    46,    48,    76,    24,    24,  -219,    11,    54,
      59,    70,  -219,    60,    55,    57,  -219,  -219,  -219,  -219,
    -219,    84,  -219,  -219,  -219,    74,    77,    63,  -219,    68,
      67,    79,    90,    21,  -219,   -10,    39,  -219,  -219,   -32,
      56,    93,    94,   107,    92,    97,  -219,    99,   109,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,    83,  -219,
     106,  -219,   108,    60,   104,  -219,  -219,  -219,    76,   110,
     111,   103,  -219,   118,  -219,   105,    28,    28,   125,   130,
     -12,   131,    54,    29,  -219,   133,   122,  -219,  -219,   134,
     123,    56,   126,   135,  -219,  -219,  -219,  -219,  -219,    28,
    -219,    78,   132,   136,   137,    28,  -219,  -219,  -219,  -219,
    -219,    28,  -219,  -219,  -219,   124,    45,   139,    56,   144,
     147,   145,  -219,   156,   119,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,    28,  -219,    28,  -219,  -219,
     179,  -219,   149,   181,    34,   160,   180,  -219,    93,   152,
    -219,  -219,   163,   154,  -219,   160,   160,   112,   199,  -219,
     112,    28,    28,   170,  -219,  -219,   126,  -219,    56,  -219,
    -219,  -219,  -219,   160,   160,  -219,  -219,   161,   162,   112,
     107,  -219,  -219,  -219,   203,  -219,   207,  -219,  -219,  -219,
    -219,   112,  -219
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,   128,     0,     1,     0,     0,   128,
       8,     4,     6,     3,     0,   128,    13,   128,     0,    12,
     128,   128,    18,     0,     0,    11,     0,    19,    17,    22,
     128,   128,    24,     9,     7,   126,   127,     0,   128,    25,
      23,    28,     0,     0,     0,   128,   128,    40,   128,   128,
       0,     0,    34,   128,    41,    48,   128,     5,    39,    38,
      10,     0,    14,    16,    32,     0,     0,     0,    37,     0,
       0,     0,     0,     0,    63,     0,   128,    20,    35,     0,
     128,   128,     0,     0,     0,     0,    61,     0,     0,    86,
      62,    65,    67,    68,    78,    77,    66,    64,     0,    85,
       0,    33,     0,   128,     0,    30,    29,    26,     0,     0,
       0,     0,    47,     0,    52,     0,     0,     0,     0,     0,
       0,   128,   128,   128,    36,     0,     0,    60,    42,     0,
       0,   128,   128,     0,    92,    88,    89,    90,    91,     0,
      93,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,     0,    84,    15,    21,     0,   128,    45,   128,     0,
       0,     0,    59,     0,     0,   117,   118,   119,   114,   115,
     116,   111,   124,   125,   106,   109,   107,   108,   110,   112,
     113,   120,   121,   122,   123,     0,    98,     0,    99,   100,
       0,    69,     0,     0,     0,    87,     0,    27,   128,     0,
      49,    57,     0,     0,    94,    95,    96,   128,     0,    83,
     128,     0,     0,     0,    46,    44,   128,    53,   128,    97,
      79,   128,    80,    81,    82,    31,    58,   128,     0,    70,
       0,    54,    55,    51,   128,    56,   128,    71,    72,    73,
      74,    76,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,  -219,  -219,  -219,  -219,   176,  -219,  -219,
    -219,    96,  -219,   102,  -219,  -219,   205,    71,  -219,  -219,
    -219,   153,  -219,   128,  -219,    -9,  -219,  -219,  -219,    30,
    -219,  -219,  -219,     3,  -219,  -219,  -219,    18,  -219,  -130,
     127,  -218,  -198,  -219,     0,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   116,  -219,  -219,  -219,  -137,
     121,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   164,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,     9,    17,    24,    48,    15,
      19,    62,    21,    28,    38,   102,   108,    40,    53,   126,
     107,    51,    76,    67,   103,    44,    45,    69,    70,   111,
      46,    71,    72,   115,   132,   227,   231,   161,   216,   109,
      57,    73,    90,    91,    92,   208,   234,   237,   238,   239,
      93,    94,    95,   193,    96,    97,    98,   120,   140,   141,
     142,   219,   185,   151,   186,   187,   188,   189,    37,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   159,   164,   229,   104,    16,   105,   106,   194,   220,
       1,    22,   222,    25,   195,     5,    29,    32,   241,   146,
     147,   148,   149,   150,    11,    84,    41,    47,   199,    85,
      35,    36,     6,    86,    52,    87,    58,    59,    88,    42,
      43,    47,    47,     7,    25,    63,    12,    13,   205,    68,
     206,    14,    74,   211,    18,   212,   165,   166,   167,    89,
      20,    23,    30,   172,   173,    26,   134,    27,   135,   136,
     137,   138,    52,    33,   223,   224,    32,   112,   174,   175,
     176,   177,   139,    39,    54,    34,    55,    56,   228,    50,
     178,    49,    61,   181,   182,   183,   184,    64,    65,    68,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   -43,
      66,   -50,    75,    77,    79,    78,    84,    80,    63,    29,
      85,    81,   174,   175,   176,   177,    87,    32,   162,    88,
      82,   110,   121,   113,   178,   179,   180,   181,   182,   183,
     184,   165,   166,   167,    83,   114,   116,   119,   172,   173,
      89,   117,    41,   118,    32,   122,   125,   123,   130,   128,
     133,   145,   129,   174,   175,   176,   177,   131,   144,    89,
     155,   156,   158,   157,   204,   178,   160,   196,   181,   182,
     183,   184,   165,   166,   167,   201,   163,   190,   198,   172,
     173,   191,   192,   200,   112,   203,   202,   207,   209,   210,
     213,   215,   217,   218,   174,   175,   176,   177,   221,   225,
     230,   233,   162,   236,    32,    85,   178,    74,   153,   181,
     182,   183,   184,   232,    60,   154,    31,   197,   214,   101,
     240,   124,    74,   235,   226,   127,   242,   152,   143,   100
};

static const yytype_uint8 yycheck[] =
{
       4,   131,   139,   221,    36,     9,    38,    39,   145,   207,
       5,    15,   210,    17,   151,    38,    20,    21,   236,    31,
      32,    33,    34,    35,    49,     4,    30,    31,   158,     8,
      40,    41,     0,    12,    38,    14,    45,    46,    17,    15,
      16,    45,    46,     3,    48,    49,    38,    48,   185,    53,
     187,    13,    56,    19,    38,    21,    22,    23,    24,    38,
       7,    50,     6,    29,    30,    28,    38,    38,    40,    41,
      42,    43,    76,    38,   211,   212,    80,    81,    44,    45,
      46,    47,    54,    38,    38,    49,    38,    11,   218,    50,
      56,    49,    38,    59,    60,    61,    62,    38,    28,   103,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    54,
      50,    54,    28,    39,    51,    38,     4,    49,   122,   123,
       8,    54,    44,    45,    46,    47,    14,   131,   132,    17,
      51,    38,    49,    39,    56,    57,    58,    59,    60,    61,
      62,    22,    23,    24,    54,    38,    54,    38,    29,    30,
      38,    54,   156,    54,   158,    49,    52,    49,    55,    49,
      55,    31,    51,    44,    45,    46,    47,    49,    43,    38,
      37,    49,    49,    39,    55,    56,    50,    53,    59,    60,
      61,    62,    22,    23,    24,    38,    51,    55,    49,    29,
      30,    55,    55,    49,   198,    39,    51,    18,    49,    18,
      20,    49,    39,    49,    44,    45,    46,    47,     9,    39,
      49,    49,   216,    10,   218,     8,    56,   221,   122,    59,
      60,    61,    62,   227,    48,   123,    21,   156,   198,    76,
     234,   103,   236,   230,   216,   108,   236,   121,   117,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    64,    65,    66,    38,     0,     3,    67,    68,
     132,    49,    38,    48,    13,    72,   132,    69,    38,    73,
       7,    75,   132,    50,    70,   132,    28,    38,    76,   132,
       6,    79,   132,    38,    49,    40,    41,   131,    77,    38,
      80,   132,    15,    16,    88,    89,    93,   132,    71,    49,
      50,    84,   132,    81,    38,    38,    11,   103,    88,    88,
      70,    38,    74,   132,    38,    28,    50,    86,   132,    90,
      91,    94,    95,   104,   132,    28,    85,    39,    38,    51,
      49,    54,    51,    54,     4,     8,    12,    14,    17,    38,
     105,   106,   107,   113,   114,   115,   117,   118,   119,   132,
     131,    84,    78,    87,    36,    38,    39,    83,    79,   102,
      38,    92,   132,    39,    38,    96,    54,    54,    54,    38,
     120,    49,    49,    49,    86,    52,    82,   103,    49,    51,
      55,    49,    97,    55,    38,    40,    41,    42,    43,    54,
     121,   122,   123,   123,    43,    31,    31,    32,    33,    34,
      35,   126,   118,    74,    76,    37,    49,    39,    49,   102,
      50,   100,   132,    51,   122,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    44,    45,    46,    47,    56,    57,
      58,    59,    60,    61,    62,   125,   127,   128,   129,   130,
      55,    55,    55,   116,   122,   122,    53,    80,    49,   102,
      49,    38,    51,    39,    55,   122,   122,    18,   108,    49,
      18,    19,    21,    20,    92,    49,   101,    39,    49,   124,
     105,     9,   105,   122,   122,    39,   100,    98,   102,   104,
      49,    99,   132,    49,   109,    96,    10,   110,   111,   112,
     132,   104,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    69,    68,    68,    71,
      70,    70,    72,    72,    73,    74,    74,    75,    75,    77,
      78,    76,    76,    79,    79,    81,    82,    80,    80,    83,
      83,    83,    85,    84,    84,    87,    86,    86,    88,    88,
      88,    90,    89,    91,    89,    92,    92,    92,    94,    93,
      95,    93,    97,    98,    96,    99,    99,   101,   100,   100,
     102,   103,   104,   104,   105,   105,   105,   106,   106,   108,
     109,   107,   110,   110,   110,   111,   112,   113,   113,   114,
     115,   116,   116,   117,   118,   118,   120,   119,   121,   121,
     121,   121,   122,   122,   122,   122,   124,   123,   125,   125,
     125,   126,   126,   126,   126,   126,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   131,   131,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     6,     0,     5,     1,     0,
       4,     1,     2,     1,     5,     5,     1,     2,     1,     0,
       0,     8,     1,     2,     1,     0,     0,     8,     1,     1,
       1,     6,     0,     4,     1,     0,     4,     1,     2,     2,
       1,     0,     6,     0,     9,     3,     5,     1,     0,     8,
       0,    11,     0,     0,     7,     1,     2,     0,     4,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     0,
       0,     9,     1,     1,     1,     2,     2,     1,     1,     6,
       6,     3,     3,     5,     3,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 172 "parser_icg.y" /* yacc.c:1646  */
    {
	 				//print_tree($<s.ast>1);
	 				tree = (yyvsp[0].s.ast);
	 			}
#line 1701 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 179 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = new_ast_root_node((yyvsp[-2].s.ast),(yyvsp[-1].s.ast));}
#line 1707 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 183 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = new_ast_program_node((yyvsp[-1].s.str));}
#line 1713 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 188 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].s.ast) = new_ast_func_proc_list_node(ast_func_or_proc_list_top, ast_func_or_proc_list);

		(yyval.s.ast) = new_ast_block_node((yyvsp[-5].s.ast),(yyvsp[-4].s.ast),(yyvsp[-3].s.ast),(yyvsp[-2].s.ast),(yyvsp[-1].s.ast),(yyvsp[0].s.ast));
	}
#line 1723 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 197 "parser_icg.y" /* yacc.c:1646  */
    {
		uses_identifier_top++;
		uses_identifier_stack[uses_identifier_top] = strdup(yylval.s.str);
	}
#line 1732 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 202 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = new_ast_uses_node(uses_identifier_top,uses_identifier_stack);
	}
#line 1740 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 210 "parser_icg.y" /* yacc.c:1646  */
    {
		uses_identifier_top++;
		uses_identifier_stack[uses_identifier_top] = strdup(yylval.s.str);
	}
#line 1749 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 232 "parser_icg.y" /* yacc.c:1646  */
    {
		printf("\nType block action");

		struct ast_typedef_node* temp = (struct ast_typedef_node*)((yyvsp[0].s.ast));
		if(temp==NULL){
			printf("\n\t$2 is Null\n");
		}
		else{
			printf("\n\tStack size: %d\n",temp->stack_size);
		}
		(yyval.s.ast) = new_ast_type_node((yyvsp[0].s.ast));
	}
#line 1766 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = NULL;
	}
#line 1774 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 253 "parser_icg.y" /* yacc.c:1646  */
    {
		type_identifier_top++;
		type_identifier_stack[type_identifier_top] = strdup(yylval.s.str);
	}
#line 1783 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 258 "parser_icg.y" /* yacc.c:1646  */
    {
		char** new_types = (char**)malloc(sizeof(char*)*10);

		for(int i = 0; i <= type_identifier_top; i++)
		{
			new_types[i] = strdup(type_identifier_stack[i]);
		}

		for(int i = 0; i <= type_identifier_top; i++)
		{
			struct type_table *s = NULL;
			HASH_FIND_STR(TYPE_TABLE, type_identifier_stack[i], s);
			if(!s)
			{
				s = malloc(sizeof(struct type_table));
				strcpy(s->user_defined_name, type_identifier_stack[i]);
				strcpy(s->actual_type_name, yylval.s.type);
				HASH_ADD_STR( TYPE_TABLE, user_defined_name, s );  /* var_name: name of key field */
			}
			else
			{
				YYABORT;
			}
			type_identifier_stack[i] = NULL;
		}
		
		struct type_node_info new_type_entry;
		new_type_entry.new_types = new_types;
		new_type_entry.type_identifier_top = type_identifier_top;
		new_type_entry.actual_type = yylval.s.type;
		type_node_stack[++type_node_stack_top] = new_type_entry;

		type_identifier_top = -1;
	}
#line 1822 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 295 "parser_icg.y" /* yacc.c:1646  */
    {
		struct type_node_info curr = type_node_stack[type_node_stack_top--];
		(yyval.s.ast) = new_ast_typedef_node(curr.new_types, curr.type_identifier_top+1, curr.actual_type, next);
		next = (yyval.s.ast);
	}
#line 1832 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 300 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = NULL;
		next = NULL;
	}
#line 1841 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "parser_icg.y" /* yacc.c:1646  */
    {
	//	printf("\nVariable block action");
		(yyval.s.ast) = new_ast_var_node((yyvsp[0].s.ast));
	}
#line 1850 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 313 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = NULL;
	}
#line 1858 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 320 "parser_icg.y" /* yacc.c:1646  */
    {
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.s.str);
		//printf("In var decl: %s\n", var_name_stack[var_name_stack_top]);
		//printf("top of stack: %d\n", var_name_stack_top);
	}
#line 1869 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 327 "parser_icg.y" /* yacc.c:1646  */
    {
		char** new_vars = (char**)malloc(sizeof(char*)*10);

		for(int i = 0; i <= var_name_stack_top; i++)
		{
			new_vars[i] = strdup(var_name_stack[i]);
		}
		
		struct var_node_info new_var_entry;
		new_var_entry.new_vars = new_vars;
		new_var_entry.var_name_stack_top = var_name_stack_top;
		new_var_entry.data_type = last_type;
		var_node_stack[++var_node_stack_top] = new_var_entry;
	}
#line 1888 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 343 "parser_icg.y" /* yacc.c:1646  */
    {
		struct var_node_info curr = var_node_stack[var_node_stack_top--];
		(yyval.s.ast) = new_ast_vardef_node(curr.new_vars, curr.var_name_stack_top+1, curr.data_type, next);
		next = (yyval.s.ast);
	}
#line 1898 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 348 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = NULL;
		next = NULL;
	}
#line 1907 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 358 "parser_icg.y" /* yacc.c:1646  */
    {
		//printf("Hit the type part of line %s\n", yylval.s.type);
		last_type = yylval.s.type;
		int result = dump_stack_in_symbol_table(yylval.s.type, yylloc.first_line, yylloc.first_column);
		if(!result){
			//printf("DumpBck in Variable: %d\n",result);
			yyerror("Abort: Variable already declared.");
			exit(1);
		}

	}
#line 1923 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 370 "parser_icg.y" /* yacc.c:1646  */
    {
		struct type_table *t = NULL;
		HASH_FIND_STR(TYPE_TABLE,yylval.s.str,t);
		//printf("\nTypeSeen:%s and t:%s\n",t->user_defined_name,t);
		if(t)
		{
			last_type = yylval.s.str;
			int result = dump_stack_in_symbol_table(t->actual_type_name, yylloc.first_line, yylloc.first_column);
			if(!result){
			yyerror("Abort: Variable already declared.");
			exit(1);
			}
		}
		else
		{
			printf("Alert : Type %s is not defined.",yylval.s.str);
			YYABORT;
		}

	}
#line 1948 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 391 "parser_icg.y" /* yacc.c:1646  */
    {
		//printf("Hit the type part of line %s\n", yylval.s.type);
		last_type = yylval.s.type;
		int result = dump_stack_in_symbol_table("array", yylloc.first_line, yylloc.first_column);
		if(!result){
			//printf("DumpBck in Variable: %d\n",result);
			yyerror("Abort: Variable already declared.");
			exit(1);
		}

	}
#line 1964 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 407 "parser_icg.y" /* yacc.c:1646  */
    {
		type_identifier_top++;
		type_identifier_stack[type_identifier_top] = strdup(yylval.s.str);
	}
#line 1973 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 416 "parser_icg.y" /* yacc.c:1646  */
    {
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.s.str);
		//printf("In var decl: %s\n", var_name_stack[var_name_stack_top]);
		//printf("top of stack: %d\n", var_name_stack_top);
	}
#line 1984 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 433 "parser_icg.y" /* yacc.c:1646  */
    {
		curr_scope_level = strdup(yylval.s.str);
		printf("Entering the Procedure %s\n", curr_scope_level);
		++ast_func_or_proc_list_top;
		ast_func_or_proc_list[ast_func_or_proc_list_top] = (struct ast_func_or_proc_node*) new_ast_func_or_proc_node(curr_scope_level);
	}
#line 1995 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 441 "parser_icg.y" /* yacc.c:1646  */
    {
		curr_scope_level = strdup(yylval.s.str);
		printf("Entering the Procedure %s\n", curr_scope_level);
		++ast_func_or_proc_list_top;
		ast_func_or_proc_list[ast_func_or_proc_list_top] = (struct ast_func_or_proc_node*) new_ast_func_or_proc_node(curr_scope_level);
	}
#line 2006 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 458 "parser_icg.y" /* yacc.c:1646  */
    {
		curr_scope_level = strdup(yylval.s.str);
		printf("Entering the Function %s\n", curr_scope_level);
		++ast_func_or_proc_list_top;
		ast_func_or_proc_list[ast_func_or_proc_list_top] = (struct ast_func_or_proc_node*) new_ast_func_or_proc_node(curr_scope_level);
	}
#line 2017 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 465 "parser_icg.y" /* yacc.c:1646  */
    {
		strcpy(curr_scope_level,"global");

	}
#line 2026 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 470 "parser_icg.y" /* yacc.c:1646  */
    {
		curr_scope_level = strdup(yylval.s.str);
		++ast_func_or_proc_list_top;
		ast_func_or_proc_list[ast_func_or_proc_list_top] = (struct ast_func_or_proc_node*) new_ast_func_or_proc_node(curr_scope_level);
	}
#line 2036 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 476 "parser_icg.y" /* yacc.c:1646  */
    {
		char s[10] = "global";
		curr_scope_level = strdup(s);
	}
#line 2045 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 484 "parser_icg.y" /* yacc.c:1646  */
    {
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.s.str);
	}
#line 2054 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 489 "parser_icg.y" /* yacc.c:1646  */
    {
	int result = dump_stack_in_symbol_table(yylval.s.type, yylloc.first_line, yylloc.first_column);
	if(!result){
			yyerror("Abort: Variable already declared.");
			exit(1);
		}
	}
#line 2066 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 506 "parser_icg.y" /* yacc.c:1646  */
    {
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.s.str);
	}
#line 2075 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 515 "parser_icg.y" /* yacc.c:1646  */
    {
//		ast_func_or_proc_list[ast_func_or_proc_list_top]->var_body;
		ast_func_or_proc_list[ast_func_or_proc_list_top]->exec_body = (yyvsp[0].s.ast);
	}
#line 2084 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 522 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[-1].s.ast);}
#line 2090 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 526 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = new_ast_exec_body_node((yyvsp[-1].s.ast),(yyvsp[0].s.ast));}
#line 2096 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 527 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = NULL;}
#line 2102 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 531 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) =(yyvsp[0].s.ast);}
#line 2108 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 532 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2114 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 533 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2120 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 537 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2126 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 538 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) =(yyvsp[0].s.ast);}
#line 2132 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 542 "parser_icg.y" /* yacc.c:1646  */
    {lab1();}
#line 2138 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 542 "parser_icg.y" /* yacc.c:1646  */
    {lab2();}
#line 2144 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 543 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.ast) = new_ast_if_node((yyvsp[-6].s.ast),(yyvsp[-3].s.ast),(yyvsp[-2].s.ast));
	}
#line 2152 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 549 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2158 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 550 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast); lab3();}
#line 2164 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 551 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = NULL;}
#line 2170 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 555 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2176 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 559 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2182 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 563 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = NULL;}
#line 2188 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 564 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = (yyvsp[0].s.ast);}
#line 2194 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 568 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = new_ast_while_node((yyvsp[-3].s.ast),(yyvsp[0].s.ast));}
#line 2200 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 580 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast)=new_ast_write_node((yyvsp[-2].s.str));}
#line 2206 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 584 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = new_ast_assignment_stmts_node((yyvsp[-2].s.ast),(yyvsp[0].s.ast));}
#line 2212 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 585 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.ast) = NULL;}
#line 2218 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 590 "parser_icg.y" /* yacc.c:1646  */
    {
push(yylval.s.str);
		//printf("Variable Being Checked : %s ",yylval.s.str);
		if(!check_valid_identifier(yylval.s.str)){
			char error[1000];
			//printf("Scope Level : %s ",curr_scope_level);
			sprintf(error,"Abort: Variable %s is not declared.",yylval.s.str);
			yyerror(error);
			exit(1);
		}
		else
		{
			assignment_name_stack_top++;
			assignment_name_stack[assignment_name_stack_top] = strdup(yylval.s.str);
			
		}
	}
#line 2240 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 608 "parser_icg.y" /* yacc.c:1646  */
    {
codegen_assign();
		struct symbol_table *symbol_node = get_symbol_node((yyvsp[-3].s.str),curr_scope_level);
		(yyval.s.ast) = new_ast_assignment_node(symbol_node,(yyvsp[-2].s.ast));
	}
#line 2250 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 617 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.intval) = (yyvsp[0].s.intval);
		(yyval.s.ast) = new_ast_number_node((yyvsp[0].s.intval));
		//printf("Its here %d and %d and %d and %d and %d\n",$<s.intval>$,var_type_information.is_int,var_type_information.is_float,var_type_information.is_bool,var_type_information.is_str );
		if(!is_rel_op){
			set_variable_to_int(assignment_name_stack,assignment_name_stack_top, (yyvsp[0].s.intval),curr_scope_level);
			var_type_info_top++;
			var_type_info_stack[var_type_info_top] = var_type_information;
			clear_variable_type_info(&var_type_information);
		}
		
	}
#line 2267 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 630 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.floatval) = (yyvsp[0].s.floatval);
		(yyval.s.ast) = NULL;
		//printf("Its here %f and %d and %d and %d and %d\n",$<s.floatval>1,var_type_information.is_int,var_type_information.is_float,var_type_information.is_bool,var_type_information.is_str );
		if(!is_rel_op){
			set_variable_to_float(assignment_name_stack,assignment_name_stack_top, (yyvsp[0].s.floatval),curr_scope_level);
			var_type_info_top++;
			var_type_info_stack[var_type_info_top] = var_type_information;
			clear_variable_type_info(&var_type_information);
		}
	}
#line 2283 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 642 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.intval) = (yyvsp[0].s.intval);
		(yyval.s.ast) = NULL;
		if(!is_rel_op){
			set_variable_to_int(assignment_name_stack,assignment_name_stack_top, (yyvsp[0].s.intval),curr_scope_level);
			var_type_info_top++;
			var_type_info_stack[var_type_info_top] = var_type_information;
			clear_variable_type_info(&var_type_information);
		}
		
	}
#line 2299 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 654 "parser_icg.y" /* yacc.c:1646  */
    {
		(yyval.s.str) = (yyvsp[0].s.str);
		(yyval.s.ast) = NULL;
		if(!is_rel_op){
			set_variable_to_string(assignment_name_stack,assignment_name_stack_top, (yyvsp[0].s.str),curr_scope_level);
			var_type_info_top++;
			var_type_info_stack[var_type_info_top] = var_type_information;
			clear_variable_type_info(&var_type_information);
		}
		
		
	}
#line 2316 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 670 "parser_icg.y" /* yacc.c:1646  */
    {
push(yylval.s.str);
		if(check_valid_identifier(yylval.s.str)){
			union data variable_value = get_identifier_data(yylval.s.str);
			struct variable_type_info id_type = get_identifier_type(yylval.s.str);
			//printf("Its here in ID and %d and %d and %d and %d\n",id_type.is_int,id_type.is_float,id_type.is_bool,id_type.is_str );
			var_type_info_top++;
			var_type_info_stack[var_type_info_top] = id_type;
			if(id_type.is_int && !(id_type.is_float) && !(id_type.is_str) && !(id_type.is_bool)){
				(yyval.s.intval) = variable_value.int_value;
			}
			else
			if(!(id_type.is_int) && (id_type.is_float) && !(id_type.is_str) && !(id_type.is_bool)){
				(yyval.s.floatval) = variable_value.float_value;
			}
			else
			if(!(id_type.is_int) && !(id_type.is_float) && (id_type.is_str) && !(id_type.is_bool)){
				strcpy((yyval.s.str),variable_value.string_value);
			}
			else
			if(!(id_type.is_int) && !(id_type.is_float) && !(id_type.is_str) && (id_type.is_bool)){
				(yyval.s.intval) = variable_value.int_value;
			}
			struct symbol_table *symbol_node = get_symbol_node(yylval.s.str,curr_scope_level);
			(yyval.s.ast) = new_ast_symbol_reference_node(symbol_node);
		}
	}
#line 2348 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 698 "parser_icg.y" /* yacc.c:1646  */
    {
push_i(yylval.s.intval);
		(yyval.s.ast) = (yyvsp[0].s.ast);
		(yyval.s.intval) = (yyvsp[0].s.intval);
	}
#line 2358 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 703 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.intval) = (yyvsp[-1].s.intval);(yyval.s.ast) = (yyvsp[-1].s.ast);}
#line 2364 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 705 "parser_icg.y" /* yacc.c:1646  */
    {
		struct variable_type_info st1,st2;
		st1 = var_type_info_stack[var_type_info_top-1];
		st2 = var_type_info_stack[var_type_info_top];
		if(st1.is_int && st2.is_int){
			//printf("%d and %d and %s\n",$<s.intval>1,$<s.intval>3,$<s.str>2);
			(yyval.s.intval) = solution((yyvsp[-2].s.intval),(yyvsp[0].s.intval),(yyvsp[-1].s.str));
			set_variable_to_int(assignment_name_stack,assignment_name_stack_top, (yyval.s.intval),curr_scope_level);

		}
		else
		if(st1.is_int && st2.is_float){
			printf("Warning : Trying to Add Real and Integer. Converting Real to Integer\n");
			//printf("%d and %f and %s\n",$<s.intval>1,$<s.floatval>3,$<s.str>2);
			(yyval.s.intval) = solution((yyvsp[-2].s.intval),(int)(yyvsp[0].s.floatval),(yyvsp[-1].s.str));
			set_variable_to_int(assignment_name_stack,assignment_name_stack_top, (yyval.s.intval),curr_scope_level);
		}
		else
		if(st1.is_int && st2.is_bool){
			yyerror("Abort: Incompatible Datatypes.");
			exit(1);
		}
		else
		if(st1.is_int && st2.is_str){
			yyerror("Abort: Incompatible Datatypes.");
			exit(1);
		}
		else
		if(st1.is_float && st2.is_int){
			printf("Warning : Trying to Add Integer and Real. Converting Real to Integer\n");
			//printf("%f and %d and %s\n",$<s.floatval>1,$<s.intval>3,$<s.str>2);
			(yyval.s.intval) = solution((int)(yyvsp[-2].s.floatval),(int)(yyvsp[0].s.intval),(yyvsp[-1].s.str));
			set_variable_to_int(assignment_name_stack,assignment_name_stack_top, (yyval.s.intval),curr_scope_level);
		}
		else{
			yyerror("Abort: Incompatible Datatypes.");
			exit(1);
		}
		(yyval.s.ast) = new_ast_node((yyvsp[-1].s.str),(yyvsp[-2].s.ast),(yyvsp[0].s.ast));
	}
#line 2409 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 747 "parser_icg.y" /* yacc.c:1646  */
    {codegen();}
#line 2415 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 748 "parser_icg.y" /* yacc.c:1646  */
    {
		is_rel_op = 1;
	}
#line 2423 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 754 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str) = (yyvsp[0].s.str);}
#line 2429 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 759 "parser_icg.y" /* yacc.c:1646  */
    {push("=");}
#line 2435 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 763 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str)=strdup("+");}
#line 2441 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 764 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str)=strdup("*");}
#line 2447 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 765 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str)=strdup("/");}
#line 2453 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 766 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str)=strdup("-");}
#line 2459 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 767 "parser_icg.y" /* yacc.c:1646  */
    {(yyval.s.str)=strdup("%");}
#line 2465 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push("=");}
#line 2471 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push(">");}
#line 2477 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push("<");}
#line 2483 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push("<=");}
#line 2489 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push(">=");}
#line 2495 "parser_icg.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 771 "parser_icg.y" /* yacc.c:1646  */
    {push("!=");}
#line 2501 "parser_icg.tab.c" /* yacc.c:1646  */
    break;


#line 2505 "parser_icg.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 788 "parser_icg.y" /* yacc.c:1906  */



char st[100][10];
int top=0;
char i_[2]="0";
char temp[2]="t";

int label[20];
int lnum=0;
int ltop=0;

 push(char *str)
 {
  strcpy(st[++top],str);
 }
 push_i(int val)
 {
  sprintf(st[++top], "%d", val);
 }
 codegen()
 {
 strcpy(temp,"t");
 strcat(temp,i_);
  printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
  top-=2;
 strcpy(st[top],temp);
 i_[0]++;
 }

 codegen_umin()
 {
 strcpy(temp,"t");
 strcat(temp,i_);
 printf("%s = -%s\n",temp,st[top]);
 top--;
 strcpy(st[top],temp);
 i_[0]++;
 }

 codegen_assign()
 {
 printf("%s = %s\n",st[top-2],st[top]);
 top-=2;
 }

 lab1()
{
 lnum++;
 strcpy(temp,"t");
 strcat(temp,i_);
 printf("%s = not %s\n",temp,st[top]);
 printf("if %s goto L%d\n",temp,lnum);
 i_[0]++;
 label[++ltop]=lnum;
}

 lab2()
{
int x;
lnum++;
x=label[ltop--];
printf("goto L%d\n",lnum);
printf("L%d: \n",x);
label[++ltop]=lnum;
}

 lab3()
{
int y;
y=label[ltop--];
printf("L%d: \n",y);
}

int yyerror(const char *message) {
	printf("\n\nInvalid Syntax:%d:%d Reason being %s\n",yylloc.first_line,yylloc.first_column,message);
	printf("Compilation Failed\n");
	successful=0;
	return 0;
}



int main(int argc,char* argv[]) {
	struct timespec start;
	struct timespec end;

	if (argc>1) {
		yyin = fopen(argv[1],"r");
		if(yyin == NULL) {
			perror("Error ");
			exit(1);
		}
	}
	else {
		yyin = stdin;
	}

	char extension[8] = ".output";
	char outputfile[40] = "output/";

	/*To Create Output File*/
	char *ptr = strtok(argv[1], "/");
	char *inputfile; 
	while(ptr != NULL)
	{
		inputfile = strdup(ptr);
		ptr = strtok(NULL, "/");
	}

	strcat(outputfile,inputfile);
	strcat(outputfile,extension);

	yyout = (FILE*)fopen(outputfile,"w+");
	/*End Create Output File*/
	clear_variable_type_info(&var_type_information);
	print_figlet();
	print_license();

	clock_gettime(CLOCK_REALTIME, &start);
	yyparse();
	clock_gettime(CLOCK_REALTIME, &end);
	if(successful){
		printf("\n\nCompiled Successfully\n");
		printf("Took : %lf seconds\n", time_elapsed(&start, &end));

		printf("\n\nSymbol Table Current Size:%d\n",HASH_COUNT(SYMBOL_TABLE));

		struct symbol_table *s;
		int i=0;
	    for(s=SYMBOL_TABLE,i=0; s != NULL,i<HASH_COUNT(SYMBOL_TABLE); s=s->hh.next,i++) {

	    	if(strcmp(s->type,"string")==0){
					printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d Value:%-10s\n",i,s->var_name,s->type, s->scope_level, s->line_no, s->col_no, s->var_value.string_value );
				}
				else if(strcmp(s->type,"integer")==0){
					printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d Value:%-10d\n",i,s->var_name,s->type, s->scope_level, s->line_no, s->col_no, s->var_value.int_value );
				}
				else if(strcmp(s->type,"real")==0){
					printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d Value:%-10f\n",i,s->var_name,s->type, s->scope_level, s->line_no, s->col_no, s->var_value.float_value );
				}
				else if(strcmp(s->type,"boolean")==0){
					printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d Value:%-10d\n",i,s->var_name,s->type, s->scope_level, s->line_no, s->col_no, s->var_value.int_value );
				}
				else {
					printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d Value:%-10s\n",i,s->var_name,s->type, s->scope_level, s->line_no, s->col_no, s->var_value.string_value );
				}

	        //printf("Index : %-10d\t Identifier : %-20s\t DataType : %-20s\t ScopeLevel : %-20s\t Line_no : %-10d\t Col_no : %-10d\n",i,s->var_name,s->type, //s->scope_level, s->line_no, s->col_no, s->var_value );
				

	    }
	//    printf("\n\nPrinting the Abstract Syntax Tree : \n\n");
	//	print_tree(tree);



		/*Intermediate Code Generation*/
		char *icg_file = strtok(inputfile,".");
		char outputicg[40] = "intermediate_code/";
		strcat(outputicg,icg_file);
		strcat(outputicg,".icg");
		FILE *fp = fopen(outputicg,"w+");
		//generate_icg(&fp);
		fclose(fp);
		printf("\n\nIntermediate Code is Generated at:%s\n",outputicg);

	}


    /*  TYPE BLOCK
    struct type_table *t;
	i=0;
    for(t=TYPE_TABLE,i=0; t != NULL,i<HASH_COUNT(TYPE_TABLE); t=t->hh.next,i++) {
        printf("Index : %d\t Identifier : %s\t DataType : %s\n",i,t->user_defined_name,t->actual_type_name);
    }*/
}

void set_variable_to_int(char **assignment_name_stack,int assignment_name_stack_top, int int_value,char* curr_scope_level) {
		if (assignment_name_stack_top == -1)
	{
		return;
	}
		
		struct symbol_table *s = NULL;
		char var_mang_name[31];
		strcpy(var_mang_name, assignment_name_stack[assignment_name_stack_top]);
		strcat(var_mang_name, "$");
		strcat(var_mang_name, curr_scope_level);
		HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
		if(s)
		{
			struct symbol_table *temp = NULL;
			struct symbol_table *r = NULL;
			temp = malloc(sizeof(struct symbol_table));
			strcat(temp->var_name, var_mang_name);
			strcpy(temp->type, s->type);
			temp->scope_level = s->scope_level;
			temp->line_no = s->line_no;
			temp->col_no = s->col_no;
			temp->var_value.int_value = int_value;
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
}

void set_variable_to_float(char **assignment_name_stack,int assignment_name_stack_top, float float_value,char* curr_scope_level) {
		if (assignment_name_stack_top == -1)
	{
		return;
	}
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, assignment_name_stack[assignment_name_stack_top]);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	if(s)
	{
		struct symbol_table *temp = NULL;
		struct symbol_table *r = NULL;
		temp = malloc(sizeof(struct symbol_table));
		strcat(temp->var_name, var_mang_name);
		strcpy(temp->type, s->type);
		temp->scope_level = s->scope_level;
		temp->line_no = s->line_no;
		temp->col_no = s->col_no;
		temp->var_value.float_value = float_value;
		HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
	}
}

void set_variable_to_string(char **assignment_name_stack,int assignment_name_stack_top, char *string_value,char* curr_scope_level){
	if (assignment_name_stack_top == -1)
	{
		return;
	}
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, assignment_name_stack[assignment_name_stack_top]);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	if(s)
	{
		struct symbol_table *temp = NULL;
		struct symbol_table *r = NULL;
		temp = malloc(sizeof(struct symbol_table));
		strcat(temp->var_name, var_mang_name);
		strcpy(temp->type, s->type);
		temp->scope_level = s->scope_level;
		temp->line_no = s->line_no;
		temp->col_no = s->col_no;
		strcpy(temp->var_value.string_value,string_value);
		HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
	}
}

int dump_stack_in_symbol_table(char *type, int line_no, int col_no) {
		for(int i = 0; i <= var_name_stack_top; i++)
		{
			struct symbol_table *s = NULL;
			char var_mang_name[31];
			strcpy(var_mang_name, var_name_stack[i]);
			strcat(var_mang_name, "$");
			strcat(var_mang_name, curr_scope_level);
			HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
			if(!s)
			{
				printf("Alert : Inserting Variable '%s' in to the Symbol Table.\n", var_mang_name);
				s = malloc(sizeof(struct symbol_table));
				strcpy(s->var_name, var_mang_name);
				strcpy(s->type, type);
				//printf("Type : %d\n",strcmp(type,"integer"));
				s->scope_level = strdup(curr_scope_level);
				s->line_no = line_no;
				s->col_no = col_no;
				if(strcmp(type,"string")==0){

					strcpy(s->var_value.string_value, "");
				}
				else if(strcmp(type,"integer")==0){
					s->var_value.int_value = 0;
				}
				else if(strcmp(type,"real")==0){
					s->var_value.float_value = 0.0;
				}
				else if(strcmp(type,"boolean")==0){
					s->var_value.int_value = 0;
				}
				else if(strcmp(type,"array")==0){
					strcpy(s->var_value.string_value, "00000x54");
				}
				HASH_ADD_STR( SYMBOL_TABLE, var_name, s );  /* var_name: name of key field */
				//SYMBOL_TABLE->current_size++;
			}
			else
			{
				printf("Error : Variable '%s' already declared with '%s' type.\n",s->var_name, s->type);
				return 0;
			}
			var_name_stack[i] = NULL;
		}
		var_name_stack_top = -1;
		return 1;
	}
int check_valid_identifier(char* var_name){
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, var_name);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	if(!s)
		return 0;
	return 1;

}

struct symbol_table *get_symbol_node(char *var_name,char *curr_scope_level) {
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, var_name);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	return s;
}

union data get_identifier_data(char *var_name){
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, var_name);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	return s->var_value;
}

struct variable_type_info get_identifier_type(char *var_name){
	struct variable_type_info retval;
	struct symbol_table *s = NULL;
	char var_mang_name[31];
	strcpy(var_mang_name, var_name);
	strcat(var_mang_name, "$");
	strcat(var_mang_name, curr_scope_level);
	HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
	if(strcmp(s->type,"integer")==0){
		retval.is_int = 1;
		retval.is_float = 0;
		retval.is_str = 0;
		retval.is_bool = 0;
	}
	else
	if(strcmp(s->type,"real")==0){
		retval.is_int = 0;
		retval.is_float = 1;
		retval.is_str = 0;
		retval.is_bool = 0;
	}
	else
	if(strcmp(s->type,"string")==0){
		retval.is_int = 0;
		retval.is_float = 0;
		retval.is_str = 1;
		retval.is_bool = 0;
	}
	else
	if(strcmp(s->type,"boolean")==0){
		retval.is_int = 0;
		retval.is_float = 0;
		retval.is_str = 0;
		retval.is_bool = 1;
	}
	return retval;
}



int solution(int a,int b, char* operator) {
	int result;
	if(strcmp(operator,"+")==0)
	{
		result = a+b;

	}
	if(strcmp(operator,"*")==0)
	{
		result = a*b;

	}
	if(strcmp(operator,"/")==0)
	{
		result = a/b;

	}
	if(strcmp(operator,"-")==0)
	{
		result = a-b;

	}
	if(strcmp(operator,"%")==0)
	{
		result = a%b;

	}
	return result;
}
