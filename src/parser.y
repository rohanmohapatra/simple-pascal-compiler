%{
	#include<stdio.h>
	#include <time.h> //link with -lrt
	#include <string.h>
	#include "../uthash/src/uthash.h"
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
	int successful=1;
    int yyerror();
    extern FILE *yyin;
    extern FILE *yyout;
    double time_elapsed(struct timespec *start, struct timespec *end);
    int yylex(void);
    //struct typeDefinitionCell {
    //
    //}
	char *var_name_stack[10];
	int var_name_stack_top = -1;
	
	char *curr_scope_level = "global";
	// struct var_info {
	// 	char var_name[31];
	// 	// YYLTYPE var_decl_loc;
	// 	char type[10];
	// 	int scope_level;
	// };

	struct symbol_table {
		char var_name[31]; //Holds the Name of the Identifier
		// struct var_info var;
		// YYLTYPE var_decl_loc;
		char type[10]; //Holds the DataType of Identifier
		char *scope_level;
		//int current_size; //Size of the Symbol Table
		UT_hash_handle hh; //Hash Structure for Optimized Access
	};

	struct symbol_table *SYMBOL_TABLE = NULL; /*Generic Symbol Table*/
%}
%locations
%union {
	char *str;
	char *type;
	int intval;
	float floatval;
}

%start startPascal

%token T_USES 
%token T_WHILE
%token T_PROGRAM
%token T_VAR
%token T_TYPE
%token T_IF
%token T_BEGIN
%token T_END
%token T_CONST
%token T_WRITELN
%token T_PROCEDURE
%token T_FUNCTION
%token T_FOR
%token T_DO
%token T_TO
%token T_DOWNTO

%token T_BOOL_AND
%token T_BOOL_OR
%token T_BOOL_NOT

%token T_REL_LE
%token T_REL_GE
%token T_REL_NE
%token T_SINGLEEQ

%token T_BIT_LS
%token T_BIT_RS

%token T_ASOP
%token T_AS_PE
%token T_AS_SE
%token T_AS_MULE
%token T_AS_DIVE

%token T_ARRAY
%token <str> T_IDENTIFIER
%token <type> T_DATATYPE

%token <intval> T_INTVAL
%token <floatval> T_FLOATVAL
%token <intval> T_BOOLVAL
%token <str> T_STRINGVAL

%%
startPascal:
	 program
;

program:
	prog_heading block '.'
;

prog_heading:
	T_PROGRAM T_IDENTIFIER ';' 
;

block:
	uses_block constant_block type_block variable_block function_and_procedure_block execution_block
;

uses_block:
	T_USES T_IDENTIFIER more_libs ';'  | epsilon
;

more_libs:
	',' T_IDENTIFIER more_libs | epsilon
;

constant_block:
	T_CONST  const_definition | epsilon 
;

const_definition:
	T_IDENTIFIER T_SINGLEEQ some_numeric_type ';'  more_const_definition
;

more_const_definition:
	T_IDENTIFIER T_SINGLEEQ some_numeric_type ';'  more_const_definition | epsilon
;

type_block:
	T_TYPE  type_definition | epsilon
;

type_definition:
	T_IDENTIFIER more_type_identifiers T_SINGLEEQ T_DATATYPE ';'  type_definition | epsilon
;	

variable_block:
	T_VAR  variable_declaration | epsilon
;

variable_declaration:
	T_IDENTIFIER 
	{
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.str);
		//printf("In var decl: %s\n", var_name_stack[var_name_stack_top]);
		//printf("top of stack: %d\n", var_name_stack_top);
	}
	more_var_identifiers ':' T_DATATYPE
	{
		//printf("Hit the type part of line %s\n", yylval.type);
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
				strcat(s->var_name, var_mang_name);
				strcpy(s->type, yylval.type);
				s->scope_level = strdup(curr_scope_level);
				HASH_ADD_STR( SYMBOL_TABLE, var_name, s );  /* var_name: name of key field */
				//SYMBOL_TABLE->current_size++;
			}
			else
			{
				printf("Warning : Variable '%s' already declared with '%s' type.\n",s->var_name, s->type);
			}
			var_name_stack[i] = NULL;
		}
		var_name_stack_top = -1;

	}
	';'  variable_declaration
	| epsilon
;

more_type_identifiers:
	',' T_IDENTIFIER more_type_identifiers | epsilon
;

more_var_identifiers:
	',' T_IDENTIFIER
	{
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.str);
		//printf("In var decl: %s\n", var_name_stack[var_name_stack_top]);
		//printf("top of stack: %d\n", var_name_stack_top);
	}
	more_var_identifiers | epsilon
;

function_and_procedure_block:
	function_block function_and_procedure_block 
	| procedure_block function_and_procedure_block 
	| epsilon
;

procedure_block:
	T_PROCEDURE T_IDENTIFIER
	{
		curr_scope_level = strdup(yylval.str);
		printf("Entering the procedure %s\n", curr_scope_level);
	}
	';'  block ';'
	| T_PROCEDURE T_IDENTIFIER '(' param_list ')' ';'  block ';'
;

param_list:
	T_IDENTIFIER ':' T_DATATYPE 
	| T_IDENTIFIER ':' T_DATATYPE ';' param_list
	| epsilon
;

function_block:
	T_FUNCTION T_IDENTIFIER
	{
		curr_scope_level = strdup(yylval.str);
		printf("Entering the function %s\n", curr_scope_level);
	}
	':' T_DATATYPE ';'  block ';'
	| T_FUNCTION T_IDENTIFIER 
	{
		curr_scope_level = strdup(yylval.str);
		printf("Entering the function %s\n", curr_scope_level);
	}
	'(' function_param_list ')' ':' T_DATATYPE ';'  block ';' 
;

function_param_list:
	T_IDENTIFIER more_func_identifiers ':' T_DATATYPE
	| T_IDENTIFIER more_func_identifiers ':' T_DATATYPE ';' function_param_list
;

more_func_identifiers:
	',' T_IDENTIFIER more_func_identifiers | epsilon
;

execution_block:
	T_BEGIN execution_body  T_END 
;	

execution_body:
	assignment_statements execution_body
	| print_statements execution_body
	| structured_statements execution_body
	| epsilon
;

structured_statements:
	conditional_statement ';'
	| repetitive_statement
;

conditional_statement:
;

repetitive_statement:
	for_statement | while_statement
;

while_statement :
	T_WHILE expression T_DO execution_body
;

for_statement:
	T_FOR T_IDENTIFIER T_ASOP for_list T_DO execution_body

for_list:
	expression T_TO expression 
	| expression T_DOWNTO expression
;

print_statements:
	T_WRITELN '(' T_STRINGVAL ')' ';'
;

assignment_statements:
	assignment_statement ';'  assignment_statements
	| epsilon
;

assignment_statement:
	T_IDENTIFIER assignment_ops expression
;

value:
	T_INTVAL | T_FLOATVAL | T_BOOLVAL | T_STRINGVAL
;

expression:
	T_IDENTIFIER
	| value
	| '(' expression ')'
	| expression operator expression

operator:
	arithmetic_ops|relational_ops|boolean_ops|bitwise_ops
;

assignment_ops:
	T_ASOP | T_AS_PE | T_AS_SE | T_AS_MULE | T_AS_DIVE
;

arithmetic_ops:
	'+'|'*'|'/'|'-'|'%'
;

relational_ops:
	T_SINGLEEQ|'>'|'<'|T_REL_LE|T_REL_GE|T_REL_NE
;

boolean_ops:
	T_BOOL_AND|T_BOOL_OR|T_BOOL_NOT
;

bitwise_ops:
	'&'|'|'|'~'|'!'|T_BIT_LS|T_BIT_RS

some_numeric_type:
	T_INTVAL | T_FLOATVAL
;

epsilon:
;

%%

int yyerror() {
	printf("Invalid Syntax:%d:%d\n",yylloc.first_line,yylloc.first_column);
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

	clock_gettime(CLOCK_REALTIME, &start);
	yyparse();
	clock_gettime(CLOCK_REALTIME, &end);
	if(successful){
		printf("Compiled Successfully\n");
		printf("Took : %lf seconds\n", time_elapsed(&start, &end));
	}
	printf("Symbol Table Current Size:%d\n",HASH_COUNT(SYMBOL_TABLE));

	struct symbol_table *s;
	int i=0;
    for(s=SYMBOL_TABLE,i=0; s != NULL,i<HASH_COUNT(SYMBOL_TABLE); s=s->hh.next,i++) {
        printf("Index : %d\t Identifier : %s\t DataType : %s\t ScopeLevel : %s\n",i,s->var_name,s->type, s->scope_level);
    }
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
