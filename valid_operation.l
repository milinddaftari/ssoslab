%{
#include<stdio.h>
#include"y.tab.h"
extern int yylval;
%}
%%
[\t]	;
[+|-|*|/|=|>|<]		{
						printf("\nOperator is %s\n",yytext);
						return(OP);
					}
[0-9]+				{
						yylval = atoi(yytext);
						printf("\nNumber is %d\n",yylval);
						return(DIGIT);
					}
int|return|char|float|bool|double|for|if|else|while|do|case|switch|void|break|goto|continue	{
																								printf("\nKeyword is %s\n",yytext);
																								return(KEY);
																							}
[a-zA-Z0-9]+	{
					printf("\nIdentifier is %s\n",yytext);
					return(ID);
				}
.  ;
%%

int yywrap()
{
	return 1;
}