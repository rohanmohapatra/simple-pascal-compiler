%{
	#include<stdio.h>
	#include<stdlib.h>
	#include <time.h> //link with -lrt
	#include <string.h>
	#include "../uthash/src/uthash.h"
	#include "ast_handle.h"
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
	int successful=1;
    int yyerror();
    extern FILE *yyin;
    extern FILE *yyout;
    double time_elapsed(struct timespec *start, struct timespec *end);
    int yylex(void);

	char *var_name_stack[10];
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

	union data {
		int int_value;
		float float_value;
		char string_value[256];
	};

	struct symbol_table {
		char var_name[31]; //Holds the Name of the Identifier
		// struct var_info var;
		// YYLTYPE var_decl_loc;
		char type[10]; //Holds the DataType of Identifier
		char *scope_level;
		//int current_size; //Size of the Symbol Table
		int line_no;
		int col_no;
		union data var_value;
		UT_hash_handle hh; //Hash Structure for Optimized Access
	};


	struct symbol_table *SYMBOL_TABLE = NULL; /*Generic Symbol Table*/

	char *type_identifier_stack[10];
	int type_identifier_top = -1;
	struct type_table{
		char user_defined_name[31];
		char actual_type_name[31];
		UT_hash_handle hh;
	};
	struct type_table *TYPE_TABLE = NULL;

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
				strcat(s->var_name, var_mang_name);
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
	union data get_identifier_data(char *var_name){
		struct symbol_table *s = NULL;
		char var_mang_name[31];
		strcpy(var_mang_name, var_name);
		strcat(var_mang_name, "$");
		strcat(var_mang_name, curr_scope_level);
		HASH_FIND_STR(SYMBOL_TABLE, var_mang_name, s);
		return s->var_value;
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
	//int update_variable_value(char* var_name,union data )


%}
%locations
%union {
	char *str;
	char *type;
	int intval;
	float floatval;
	struct ast_node * ast;
}

%start startPascal

%token T_USES 
%token T_WHILE
%token T_PROGRAM
%token T_VAR
%token T_TYPE
%token T_IF
%token T_THEN
%token T_ELSE
%token T_BEGIN
%token T_END
%token T_CONST
%token T_WRITELN
%token T_PROCEDURE
%token T_FUNCTION
%token T_FOR
%token T_DO
%token T_TO
%token T_OF
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

%token T_INDEXTYPE
%token <str> T_IDENTIFIER
%token <type> T_DATATYPE

%token <intval> T_INTVAL
%token <floatval> T_FLOATVAL
%token <intval> T_BOOLVAL
%token <str> T_STRINGVAL

%define parse.error verbose
%left '+' '-'
%left '*' '/'
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
	T_IDENTIFIER 
	{
		type_identifier_top++;
		type_identifier_stack[type_identifier_top] = strdup(yylval.str);
	}
	more_type_identifiers T_SINGLEEQ T_DATATYPE 
	{
		for(int i = 0; i <= type_identifier_top; i++)
		{
			struct type_table *s = NULL;
			HASH_FIND_STR(TYPE_TABLE, type_identifier_stack[i], s);
			if(!s)
			{
				s = malloc(sizeof(struct type_table));
				strcpy(s->user_defined_name, type_identifier_stack[i]);
				strcpy(s->actual_type_name, yylval.type);
				HASH_ADD_STR( TYPE_TABLE, user_defined_name, s );  /* var_name: name of key field */
			}
			else
			{
				YYABORT;
			}
			type_identifier_stack[i] = NULL;
		}
		type_identifier_top = -1;
	}
	';'  type_definition | epsilon
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
	more_var_identifiers ':' data_type ';'  variable_declaration
	| epsilon
;

data_type:
	T_DATATYPE
	
	{
		//printf("Hit the type part of line %s\n", yylval.type);
		int result = dump_stack_in_symbol_table(yylval.type, yylloc.first_line, yylloc.first_column);
		if(!result){
			//printf("DumpBck in Variable: %d\n",result);
			yyerror("Abort: Variable already declared.");
			exit(1);
		}

	} 
	| T_IDENTIFIER 
	{
		struct type_table *t = NULL;
		HASH_FIND_STR(TYPE_TABLE,yylval.str,t);
		//printf("\nTypeSeen:%s and t:%s\n",t->user_defined_name,t);
		if(t)
		{
			int result = dump_stack_in_symbol_table(t->actual_type_name, yylloc.first_line, yylloc.first_column);
			if(!result){
			yyerror("Abort: Variable already declared.");
			exit(1);
			}
		}
		else
		{
			printf("Alert : Type %s is not defined.",yylval.str);
			YYABORT;
		}

	}
	| T_ARRAY '['T_INDEXTYPE']' T_OF T_DATATYPE
	{
		//printf("Hit the type part of line %s\n", yylval.type);
		int result = dump_stack_in_symbol_table("array", yylloc.first_line, yylloc.first_column);
		if(!result){
			//printf("DumpBck in Variable: %d\n",result);
			yyerror("Abort: Variable already declared.");
			exit(1);
		}

	}

;

more_type_identifiers:
	',' T_IDENTIFIER 
	{
		type_identifier_top++;
		type_identifier_stack[type_identifier_top] = strdup(yylval.str);
	}
	more_type_identifiers | epsilon
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
		printf("Entering the Procedure %s\n", curr_scope_level);
	}
	';'  block ';'
	| T_PROCEDURE T_IDENTIFIER 
	{
		curr_scope_level = strdup(yylval.str);
		printf("Entering the Procedure %s\n", curr_scope_level);
	}
	'(' param_list ')' ';'  block ';'
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
		printf("Entering the Function %s\n", curr_scope_level);
	}
	':' T_DATATYPE ';'  block ';' 
	{
		strcpy(curr_scope_level,"global");

	}
	| T_FUNCTION T_IDENTIFIER 
	{
		curr_scope_level = strdup(yylval.str);
	}
	'(' function_param_list ')' ':' T_DATATYPE ';'  block ';' 
	{
		char s[10] = "global";
		curr_scope_level = strdup(s);
	}
;

function_param_list:
	T_IDENTIFIER 
	{
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.str);
	}
	more_func_identifiers ':' T_DATATYPE 
	{
	int result = dump_stack_in_symbol_table(yylval.type, yylloc.first_line, yylloc.first_column);
	if(!result){
			yyerror("Abort: Variable already declared.");
			exit(1);
		}
	}
	function_param_continue
;

function_param_continue :
	epsilon
	| ';' function_param_list
;

more_func_identifiers:
	',' T_IDENTIFIER
	{
		var_name_stack_top++;
		var_name_stack[var_name_stack_top] = strdup(yylval.str);
	}
	more_func_identifiers | epsilon
;

execution_block:
	T_BEGIN execution_body T_END 
;	

execution_body:
	execution_body statements 
	| epsilon
;

statements : 
	assignment_statements
	| print_statements
	| structured_statements
;	

structured_statements:
	conditional_statement
	| repetitive_statement
;

conditional_statement:
	T_IF '(' boolean_expression ')' T_THEN execution_body if_then_follow
;

if_then_follow:
	else_if_block | else_block | epsilon
;

else_if_block:
	T_ELSE conditional_statement
;

else_block:
	T_ELSE execution_body
;

repetitive_statement:
	for_statement | while_statement
;

while_statement : 
	T_WHILE expression T_DO statements
;

for_statement:
	T_FOR T_IDENTIFIER T_ASOP for_list T_DO statements

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
	T_IDENTIFIER 
	{
		//printf("Variable Being Checked : %s ",yylval.str);
		if(!check_valid_identifier(yylval.str)){
			char error[1000];
			//printf("Scope Level : %s ",curr_scope_level);
			sprintf(error,"Abort: Variable %s is not declared.",yylval.str);
			yyerror(error);
			exit(1);
		}
		else
		{
			assignment_name_stack_top++;
			assignment_name_stack[assignment_name_stack_top] = strdup(yylval.str);
		}
	}
	assignment_ops expression 

	
;

value:
	T_INTVAL 
	{
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
			temp->var_value.int_value = yylval.intval;
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
	}
	| T_FLOATVAL 
	{
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
			temp->var_value.float_value = yylval.floatval;
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
	}
	| T_BOOLVAL 
	{
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
			temp->var_value.int_value = yylval.intval;
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
	}
	| T_STRINGVAL
	{
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
			strcpy(temp->var_value.string_value,yylval.str);
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
	}
;

expression:
	T_IDENTIFIER
	{
		if(check_valid_identifier(yyval.str)){
			union data variable_value = get_identifier_data(yylval.str);
			$<intval>$ = variable_value.int_value;
		}
	} 
	| value 
	| '(' expression ')' 
	| expression operator expression 
	{
		printf("%d and %d and %s\n",$<intval>1,$<intval>3,$<str>2);
		$<intval>$ = solution($<intval>1,$<intval>3,$<str>2);
		
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
			temp->var_value.int_value = $<intval>$;
			HASH_REPLACE_STR( SYMBOL_TABLE, var_name, temp,r );  /* var_name: name of key field */
		}
	}
;
boolean_expression:
	expression relational_ops expression
;

operator:
	arithmetic_ops {$<str>$ = $<str>1;}
	|relational_ops|boolean_ops|bitwise_ops
;

assignment_ops:
	T_ASOP | T_AS_PE | T_AS_SE | T_AS_MULE | T_AS_DIVE
;

arithmetic_ops:
	'+' {strcpy($<str>$,"+");}
	|'*' {strcpy($<str>$,"*");}
	|'/' {strcpy($<str>$,"/");}
	|'-' {strcpy($<str>$,"-");}
	|'%' {strcpy($<str>$,"%");}
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

	}
	

    /*  TYPE BLOCK
    struct type_table *t;
	i=0;
    for(t=TYPE_TABLE,i=0; t != NULL,i<HASH_COUNT(TYPE_TABLE); t=t->hh.next,i++) {
        printf("Index : %d\t Identifier : %s\t DataType : %s\n",i,t->user_defined_name,t->actual_type_name);
    }*/
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
