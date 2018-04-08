#include<stdio.h>
#include<string.h>
void main()
{
	char icode[10][30],opr,op1[5],op2[5],res[5];
	int i=0,n,j,k;
	printf("\nEnter the number of intermediate statements : ");
	scanf("%d",&n);
	printf("\nEnter the set of intermediate code\n");
	for(i=0;i<n;i++)
		scanf("%s",&icode[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		j=0;
		k=0;
		while(icode[i][j]!='=')
		{
			res[k] = icode[i][j];
			j=j+1;
			k=k+1;
		}
		res[j] = '\0';
		k=0;
		j++;
		if(icode[i][j]=='-')
		{
			j++;
			while(icode[i][j]!='\0')
			{
				op1[k] = icode[i][j];
				j++;
				k++;
			}
			op1[k] = '\0';
			printf("\nLOAD R1,%s",op1);
			printf("\nNEG R1");
			printf("\nSTORE %s,R1",res);
		}
		else
		{
			k=0;
			while(icode[i][j]!='\0' && icode[i][j]!='+' && icode[i][j]!='-' && icode[i][j]!='*')
			{
				op1[k]=icode[i][j];
				j++;
				k++;
			}
			op1[k]='\0';
			if(icode[i][j]=='\0')
			{
				printf("\nLOAD R1,%s",op1);
				printf("\nSTORE %s,R1",res);
				continue;
			}
			else
			{
				opr = icode[i][j];
				k=0;
				j++;
				while(icode[i][j]!='\0')
				{
					op2[k]=icode[i][j];
					j++;
					k++;
				}
				op2[k]='\0';
			}
			switch(opr)
			{
				case '+' : printf("\nLOAD R2,%s",op1);
						   printf("\nLOAD R3,%s",op2);
						   printf("\nADD R2,R3");
						   printf("\nSTORE %s,R2",res);
						   break;
				case '-' : printf("\nLOAD R2,%s",op1);
						   printf("\nLOAD R3,%s",op2);
						   printf("\nSUB R2,R3");
						   printf("\nSTORE %s,R2",res);
						   break;
				case '*' : printf("\nLOAD R1,%s",op1);
						   printf("\nLOAD R2,%s",op2);
						   printf("\nMUL R1,R2");
						   printf("\nSTORE %s,R1",res);
						   break;
				default :  printf("--INVALID--");
			}
		}
	}
	printf("\n");
}