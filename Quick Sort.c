#include<stdio.h>

int dizi[9]={6,5,1,3,8,4,7,9,2},j,i=0;
int d=8;	// dizinin son indisi

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];	//printf("l = %d -- r = %d -- p = %d\n",left,right,pivot);
 

      while (i <= j) {
            while (arr[i] < pivot)
            {
            	i++;
            	//printf("i %d\n",i);
			}
                  
            while (arr[j] > pivot)
            {
            	j--;
            	//printf("j %d\n", j);
			}								
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;													//printf("(%d,%d)\t",arr[i-1],arr[j+1]);		goster();
            }				
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void goster()
{
	int k;
	
	for(k=0;k<=d;k++)
		printf("%d ",dizi[k]);
		
	printf("\n");
	
}

main()
{
	goster();
	
	quickSort(dizi,0,d);

    goster();
		
	return 0;
}
