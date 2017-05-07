#include<stdio.h>
#include<conio.h>

#define SAYI 5

/*Mahir KÖLE*/

int kuyruk[SAYI], say = 0;

void ekle(int gelen)
{
	kuyruk[say] = gelen;
	say++;
}

void cikar(int eleman)
{
	if(say==0)
	{
		return;
	}
	
	int i;
	
	for(i = eleman+say+1; i<say; i++)
	{
		kuyruk[i] = kuyruk[i+1];
	}
	say--;
}

main(int argc, char *argv[])
{
	ekle(1);
	ekle(2);
	ekle(3);
	ekle(4);
	ekle(5);
	
	int carpan = 1;
	
	while(say != 1)
	{
		cikar((carpan*6)%say);
		//carpan++;
	}
	
	int i;
	
	for(i = 0; i<say; i++)
	{
		printf("%d ",kuyruk[i]);	
	}
	
	printf("%d", kuyruk[say]);
}

