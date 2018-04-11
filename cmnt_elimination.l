%{
#include<stdio.h>
#include<stdlib.h>
int c=0;
%}
%%
[/][/][0-9a-zA-Z ]* {printf(" "); c++;}
[/][*][0-9a-zA-Z \n\t]*[\n]*[*][/] {printf(" "); c++;}
%%
main()
{
	yyin = fopen("in.c","r");
	yyout = fopen("out.c","w");
	yylex();
	printf("\nTotal Comment lines is %d \n",c);
}
int yywrap()
{
	return 1;
}