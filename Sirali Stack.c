//girilen sayýlarý kücükten büyüðe sýralayan stack

#include<stdio.h>
#include<conio.h>

int cuval[5], yedek[5];
int ust=0, y_ust=0;

void push(int gelen)
{
	if(ust>=5)
	printf("%d Stack Dolu..!\n",gelen);
else{

	cuval[ust]=gelen;
	ust++;
}
}



int pop()
{
	if(ust<=0){
	printf("Stack bos...\n");
	return -1;
	}
	else{
		ust--;
	return(cuval[ust]);
	
	}


}


void push_y(int gelen)
{
	if(y_ust>=5)
	printf("%d Stack Dolu..!\n",gelen);
else{

	yedek[y_ust]=gelen;
	y_ust++;
}
}

int pop_y()
{
	if(y_ust<=0){
	printf("Stack bos...\n");
	return -1;
	}
	else{
		y_ust--;
	return(yedek[y_ust]);
	
	}


}



int main(){

	int i,sayi;
	for(i=0;i<5;i++)
	{
			printf("Girilecek sayi: ");  scanf("%d",&sayi);
			if(ust==0)	push(sayi);
			else
			{
				if(sayi>cuval[ust-1])	push(sayi);
				else
				{
					while((sayi<cuval[ust-1])	&&  (ust>0))
					
				    push_y(pop());
						
					push(sayi);
					
					while(y_ust>0)	push(pop_y());
					
				}
			}
	}
	
	
for(i=0;i<ust;i++)
printf("%d,",cuval[i]);

getch();
	

}

