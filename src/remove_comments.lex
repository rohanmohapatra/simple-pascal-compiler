%{
#include<stdio.h>
%}
%x IN_COMMENT
%%
<INITIAL>"{*" {BEGIN(IN_COMMENT);printf("THIS SHOULD HAVE BEEN A COMMENT-CENSURED");}
<IN_COMMENT>"*}"      {BEGIN(INITIAL);}
<IN_COMMENT>[^*\n]+   ;// eat comment in chunks
<IN_COMMENT>"*"       ;// eat the lone star
<IN_COMMENT>\n        yylineno++;
%%
void main() {
    yylex();
}
