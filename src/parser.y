%{
	#include<stdio.h>
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
    int successful=1;
%}
%locations
%union {
	char *str;
	char *type;
}

%token T_USES 
%token T_WHILE
%token T_PROGRAM
%token T_VAR
%token T_TYPE
%token T_IF
%token T_BEGIN
%token T_END
%token T_CONST
%token <str> T_IDENTIFIER
%token <type> T_DATATYPE

%%
program:
	prog_heading block
;

prog_heading:
	T_PROGRAM T_IDENTIFIER ';' newlineOrNo
;

block:
	uses_block
;

uses_block:
	T_USES T_IDENTIFIER ',' more_libs | T_USES T_IDENTIFIER ';' newlineOrNo |;
;

more_libs:
	T_IDENTIFIER ',' more_libs | T_IDENTIFIER ';' newlineOrNo
;

newlineOrNo:
	'\n'|
;

%%

int yyerror() {
	printf("\nInvalid syntax at %d",yylloc.first_line);
	successful=0;
	return 0;
}

int main() {
	yyparse();
	if(successful){
		printf("\nCompilation successful");
	}
}
