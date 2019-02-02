%{
	#include<stdio.h>
	int valid=1;
	#define YYPARSE_PARAM scanner
    #define YYLEX_PARAM   scanner
%}
%union {
	char *keyword;
	char *str;
}

%token <keyword> T_USES 
%token <keyword> T_WHILE
%token <keyword> T_PROGRAM
%token <keyword> T_VAR
%token <keyword> T_TYPE
%token <keyword> T_IF
%token <keyword> T_BEGIN
%token <keyword> T_END
%token <keyword> T_CONST
%token <str> T_IDENTIFIER

%%
program_sub_block:
	T_PROGRAM T_IDENTIFIER ';' uses_sub_block
;

uses_sub_block:
	T_USES T_IDENTIFIER ';'{
		printf("hello");
	}
;
%%

int yyerror() {
	printf("\nInvalid syntax");
	return 0;
}

int main() {
	printf("\nEnter string:");
	yyparse();
}
