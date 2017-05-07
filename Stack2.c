#include <stdio.h>

int stack[3]={0};
int over=0;

void push(int gelen)
{
	if(over>=3)
	{
		printf("stack dolu...!\n");
	}
	else
	{
		stack[over]=gelen;
		over++;
	}
}	
	
void goster()
{int i=0;

	while(i<over)
	{
	
		printf("%d ",stack[i]);
		i++;
	}
}

int pop()
{
	if(over<0)
	{
		printf("stack bos...!\n");
	}
	else
	{
		 return stack[--over];
	}
	

}



int main()
{
	int a,b;
	
	
	do
	{
		printf("eklemek icin 1'e, cikarmak icin 2'ye basiniz: "); scanf("%d",&b);
	
		switch(b)
		{
			
		case 1: printf("eklemek istediginiz sayi= "); scanf("%d",&a); push(a);goster(); break;
		case 2:	if(over>=0)
		{
			printf("cikarilan sayi= %d\n",pop()); break;	
		}else break;
		default: return 0;
			
		}
		
	}while(b!=1 || b!=2);
		
}

