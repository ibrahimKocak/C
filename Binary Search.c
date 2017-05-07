#include<stdio.h>


int dizi[]={12, 22, 34, 47, 55, 67, 82, 98};
int d=8;

int binarySearch(int array[], int size, int searchValue)
{
    int low = 0;
    int high = size - 1;
 
    int mid;
 
    while (low <= high)
    {
        mid = (low + high) / 2;
 
        if(searchValue == array[mid])
        {
            return 1;
        }
        else if (searchValue > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
 
    return -1;
 
}

main()
{
	int sayi;
	
	printf("sayi = ");	scanf("%d",&sayi);
	
	if(binarySearch(dizi,d,sayi) == 1)
		printf("Buldum..!");
	else
		printf("Bulamadim..!");
		
}
