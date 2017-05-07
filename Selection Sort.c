#include<stdio.h>
#include<time.h>

int dizi[9]={6,5,1,3,8,4,7,9,2};
int d=8;	// dizinin son indisi


void Selection_Sort()
{
	int i,j;
	
	for(i=0;i<d;i++)
	{									
		for(j=i+1;j<d;j++)
		{								//printf("(%d,%d)\t",dizi[i],dizi[j]);		goster();
			if(dizi[j]<dizi[i])
			{
				int temp = dizi[i];
				dizi[i]=dizi[j];
				dizi[j]=temp;
			}
		}
		
	}
	
}

void goster()
{
	int k;
	
	for(k=0;k<d;k++)
	printf("%d ",dizi[k]);
	
	printf("\n");
}

main()
{
	goster();

	Selection_Sort();
	
	goster();
	
	return 0;
}

