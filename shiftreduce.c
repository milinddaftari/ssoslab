#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char inputsymbols[30];
int n;
char sy_stack[20],production[30][20];
int stack[20];
char action_T[]="a+*()$";
char goto_nt[]="ETF";
int top=-1,sy_top=-1;
char action[12][9][6]={{"S5"," "," ","S4"," "," "},
					   {" ","S6"," "," "," ","Accept"},
					   {" ","R2","S7"," ","R2","R2"},
					   {" ","R4","R4"," ","R4","R4"},
					   {"S5"," "," ","S4"," "," "},
					   {" ","R6","R6"," ","R6","R6"},
					   {"S5"," "," ","S4"," "," "},
					   {"S5"," "," ","S4"," "," "},
					   {" ","S6"," "," ","S11"," "},
					   {" ","R1","S7"," ","R1","R1"},
					   {" ","R3","R3"," ","R3","R3"},
					   {" ","R5","R5"," ","R5","R5"}
					  };
int Goto[12][3]={{1,2,3},
		{-1,-1,-1},
		{-1,-1,-1},
		{-1,-1,-1},
		{8,2,3},
		{-1,-1,-1},
		{-1,9,3},
		{-1,-1,10},
		{-1,-1,-1},
		{-1,-1,-1},
		{-1,-1,-1},
		{-1,-1,-1},
		};
int getterminalindex(char x)
{
	int i;
	for(i=0;i<strlen(action_T);i++)
	{
		if(action_T[i]==x)
			break;
		}
	return i;
}
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
	return str;
}
int getgotoindex(char x)
{			
	int i;
	for(i=0;i<strlen(goto_nt);i++)
	{
		if(goto_nt[i]==x)
			break;
		}
	return i;
}

void push(int x)
{
	stack[++top]=x;
}
void pop(int n)
{
	int i;
    for(i=0;i<n;i++)
		top--;
}
void disp(int j,char inputstring[30])
{
	int i;
	for(i=0;i<=top;i++)
		printf("%3d",stack[i]);
	if(i==2)
		printf("			 ");
	else if(i==3)
		printf("		   ");
	else
		printf("		 ");
	for(i=0;i<=sy_top;i++)
		printf("%c",sy_stack[i]);
	printf("\t\t\t");
	for(i=j;i<strlen(inputstring);i++)
		printf("%c",inputstring[i]);
	printf("\t\t\t");
}
void sy_push(char x)
{
	sy_stack[++sy_top]=x;
}
void sy_pop(int n)
{
	int i;
	for(i=0;i<n;i++)
		sy_top--;
}
void processinput(char inputstring[30])
{
	int i,j,col,s,prod_no,t,st,buf[60],num;
	char ch,ac[3],*token,prod[20],rprod[20],temp[3];
	for(i=0;i<strlen(inputstring);i++)
	{
		ch=inputstring[i];
		while(1)
		{
			s=stack[top];
			buf[0]='\0';
			col=getterminalindex(ch);
			if(action[s][col][0]=='S')
			{
				strcpy(ac,action[s][col]);
				if(strlen(ac)==3)
				{
					temp[0]=ac[1];
					temp[1]=ac[2];
					temp[2]='\0';
					num=atoi(temp);
					push(num);
				}
				else
					push(ac[1]-'0');
				sy_push(ch);
				i++;
				disp(i,inputstring);
				printf("SHIFT\n");
				ch=inputstring[i];
				continue;
			}
			else if(action[s][col][0]=='R')
			{
				strcpy(ac,action[s][col]);
				prod_no=ac[1]-'0';
				prod_no--;
				strcpy(prod,production[prod_no]);
				strcpy(rprod,strrev(prod));
				token=strtok(rprod,">");
				pop(strlen(token));
				t=stack[top];
				col=getgotoindex(production[prod_no][0]);
				st=Goto[t][col];
				sy_pop(strlen(token));
				sy_push(production[prod_no][0]);
				push(st);
				disp(i,inputstring);
				printf("REDUCE %s %s\n",ac,production[prod_no]);
			}
			else if(action[s][col][0]=='A')
			{
				disp(i,inputstring);
				printf("Accept : Parsing done");
				break;
			}
			else
			{
				printf("ERROR");
				return;
			}
		}
	}
}
int main()
{	
	char inputstring[30];
	int i,j,ch;
	for(i=0;i<6;i++)
	{
		printf("Enter the %d production\t",i+1);
		scanf("%s",production[i]);
		
	}
	printf("\nThe productions entered\t");
	for(i=0;i<6;i++)
		printf("\n%d %s",i+1,production[i]);
	while(1)
	{
		top=-1;
		sy_top=-1;
		printf("\nEnter the input string : ");
		scanf("%s",inputstring);
		strcat(inputstring,"$");
		push(0);
		printf("\n Stack \t\t\t Symbol \t\t Input \t\t Action 		");
		printf("\n ________________________________________________________________________________________________ \n");
		processinput(inputstring);
		printf("\n_________________________________________________________________________________________________ \n");
		printf("\n Press 1 to contine 0 to Exit\t");					
		scanf("%d",&ch);
		fflush(stdin);
		if(ch==0)
			break;
	}
}
