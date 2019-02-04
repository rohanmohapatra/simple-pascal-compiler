%{
	#include <stdio.h>
	#include <string.h>
	#include "parser.tab.h"
	#include <uthash.h>
	int yyerror();
	int yycolumn;
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

	struct var_info {
		char var_name[31];
		YYLTYPE var_decl_loc;
		char type[10];
		int scope_level;
	};
	
	struct symbol_table {
		char var_name[31];
		struct var_info var;
		UT_hash_handle hh;
	};

%}
%option yylineno

DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
PUNCTUATION ;|,|:
SINGLE_CHAR_OPERATORS <|>|\+|\*|-|\/|\&|\||\~|\!
MODULO %|mod
MULTI_CHAR_OPERATORS and|or|not|<=|>=|<>|>>|<<|:=
PARENTHESIS \(|\)
SINGLE_EQ =
INTVAL [0-9]+
FLOATVAL [0-9]+\.[0-9]+
BOOLVAL true|false
STRINGVAL \".*\"
%%
{INTVAL} {
	yylval.intval = atoi(yytext);
	return T_INTVAL;
}

{FLOATVAL} {
	yylval.floatval = atof(yytext);
	return T_FLOATVAL;
}

{BOOLVAL} {
	if(strcmp(yytext,"true")==0) {
		yylval.intval=1;
	}
	else {
		yylval.intval=0;
	}
	return T_BOOLVAL;
}

{STRINGVAL} {
	char temp[yyleng-2];
	//skip starting and ending quote and copy only string content
	strncpy(temp,yytext+1,yyleng-2);
	yylval.str=strdup(temp);
	return T_STRINGVAL;	
}
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

array {
	return T_ARRAY;	
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

{SINGLE_CHAR_OPERATORS}	{
	return yytext[0];
}

{MODULO} {
	return '%';
}

{SINGLE_EQ} {
	return T_SINGLEEQ;
}

{MULTI_CHAR_OPERATORS} {
	if(strcmp(yytext,"and")==0) {
		return T_BOOL_AND;
	}
	else if(strcmp(yytext,"or")==0) {
		return T_BOOL_OR;
	}
	else if(strcmp(yytext,"not")==0) {
		return T_BOOL_NOT;
	}
	else if(strcmp(yytext,"<=")==0) {
		return T_REL_LE;
	}
	else if(strcmp(yytext,">=")==0) {
		return T_REL_GE;
	}
	else if(strcmp(yytext,"<>")==0) {
		return T_REL_NE;
	}
	else if(strcmp(yytext,">>")==0) {
		return T_BIT_RS;
	}
	else if(strcmp(yytext,"<<")==0) {
		return T_BIT_LS;
	}
	else if(strcmp(yytext,":=")==0) {
		return T_ASOP;
	}
}

{PARENTHESIS} {
	return yytext[0];
}

{PUNCTUATION} {
	return yytext[0];
}

"\n" { 
	yycolumn = 1;
	return yytext[0];
}
.  {}

%%

int yywrap() {
	return 1;
}