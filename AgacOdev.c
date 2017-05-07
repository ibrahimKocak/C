#include<stdio.h>


char dizi[50];
int i = 0,j;
char stack[50],stack2[50];

void push(char gelen)
{
	if(i>=50)
		printf("Stack Dolu..!");
	else
	{
		stack[i] = gelen;
		i++;
	}	
}

char pop()
{
	if(i<0)
		printf("Stack Bos...!");
	else
	{
		i--;
		return stack[i+1];
	}
}
void push2(char gelen)
{
	if(i>=50)
		printf("Stack Dolu..!");
	else
	{
		stack2[i] = gelen;
		i++;
	}	
}

char pop2()
{
	if(i<0)
		printf("Stack Bos...!");
	else
	{
		i--;
		return stack2[i+1];
	}
}

void goster()
{
	for(j=0;j<i;j++)
		printf("%d",stack[j]);
}


main()
{
	printf("islemi giriniz : ");	scanf("%d",&stack);
	for(j=0;j<50;j++)
	{
		if(stack[j] == "/"	|| dizi[j] == "*" || dizi[j] == "+" || dizi[j] == "-")
		{
			push2(stack[j]);
			stack[j] = NULL;
		}

	}
	
	goster();
	
	return 0;
}
