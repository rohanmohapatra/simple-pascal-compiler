%{
	#include <stdio.h>
	#include <string.h>
	#include "parser.tab.h"
	int yyerror();
	int yycolumn;
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; 
%}
%option yylineno

DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
OPERATORS &&|<|<=|>|>=|<>|==|\+|\*|-|\/|\|\|
ASSIGNMENTOPERATOR =
PARENTHESIS \(|\)
%%
if {	
	return T_IF;
}

while {
	return T_WHILE;
}

program {
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
	yylval.type = strdup(yytext);
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