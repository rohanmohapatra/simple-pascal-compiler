%{
	#include <stdio.h>
	#include <string.h>
	//OPERATORS <|<=|>=|>|=|\|\||==|\+|\*|-|<>|/


%}

RESERVED if|while|program|var|type|uses|begin|end|const
DATATYPES integer|character|real|boolean|string
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE [ \t]+
OPERATORS &&|<|<=|>|>=|<>|==|\+|\*|-|\/|\|\|
PARENTHESIS \(|\)

%%

{RESERVED}	{
			ECHO;
			printf("\nReserved Detected\n");	
			}
{WHITESPACE}	{
				;
				}
{DATATYPES}		{
				ECHO;
				printf("\nDatatypes Detected\n");
				}
{IDENTIFIER}	{
				ECHO;
				printf("\nIdentifier Detected\n");
				}
{OPERATORS}		{
				ECHO;
				printf("\nOperator Detected\n");
				}
{PARENTHESIS}		{
				ECHO;
				printf("\nParenthesis Detected\n");
				}
.				{
				;
				}

%%

int main() {
	yylex();
}
int yywrap()
{
	return 1;
}