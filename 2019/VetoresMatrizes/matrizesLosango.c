#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 7
#define PULA printf("\n\n")

void exibematriz(int b[][TAM], int);
void preencheMatrizLosango(int mat[][TAM], int);

main(){

    getchar();
}
void exibematriz(int mat[][COLUNA], int lin, int col){
 int i, j;
 for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d\t", i, j, mat[i][j]);

        }printf("\n");
    }
}
