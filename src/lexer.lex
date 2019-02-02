%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}
%option yylineno

DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
OPERATORS &&|<|<=|>|>=|<>|==|\+|\*|-|\/|\|\|
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

{WHITESPACE} {}

{DATATYPES}	{
	yylval.type = strdup(yytext);
	return T_DATATYPE;
}

{IDENTIFIER} {
	yylval.str=strdup(yytext);
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


"\n"|","|";" { return yytext[0];}
.  {}

%%

int yywrap()
{
	return 1;
}