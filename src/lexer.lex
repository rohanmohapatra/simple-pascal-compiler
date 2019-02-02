%{
	#include <stdio.h>
	#include <string.h>
	#include "parser.tab.h"
%}
DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
OPERATORS &&|<|<=|>|>=|<>|==|\+|\*|-|\/|\|\|
PARENTHESIS \(|\)
%%
if {	
	yylval.keyword = strdup(yytext);
	return T_IF;
}

while {
	yylval.keyword = strdup(yytext);
	return T_WHILE;
}

program {
	printf("in program");
	yylval.keyword = strdup(yytext);
	return T_PROGRAM;
}

var {
	yylval.keyword = strdup(yytext);
	return T_VAR;
}

type {
	yylval.keyword = strdup(yytext);
	return T_TYPE;
}

uses {
	printf("\nin uses");
	yylval.keyword = strdup(yytext);
	return T_USES;
}

begin {
	yylval.keyword = strdup(yytext);
	return T_BEGIN;
}

end {
	yylval.keyword = strdup(yytext);
	return T_END;
}

const {
	yylval.keyword = strdup(yytext);
	return T_CONST;
}

{WHITESPACE} {;}

{DATATYPES}	{
	ECHO;
	printf("\nDatatypes Detected\n");
}

{IDENTIFIER} {
	printf("\nIn identifier");
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


";" { return yytext[0];}
.  {}

%%

int yywrap()
{
	return 1;
}