%{
	#include <stdio.h>
	#include <string.h>
	#include "parser.tab.h"
	int yyerror();
	int yycolumn;
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

	struct var_info {
		char *var_name;
		YYLTYPE var_decl_loc;
		struct YYLTYPE var_used_locs[10];
		int no_used;
		char *type;
		int scope_level;
	};

%}
%option yylineno

DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
OPERATORS &&|<|<=|>|>=|<>|==|\+|\*|-|\/|\|\|
ASSIGNMENTOPERATOR =
PARENTHESIS \(|\)
INTVAL [0-9]+
FLOATVAL [0-9]+\.[0-9]+
%%
if {
	return T_IF;
}

while {
	return T_WHILE;
}

program {
	printf("%d\n", yylineno);
	return T_PROGRAM;
}

var {
	return T_VAR;
}

type {
	return T_TYPE;
}

uses {
	return T_USES;
}

begin {
	return T_BEGIN;
}

end {
	return T_END;
}

const {
	return T_CONST;
}

{ASSIGNMENTOPERATOR} {
	return T_ASOP;
}

{WHITESPACE} {}

{DATATYPES}	{
	return T_DATATYPE;
}

{IDENTIFIER} {
	if(yyleng > 31) {
		printf("Warning : Identifier Length Greater 31 characters, Truncating Identifier.\n");
	}
	char temp[32];
	strncpy(temp,yytext,31);
	yylval.str = strdup(temp);
	return T_IDENTIFIER;
}

{OPERATORS}	{
	ECHO;
	printf("\nOperator Detected\n");
}

{PARENTHESIS} {
	ECHO;
	printf("\nParenthesis Detected\n");
}

{INTVAL} {
	yylval.intval = atoi(yytext);
	return T_INTVAL;
}

{FLOATVAL} {
	yylval.floatval = atof(yytext);
	return T_FLOATVAL;
}

"\n"|","|";" { 
	yycolumn = 1;
	return yytext[0];
}
.  {}

%%

int yywrap()
{
	return 1;
}