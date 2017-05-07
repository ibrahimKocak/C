#include<stdio.h>

struct agac
{
	int veri;
	struct agac *sol,*sag;
	
};	struct agac *kok = NULL, *dugum, *anne;

void push(int gelen)
{
	struct agac *yeni;
	yeni = malloc(sizeof(struct agac));
	yeni->veri = gelen;
	yeni->sol = NULL;
	yeni->sag = NULL;
	
	if(kok == NULL)
		kok = yeni;
	else
	{
		dugum = kok;
		
		while(dugum != NULL)
		{
			anne = dugum;
			if(gelen < dugum->veri)
				dugum = dugum->sol;
			else
				dugum = dugum->sag;
		}
		if(gelen < anne->veri)
			anne->sol = yeni;
		else
			anne->sag = yeni;
	}
}



struct agac * ssearch(int gelen)
{
	dugum = kok;
	anne = NULL;
	
	while(dugum != NULL)
	{
		if(gelen == dugum->veri)
		{
			return (dugum);			
		}
		else
		{
			anne = dugum;
			if(gelen < dugum->veri)
				dugum = dugum->sol;
			else
				dugum = dugum->sag;
		}
	}
	
	dugum = NULL;	return (dugum);	
}

void search(int gelen)
{
	if(ssearch(gelen) == NULL)
		printf("Bulamadim\n");
	else
		printf("Buldum\n");
}


void pop(int gelen)
{
	if(ssearch(gelen) == NULL)
		printf("Silemedim\n");
	else
	{
		dugum = ssearch(gelen);
		
		if(dugum->sol == NULL && dugum->sag == NULL)
		{
			anne->sol = NULL;	anne->sag = NULL;	printf("Sildim\n");
		}
		else if(dugum->sol == NULL)
		{
			if(anne->veri < dugum->veri)
				anne->sag = dugum->sag;
			else
				anne->sol = dugum->sag;
		}
		else if(dugum->sag == NULL)
		{
			if(anne->veri < dugum->veri)
				anne->sag = dugum->sol;
			else
				anne->sol = dugum->sol;
		}
		else
		{
			struct agac *temp,*yedek;
			temp = malloc (sizeof(struct agac));
			yedek = malloc (sizeof(struct agac));
			temp = dugum;
			
			if(anne->veri < dugum->veri)
			{
				while(dugum->sol != NULL && dugum->sag != NULL)
				{
					if(dugum->sol != NULL)
						yedek = dugum;
					dugum = dugum->sag;					
				}
				
				anne->sag = yedek->sol;
				dugum = anne->sag;
				dugum->sol = temp->sol;
				dugum->sag = temp->sag;
				dugum = yedek;
				dugum->sol = NULL;
			}
			else
			{
				while(dugum->sol != NULL && dugum->sag != NULL)
				{
					if(dugum->sag != NULL)
						yedek = dugum;
					dugum = dugum->sol;					
				}
				
				anne->sol = yedek->sag;
				dugum = anne->sol;
				dugum->sol = temp->sol;
				dugum->sag = temp->sag;
				dugum = yedek;
				dugum->sag = NULL;
			}							
		}
				
	}
}

void Prefix(struct agac *gelen_anne)
{
	if(gelen_anne != NULL)
	{
		printf("%d ",gelen_anne->veri);
		Prefix(gelen_anne->sol);
		Prefix(gelen_anne->sag);
	}
}

void Infix(struct agac *gelen_anne)
{	
	if(gelen_anne != NULL)
	{
		Infix(gelen_anne->sol);
		printf("%d ",gelen_anne->veri);
		Infix(gelen_anne->sag);
	}
}

void Postfix(struct agac *gelen_anne)
{
	if(gelen_anne != NULL)
	{
		Postfix(gelen_anne->sol);
		Postfix(gelen_anne->sag);
		printf("%d ",gelen_anne->veri);
	}
}

main()
{
	push(7);	push(9);	push(1);	push(0);	push(4);	push(14);	push(2);	push(9);
	
	Infix(kok);	printf("\n");
	
	search(0);
	
	//pop(9);
	
	Infix(kok);	printf("\n");
}

/*
void push(int gelen)
{
	struct agac *yeni;
	yeni = malloc (sizeof(struct agac));
	yeni->veri = gelen;				
	yeni->sol = NULL;
	yeni->sag = NULL;
			
	if(kok == NULL)
	{
		kok = yeni;							//printf("*%d\n",kok->veri);
	}
	else
	{
		struct agac *anne = kok;
		while((gelen <= anne->veri && anne->sol != NULL) || (gelen > anne->veri && anne->sag != NULL))
		{
			if(gelen <= anne->veri)
			{
				anne = anne->sol;				//printf("->sl %d",anne->veri);
			}
			else
			{
				anne = anne->sag;				//printf("->sg %d",anne->veri);
			}
		}

		if(gelen <= anne->veri)
		{
			anne->sol = yeni;			//printf(" sol %d\n",gelen);
		}
		else
		{
			anne->sag = yeni;			//printf(" sag %d\n",gelen);
		}
	}
			
}
*/
