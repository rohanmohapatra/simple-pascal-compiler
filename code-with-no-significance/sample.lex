%{
#include<stdio.h>
%}
%%
if|else|while|int|switch|for|char    {printf("keyword");}
[a-z]([a-z]|[0-9])*    {printf("identifier");}
[0-9]*        {printf("number");}
.*    {printf("invalid");}
%%
int main()
{
yylex();
return 0;
}
int yywrap()
{
}