#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct FT
{
	char nonT,set[20];
};

int i,j;

typedef struct FT FIRST_FOLLOW_SET;
FIRST_FOLLOW_SET first[10],follow[10];
char Parser_Table[2][3][10];

char *strrev(char *str)
{
	int i=strlen(str)-1,j=0;
	char ch;
	while(i>j)
	{
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
		i--;
		j++;
	}
	return(str);
}

char terminal_list[3] = {"ab$"};
char stack[50];
int top = -1;
int getFollowIndex(char x)
{
	for(i=0;i<2;i++)
		if(follow[i].nonT==x)
			break;
	return(i);
} 
int getTerminalIndex(char x)
{
	for(i=0;i<strlen(terminal_list);i++)
		if(terminal_list[i]==x)
			break;
	return(i);
} 
void push(char x)
{
	stack[++top]=x;
}
void pop()
{
	stack[top]='\0';
	top--;
}
void check_input(char expr[30])
{
	int row,col;
	char prod[20],*token,ch,StackTop,temp[2],rprod[20];
	temp[1]='\0';
	for(i=0;expr[i]!='$';)
	{
		ch = expr[i];
		StackTop = stack[top];
		temp[0] = StackTop;
		if((strstr(terminal_list,temp)!=NULL)|| StackTop == '$')
		{
			if(strstr(terminal_list,temp)!=NULL)
			{
				pop();
				i++;
			}
			else
			{
				printf("\nError in the stack symbol , Not Mentioned ");
				printf("\n%s Not Accepted",expr);
				return;
			}
		}
		else
		{
			if(strstr(terminal_list,temp)==NULL)
			{
				row = getFollowIndex(StackTop);
				col = getTerminalIndex(ch);
				strcpy(prod,Parser_Table[row][col]);
				printf("\nM[%d,%d] M[%c,%c] = %s",row,col,StackTop,ch,prod);
				if(strstr(prod,"err")!=NULL)
				{
					printf("\nError : No Entry in the Table");
					printf("\n%s Not Accepted",expr);
					return;
				}
				else
				{
					strcpy(rprod,strrev(prod));
					token = strtok(rprod,">");
					if(strstr(rprod,"#")!=NULL)
					{
						pop();
					}
					else
					{
						pop();
						for(j=0;j<strlen(token);j++)
						{	
							push(token[j]);
						}	
					}
				}
			}

		}
	}
	if(expr[i]==stack[top])
		printf("\nch = %c StackTop = %c %s is Accepted ",expr[i],stack[top],expr);
	else
		printf("\nch = %c StackTop = %c %s is Not Accepted ",expr[i],stack[top],expr);
}

void init()
{
	stack[0] = '\0';
	top = -1;
}

int main()
{
	char production[10][20],inputString[30],t,T;
	int ch;
	for(i=0;i<2;i++)
	{
		printf("\nEnter the %d production ",i);
		gets(production[i]);
		fflush(stdin);
	}
	printf("\nThe productions entered are - ");
	for (i=0;i<2;i++)
	{
		printf("\n%s",production[i]);
	}
	printf("\n--First Set--\n");
	for(i=0;i<2;i++)
	{
		first[i].nonT = production[i][0];
		printf("\nEnter First(%c) : ",first[i].nonT);
		gets(first[i].set);
		fflush(stdin);
	}
	printf("\n--Follow Set--\n");
	for(i=0;i<2;i++)
	{
		follow[i].nonT = first[i].nonT;
		printf("\nEnter Follow(%c) : ",follow[i].nonT);
		gets(follow[i].set);
		fflush(stdin);
	}
	printf("\nIf no entry , enter 'err' in the table ");
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
		{
			T = first[i].nonT;
			t = terminal_list[j];
			printf("\nM[%d,%d] M[%c,%c] = ",i,j,T,t);
			gets(Parser_Table[i][j]);
			fflush(stdin);
		}
		init();
		push('$');
		push(production[0][0]);
		printf("\nStack %s",stack);
		printf("\nEnter the input : ");
		gets(inputString);
		strcat(inputString,"$");
		printf("\nInput String %s ",inputString);
		check_input(inputString);
		printf("\n");
}
