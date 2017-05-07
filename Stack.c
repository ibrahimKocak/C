#include<stdio.h>

int cuval[5];
int ust=0;

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

int main(){
	
	push(5); push(22); push(12); push(32);	push(81); push(9);
	printf("cikariyorum %d \n",pop());
	
	int i;
	for(i=0;i<ust;i++)
	
	printf("%d,",cuval[i]);
	

	

	return 0;
}

