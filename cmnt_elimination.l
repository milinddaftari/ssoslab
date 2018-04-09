%{
#include<stdio.h>
int comment=0;
%}
%%
[/][/][a-zA-Z0-9 ]*  {
						printf("");
						comment++;
					   }
[/][*][a-zA-Z0-9 \n\t]*[\n]*[*][/]	{
										printf("");
										comment++;
									}
%%
main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yyout = fopen(argv[2],"w");
	yylex();
	printf("\nTotal comment lines = %d \n",comment);
}

int yywrap()
{
	return(1);
}