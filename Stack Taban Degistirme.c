#include<stdio.h>
#include<conio.h>
#define mak 5

char kuyruk[mak]={-1};
char bas=0,son=0;
char kapasite=0;

void goster()
{
     int i=0;
     for(i=0;i<mak;i++)
     if(i==bas) printf("*");
     if(i==son%mak) printf("$");
     printf("%d,",kuyruk[i]);
}


void cikar()
{
     if(kapasite==0)
          printf("\nKuyruk Bos..!");
     else
     {
         printf("n%d cikarildi...",kuyruk[bas]);
         kapasite--;
         kuyruk[bas]=0;
         bas++;              
     }              
}

void ekle(char gelen)
{
     if(kapasite==mak)
     printf("\nKuyruk dolu..!");
     else
     {
          kuyruk[son]=gelen;
          son++;
          kapasite++;    
     }
}

                   
void main()
{
     ekle(23); ekle(45); ekle(98); ekle(23); ekle(23); ekle(23);
     goster();
     getch();
}

