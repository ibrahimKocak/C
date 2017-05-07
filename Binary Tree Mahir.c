#include <stdio.h>
#include <conio.h>

struct agac {
       int veri;
       struct agac *sol, *sag;
};

struct agac *kok = NULL;

void ekle(int sayi){
     
     struct agac *yeni = malloc(sizeof(struct agac));
     yeni->veri=sayi; yeni->sag=NULL; yeni->sol=NULL;
     
     if(kok==NULL) kok=yeni;
     else{
          struct agac *anne, *dugum = kok;
          
          while(dugum!=NULL)
          {
              anne=dugum;              
              if(sayi < dugum->veri) dugum = dugum->sol;
              else dugum = dugum->sag;                  
          }
          
          if(sayi>anne->veri) anne->sag = yeni;
          else anne->sol = yeni;
     }  

}

void dolas(struct agac *dugum){
     if(dugum!=NULL){
         dolas(dugum->sol);
         printf("%d ", dugum->veri);
         dolas(dugum->sag);  
     }
}

struct agac *minbul(struct agac *dugum){
    if(dugum==NULL) return NULL;
    if(dugum->sol != NULL) return minbul(dugum->sol);
    else return dugum;   
}

struct agac *maxbul(struct agac *dugum){
    if(dugum==NULL) return NULL;
    if(dugum->sag != NULL) return maxbul(dugum->sag);
    else return dugum;   
}

struct agac *sil(struct agac *dugum, int data)
{
       if(dugum==NULL) printf("Bulamadim");
       else if(data < dugum->veri) dugum->sol = sil(dugum->sol, data);
       else if(data > dugum->veri) dugum->sag = sil(dugum->sag, data);
       else {
            if(dugum->sag!=NULL && dugum->sol!=NULL){
                 struct agac *temp;
                 temp = minbul(dugum->sag);
                 dugum -> veri = temp->veri;
                 
                 dugum -> sag = sil(dugum->sag, temp->veri);
            }
            else {
                 if(dugum->sol == NULL) dugum = dugum->sag;
                 else if(dugum->sag == NULL) dugum = dugum->sol;
            }
       }
       return dugum;
}

int main(){
    
    ekle(8);
    ekle(12);
    ekle(7);
    ekle(10);
    ekle(1);
    ekle(15);
    ekle(13);
    ekle(14);
    
    dolas(kok);
    sil(kok, 8);
    sil(kok, 8);
    printf("\n");
     dolas(kok);
    /*struct agac *m = minbul(kok);
    printf("En kucuk: %d ", m->veri);
    
    m = maxbul(kok);
    printf("En buyuk: %d ", m->veri);*/
    
    getch();   
}
