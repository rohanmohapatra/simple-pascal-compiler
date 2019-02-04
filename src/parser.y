%{
	#include<stdio.h>
	#include <time.h> //link with -lrt
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
	int successful=1;
    int yyerror();
    extern FILE *yyin;
    double time_elapsed(struct timespec *start, struct timespec *end);

    //struct typeDefinitionCell {
    //
    //}	
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

%token T_ARRAY
%token <str> T_IDENTIFIER
%token <type> T_DATATYPE

%token <intval> T_INTVAL
%token <floatval> T_FLOATVAL
%token <intval> T_BOOLVAL
%token <str> T_STRINGVAL

%%
startPascal:
	newlineOrNo program
;

program:
	prog_heading block 
;

prog_heading:
	T_PROGRAM T_IDENTIFIER ';' newlineOrNo
;

block:
	uses_block constant_block type_block variable_block //execution_block
;

uses_block:
	T_USES T_IDENTIFIER more_libs ';' newlineOrNo | epsilon
;

more_libs:
	',' T_IDENTIFIER more_libs | epsilon
;

constant_block:
	T_CONST onlyNewLine const_definition | epsilon 
;

const_definition:
	T_IDENTIFIER T_SINGLEEQ some_numeric_type ';' newlineOrNo more_const_definition
;

more_const_definition:
	T_IDENTIFIER T_SINGLEEQ some_numeric_type ';' newlineOrNo more_const_definition | epsilon
;

type_block:
	T_TYPE onlyNewLine type_definition | epsilon
;

type_definition:
	T_IDENTIFIER more_identifiers T_SINGLEEQ T_DATATYPE ';' onlyNewLine type_definition | epsilon
;	

variable_block:
	T_VAR onlyNewLine variable_declaration | epsilon
;

variable_declaration:
	T_IDENTIFIER more_identifiers ':' T_DATATYPE ';' onlyNewLine variable_declaration {}
	| epsilon
;

more_identifiers:
	',' T_IDENTIFIER more_identifiers | epsilon
;

newlineOrNo:
	'\n'|
;

onlyNewLine:
	'\n'
;

operator:
	arithmetic_ops|relational_ops|boolean_ops|bitwise_ops
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
	}
	else {
		yyin = stdin;
	}

	clock_gettime(CLOCK_REALTIME, &start);
	yyparse();
	clock_gettime(CLOCK_REALTIME, &end);
	if(successful){
		printf("Compiled Successfully\n");
		printf("Took : %lf seconds\n", time_elapsed(&start, &end));
	}
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
