%{
#include<stdio.h>
int integer=0,operator=0;
%}
%%
[0-9]+  {
			printf("\nIdentifier %s\n",yytext);
			integer++;
		}
[+*]	{
			printf("\nOperator %s\n",yytext);
			operator++;
		}
%%
main()
{
	printf("\n--Enter the Expression--\n");
	yylex();
	if(integer==operator+1)
	{
		printf("\nValid Expression\n");
		printf("\nNumber of Identifiers is %d\nNumber of Operators is %d\n",integer,operator);
	}
	else
	{
		printf("\nInvalid Expression\n");
	}
}

int yywrap()
{
	return(1);
}