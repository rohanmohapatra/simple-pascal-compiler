%{
	#include <stdio.h>
	#include <string.h>
	#include "parser_icg.tab.h"
	#include "../uthash/src/uthash.h"
	#include "var_type.h"
	int yyerror();
	int yycolumn;
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
    extern struct variable_type_info var_type_information;
	// struct var_info {
	// 	char var_name[31];
	// 	YYLTYPE var_decl_loc;
	// 	char type[10];
	// 	int scope_level;
	// };
	
	// struct symbol_table {
	// 	char var_name[31];
	// 	struct var_info var;
	// 	UT_hash_handle hh;
	// };

%}
%option yylineno

%x IN_MULTILINE_COMMENT
%x IN_SINGLELINE_COMMENT


DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
PUNCTUATION ;|,|:|.
SINGLE_CHAR_OPERATORS <|>|\+|\*|-|\/|\&|\||\~|\!
MODULO %|mod
MULTI_CHAR_OPERATORS and|or|not|<=|>=|<>|>>|<<|:=|\+=|-=|\*=|\/=
PARENTHESIS \(|\)|\[|\]
SINGLE_EQ =
INTVAL [0-9]+
FLOATVAL [0-9]+\.[0-9]+
BOOLVAL true|false
STRINGVAL \".*\"
INDEXTYPE [0-9]\.\.\.[0-9]+
%%

<INITIAL>"{*" {BEGIN(IN_MULTILINE_COMMENT);}

<INITIAL>"{" {BEGIN(IN_SINGLELINE_COMMENT);}

<IN_MULTILINE_COMMENT>"*}\n"      {BEGIN(INITIAL);}

<IN_MULTILINE_COMMENT>[^*\n]+   ;// eat comment in chunks

<IN_MULTILINE_COMMENT>"*"       ;// eat the lone star

<IN_MULTILINE_COMMENT>\n        ;

<IN_SINGLELINE_COMMENT>"}\n"     {BEGIN(INITIAL);}

<IN_SINGLELINE_COMMENT>.   		;


{INDEXTYPE} {
	ECHO;
	return T_INDEXTYPE;	

}

{INTVAL} {
	yylval.s.intval = atoi(yytext);
	var_type_information.is_int = 1;
	ECHO;
 	return T_INTVAL;
}

{FLOATVAL} {
	yylval.s.floatval = atof(yytext);
	var_type_information.is_float = 1;
	ECHO;
 	return T_FLOATVAL;
}

{BOOLVAL} {
	if(strcmp(yytext,"true")==0) {
		yylval.s.intval=1;
	}
	else {
		yylval.s.intval=0;
	}
	var_type_information.is_bool = 1;
	ECHO;
 	return T_BOOLVAL;
}

{STRINGVAL} {
	char temp[yyleng-2];
	//skip starting and ending quote and copy only string content
	strncpy(temp,yytext+1,yyleng-2);
	temp[yyleng-2]='\0';
	yylval.s.str=strdup(temp);
	//printf("yylval.str : %s and len : %d\n",temp,(int)strlen(yylval.s.str));
	var_type_information.is_str = 1;
	ECHO;
 return T_STRINGVAL;	
}

function {
	ECHO;
	return T_FUNCTION;
}

procedure {
	ECHO;
	return T_PROCEDURE;
}

if {
	ECHO;
 return T_IF;
}

then {
	ECHO;
	return T_THEN;
}

else {
	ECHO;
	return T_ELSE;
}

while {
	ECHO;
 return T_WHILE;
}

program {
	ECHO;
 return T_PROGRAM;
}

var {
	ECHO;
 return T_VAR;
}

type {
	ECHO;
 return T_TYPE;
}

uses {
	ECHO;
 return T_USES;
}

begin {
	ECHO;
 return T_BEGIN;
}

end {
	ECHO;
 return T_END;
}

const {
	ECHO;
 return T_CONST;
}

array {
	ECHO;
 return T_ARRAY;	
}
of	{
	ECHO;
	return T_OF;
}
writeln {
	ECHO;
	return T_WRITELN;
}
for {
	ECHO;
	return T_FOR;
}

do {
	ECHO;
	return T_DO;
}

to {
	ECHO;
	return T_TO;
}

downto {
	ECHO;
	return T_DOWNTO;
}


{WHITESPACE} {ECHO;}

{DATATYPES}	{
	yylval.s.type = strdup(yytext);
	ECHO;
 return T_DATATYPE;
}

{IDENTIFIER} {
	if(yyleng >= 31) {
		printf("Warning : Identifier Length Greater 31 characters, Truncating Identifier.\n");
	}
	char temp[32];
	strncpy(temp,yytext,31);
	yylval.s.str = strdup(temp);
	//printf("%s\n", yylval.s.str);
	ECHO;
 return T_IDENTIFIER;
}

{SINGLE_CHAR_OPERATORS}	{
	ECHO;
 return yytext[0];
}

{MODULO} {
	ECHO;
 return '%';
}

{SINGLE_EQ} {
	ECHO;
 return T_SINGLEEQ;
}

{MULTI_CHAR_OPERATORS} {
	if(strcmp(yytext,"and")==0) {
		ECHO;
 return T_BOOL_AND;
	}
	else if(strcmp(yytext,"or")==0) {
		ECHO;
 return T_BOOL_OR;
	}
	else if(strcmp(yytext,"not")==0) {
		ECHO;
 return T_BOOL_NOT;
	}
	else if(strcmp(yytext,"<=")==0) {
		ECHO;
 return T_REL_LE;
	}
	else if(strcmp(yytext,">=")==0) {
		ECHO;
 return T_REL_GE;
	}
	else if(strcmp(yytext,"<>")==0) {
		ECHO;
 return T_REL_NE;
	}
	else if(strcmp(yytext,">>")==0) {
		ECHO;
 return T_BIT_RS;
	}
	else if(strcmp(yytext,"<<")==0) {
		ECHO;
 return T_BIT_LS;
	}
	else if(strcmp(yytext,":=")==0) {
		ECHO;
 return T_ASOP;
	}
	else if(strcmp(yytext,"+=")==0) {
		ECHO;
 return T_AS_PE;
	}
	else if(strcmp(yytext,"-=")==0) {
		ECHO;
 return T_AS_SE;
	}
	else if(strcmp(yytext,"*=")==0) {
		ECHO;
 return T_AS_MULE; //MultiplyEqual
	}
	else if(strcmp(yytext,"/=")==0) {
		ECHO;
 return T_AS_DIVE;
	}
}

{PARENTHESIS} {
	ECHO;
 return yytext[0];
}

{PUNCTUATION} {
	ECHO;
 return yytext[0];
}

"\n" { 
	yycolumn = 1;
	ECHO;
 //return yytext[0];
}
.  {}

%%

int yywrap() {
 return 1;
}
