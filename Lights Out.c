#include<stdio.h>

int L[3][3] = {{1,1,0},{0,0,0},{1,0,1}};

int A[9][10] ={
{1,1,0,1,0,0,0,0,0},{1,1,1,0,1,0,0,0,0},{0,1,1,0,0,1,0,0,0},
{1,0,0,1,1,0,1,0,0},{0,1,0,1,1,1,0,1,0},{0,0,1,0,1,1,0,0,1},
{0,0,0,1,0,0,1,1,0},{0,0,0,0,1,0,1,1,1},{0,0,0,0,0,1,0,1,1}			};

main()
{
	int i,j;
	
	for(i=0;i<3;i++)				//
		for(j=0;j<3;j++)
			A[i*3+j][9] = L[i][j];

	//yazdir();
	gauss_jordan();
	//yazdir();
	
	for(i=0;i<9;i++)
	{
		printf("%4d",A[i][9]);
		if(i%3==2)
			printf("\n");
	}
}

void gauss_jordan()
{
	int i=0,j=0,k;
	int kontrol = 0;
	
	do
	{
		if(A[i][j] == 0)
		{
			kontrol = 0;
			for(k=i+1; k<9; k++)
				if(A[k][j] == 1)
				{
					topla(i,k);
					kontrol = 1;
					break;
				}
			
			if(kontrol == 0)
			{
				printf("Cozum yok!");
				exit(1);
			}
		}
		
		for(k=0; k<9; k++)
			if( k != i)
				if(A[k][j] == 1)
				{
					//printf("%d--%d",k,i);
					topla(k,i);
					//yazdir();
				}
		i++;
		j++;
			
	}while(i != 9);	
}

topla(int indis1, int indis2)
{
	int j;
	
	for(j=0; j<10; j++)
		A[indis1][j] = (A[indis1][j] + A[indis2][j]) %2 ;
}

yazdir()
{
	int i,j;
	printf("\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<10;j++)
			printf("%4d",A[i][j]);
		printf("\n");
	}
	printf("\n");
}
