#include <stdio.h>
#include <stdlib.h>

#define FILENAME "info.yas"

struct info{
    int id;
    char name[20];
    float price;
    int stock;
};

void menu();
void add();
void update();
void show();
void delete();

int main(){
   menu();
}

void menu(){
    int choice;
    do{
    printf("***URUN YONETIMI***\n");
    printf("1-Urun ekleme\n");
    printf("2-Urun guncelleme\n");
    printf("3-Urun goster\n");
    printf("4-Urun sil\n");
    printf("5-cikis\n");
    printf("Lutfen bir islem seciniz: ");
    scanf("%d",&choice);
     switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            update();
            break;
        case 3:
            show();
            break;
        case 4:
            delete();
            break;
        
        default:
            printf("Yanlis secim yaptiniz.");
            break;
        }
    }
    while(choice!=5);
    }


void add(){
    struct info p;
    FILE* file=fopen(FILENAME,"ab");

    printf("urun id: ");
    scanf("%d",&p.id);
    printf("urun adi: ");
    scanf("%s",p.name);
    printf("urun fiyati: ");
    scanf("%f",&p.price);
    printf("urun miktari: ");
    scanf("%d",&p.stock);

    fwrite(&p,sizeof(struct info),1,file);
    fclose(file);
    printf("urun basariyla eklenmistir.\n");
}

void update(){
    struct info p;
    int secim,ysec,id,found=0;
    FILE* file=fopen(FILENAME,"rb+");

     printf("Guncellenecek urunun ID'sini girin: ");
     scanf("%d", &id);

    while(fread(&p,sizeof(struct info),1,file)){
        if(p.id==id){
            found=1;
        

        printf("*NE YAPMAK ISTERSINIZ?*\n");
        printf("1-urun idsi guncelleme\n");
        printf("2-urun adi guncelleme\n");
        printf("3-urun stok miktari guncelleme\n");
        printf("4-urun fiyati guncelleme\n");
        printf("5-cikis\n");
        scanf("%d",&secim);

        switch (secim){
        case 1:
        printf("yeni id girin: ");
        scanf("%d",&p.id);
        break;
        case 2:
        printf("yeni urun adi girin: ");
        scanf("%19s",p.name);
        break;
        case 3:
        printf("islem seciniz\n 1-urun ekle\n2-urun cikar");
        scanf("%d",&ysec);
        if(ysec==1){
            int ekle;
            printf("eklenecek miktar nedir?");
            scanf("%d",&ekle);
            p.stock+=ekle;
            printf("urun miktari guncellenmistir.");

        }else if(ysec==2){
            int cikar;
            printf("cikarilacak miktar nedir?");
            scanf("%d",&cikar);
            p.stock-=cikar;
            printf("urun miktari guncellenmistir.");
        }
        case 4:
            printf("yeni fiyat girin: ");
            scanf("%f",p.price);
            break;
        case 5:
            printf("cikis yapildi.\n");
            break;
        default:
            printf("gecersiz secim.\n");
            break;
        }
          fseek(file, -sizeof(struct info), SEEK_CUR);
          fwrite(&p, sizeof(struct info), 1, file);
            
    }
    }
    if(!found){
        printf("dosya bulunamadi.");
    }
    fclose(file);
    }
      


void show(){
    FILE* file=fopen(FILENAME,"rb");
    struct info p;
    if(file==NULL){
        printf("dosya acilamadi.");
    }else{
    fread(&p,sizeof(struct info),1,file);
    printf("**URUN LISTESI**\n");
    printf("urun id:%d\n",p.id);
    printf("urun adi:%s\n",p.name);
    printf("urun fiyati:%.2f\n",p.price);
    printf("urun stogu:%d\n",p.stock);
    
    }

    
    fclose(file);
}

void delete(){
    if(remove(FILENAME)==0){
        printf("Dosya basariyla silindi.\n");
    }else{
        printf("Dosya silinemedi\n");
    }
}
