#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows1 2
#define cols1 3
#define rows2 3
#define cols2 2
#define rows 2
#define cols 2

int arrayA[rows1][cols1];
int arrayB[rows2][cols2];
int summatrix[rows][cols];

void printfmatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]);
void rastgeledeger(int arrayA[rows1][cols1],int arrayB[rows2][cols2]);
void carpimmatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]);
void toplammatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]);

int main(){
    srand(time(NULL));

    rastgeledeger(arrayA,arrayB);


    printf("***DIZI A ve B***\n");
    printfmatrix(arrayA, arrayB);

    printf("***TOPLAM MATRIXI***\n");
    toplammatrix(arrayA,arrayB);

    printf("\n***CARPIM MATRIXI***\n");
    carpimmatrix(arrayA,arrayB);
      
    return 0;
}

void printfmatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]){
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            printf("%d ",arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            printf("%d ",arrayB[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

void rastgeledeger(int arrayA[rows1][cols1],int arrayB[rows2][cols2] ){
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            arrayA[i][j]= rand() % 100 + 1;
        }
    }

    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            arrayB[i][j]= rand() % 100 + 1;
        }
    }
}

void carpimmatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]){
    
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            summatrix[i][j]=0;
            for(int k=0;k<rows2;k++){
                summatrix[i][j]+=arrayA[i][k]*arrayB[k][j];
            }
            
        }
    }


    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            printf("%d ",summatrix[i][j]);
        }
        printf("\n");
    }

}

void toplammatrix(int arrayA[rows1][cols1],int arrayB[rows2][cols2]){
    if(rows1!=rows2&&cols1!=cols2){
        printf("BU MATRIXLER TOPLANAMAZ CUNKU BOYUTLARI FARKLI.");
    }
    else{
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
                summatrix[i][j]=arrayA[i][j]+arrayB[i][j];
                
                 printf("%d ",summatrix[i][j]);
            }
        }
    }
    }
