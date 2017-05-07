//Palindrom
#include<stdio.h>
#include<conio.h>
#include<string.h>

char kelime[20],yeni[20];
int ust=0;

void push(char c)
{
	kelime[ust++]=c;
}

void ters_goster()
{
	int i,t=0;
	
	for (i=ust-1;i>=0;i--)
	{
		printf("%c",kelime[i]);
		yeni[t]=kelime[i];
		t++;
	}	
}


main()
{
	char kel[20];
	printf("Kelime gir: "); scanf("%s",kel);
	
	int i=0;
	for(i=0;i<strlen(kel);i++)	push(kel[i]);
	
	ters_goster();
	printf("%s",yeni);
	
	if(strcmp(yeni,kel)==0)	printf("Tersi ayni ya la :D");
	getch();
	
}


// iki tane stack yap, sýfýr girene kadar tekler bir yere, çiftler bir yere. En son yazdýr.

