#include<stdio.h>
#include<stdlib.h>

int dizi[9]={6,5,1,3,8,4,7,9,2},i,temp;
int d=8;	// dizinin son indisi
int y=0;

void BubbleSort()
{
	i=0;
	y = 1;												//printf("\n");
		
	while(i < d)
	{
		if(dizi[i] > dizi[i+1])
		{
			temp = dizi[i];
			dizi[i] = dizi[i+1];
			dizi[i+1] = temp;
			y = 0;					 
		}
														//printf("(%d,%d)\t",dizi[i],dizi[i+1]);		goster();
		i++;
	}													//printf("\n");
	if(y == 0)
	{													
		BubbleSort(dizi);
	}
}


void goster()
{
	int j;
	
	for(j=0;j<=d;j++)
		printf("%d ",dizi[j]);
	printf("\n");
}


main()
{
	goster();
	
	BubbleSort();
	
	goster();
	
	return 0;
}
