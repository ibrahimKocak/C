#include<stdio.h>
#include<stdlib.h>

struct liste
{
       char veri;
       struct liste *sonraki;     
};
struct liste *bas=NULL;

void basa_ekle(char gelen)
{
	struct liste *yeni;
	yeni=malloc(sizeof(struct liste));
	yeni->veri=gelen;
	yeni->sonraki=bas;
	bas=yeni;
}

void ekle(char gelen)
{
     if (bas==NULL)
     {
        bas=(struct liste *) malloc (sizeof(struct liste));
        bas->veri=gelen;
        bas->sonraki=NULL;
        }    
        else
        {
            struct liste *dugum=bas;
            while (dugum->sonraki!=NULL)
            {
                  dugum=dugum->sonraki;
            }
            struct liste *yeni;
            yeni=malloc (sizeof(struct liste));
            yeni->veri=gelen;
            yeni->sonraki=NULL;
            dugum->sonraki=yeni;
        }
}
void goster()
{
     if (bas==NULL)
        printf ("\nListe Bos...");
     else
     {
         struct liste *dugum=bas;
         while (dugum!=NULL)
         {
               printf("%d,",dugum->veri);
               dugum=dugum->sonraki;
         }
     }
     
}

void bastan_sil()
{
	if(bas==NULL)
	printf("Liste Bos...\n");
	else
	bas=bas->sonraki;
}


void main()
{
     ekle(34); ekle(45); ekle(17); ekle(12);
     goster();
     basa_ekle(66);
     goster();
     bastan_sil();	bastan_sil();
     goster();
     
     getch();
     
}
     
       

