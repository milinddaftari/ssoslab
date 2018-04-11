%{
#include<stdio.h>
#include<stdlib.h>
extern FILE *yyin;
int id=0,digit=0,key=0,op=0;
%}
%token DIGIT ID OP KEY
%%
input : DIGIT input {digit++;}
	|	ID input {id++;}
	|	OP input {op++;}
	|	KEY input {key++;}
	|   DIGIT  {digit++;}
	|	ID  {id++;}
	|	OP  {op++;}
	|	KEY  {key++;} ;
%%

main(int argc,char *argv[])
{
	yyin = fopen("sample1.c","r");
	yyparse();
	printf("\nNumber=%d\nKeyword=%d\nIdentifier=%d\nOperator=%d\n",digit,key,id,op);
}

int yyerror()
{
	printf("\nError\n");
	exit(0);
}