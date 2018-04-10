%{
	#include<ctype.h>
	#include<stdio.h>
	#include<stdlib.h>
	int valid=1;
%}
%token num
%left '+''-'
%left '*''/'
%left '('')'
%nonassoc UMINUS
%%
exp:e {
		if(valid)
		printf("the value of expression is %d",$1);
		exit(0);
	  }
e:e'+'e {
		$$=$1+$3;
		}
e:e'-'e {
		$$=$1-$3;
		}
e:e'*'e {
		$$=$1*$3;
		}
e:e'/'e {
		if($3==0)
			printf("\n division by zero\n");
		else
			{
				$$=$1/$3;
			}
		}
e:'('e')'	{
				$$=$2;
			}
e:num	{
			$$=$1;
		}	
e:'-'e {
		$$=-$2;

		}
%%
int yyerror()
{
	valid=0;
}
int main()
{
	printf("enter an expression\n");
	yyparse();
	printf("invalid");
}
int yywrap()
{
	return 1;
}