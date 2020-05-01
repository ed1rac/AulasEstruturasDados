#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Função : Exemplos de matrizes - random
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                                    */
#define LINHA 6
#define COLUNA 6
#define PULA printf("\n\n")

void lematriz_random(int b[][COLUNA], int, int, int);
void exibematriz(int b[][COLUNA], int, int);
int aleatorio(int n);

main(){
    int b[LINHA][COLUNA];           //declara
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    lematriz_random(b, LINHA, COLUNA, 100);     //l�
    PULA;
    exibematriz(b, LINHA, COLUNA);  //exibe
    PULA;
    getchar();
}
void lematriz_random(int mat[][COLUNA], int lin, int col, int n){
int i, j, valor;
for(i=0;i<lin;i++){             //linha
        for(j=0;j<col;j++){    //coluna
            valor = (1 + aleatorio(n-1));
            mat[i][j]=valor;
        }
    }
}
void exibematriz(int mat[][COLUNA], int lin, int col){
 int i, j;
 for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("b[%d][%d]: %d\t", i, j, mat[i][j]);

        }printf("\n");
    }
}
int aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
