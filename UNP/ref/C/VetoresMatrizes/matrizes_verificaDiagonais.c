#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Função : Exemplos de matrizes - random
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                                    */
#define LINHA 6
#define COLUNA 6
#define TAM 7
#define PULA printf("\n\n")

void lematriz_random(int b[][COLUNA], int, int, int);
void exibematriz(int b[][TAM], int);
int verificaDiagonais(int mat[][COLUNA], int lin, int col);
void preencheMatrizLosango(int mat[][TAM], int);

main(){
    int b[TAM][TAM];           //declara
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    preencheMatrizLosango(b, TAM);
    //lematriz_random(b, LINHA, COLUNA, 100);     //lê
    PULA;
    exibematriz(b, TAM);  //exibe
    PULA;
   /* if(verificaDiagonais(b,LINHA,COLUNA))
        printf("\nsao iguais\n");
    else
        printf("\nsao iguais\n");
    */

    getchar();
}
void lematriz_random(int mat[][COLUNA], int lin, int col, int n){
int i, j, valor;
for(i=0;i<lin;i++){             //linha
        for(j=0;j<col;j++){    //coluna
            valor = (1 + random(n-1));
            mat[i][j]=valor;
        }
    }
}
void exibematriz(int mat[TAM][TAM], int lin){
 int i, j;
 for(i=0;i<lin;i++){
        for(j=0;j<lin;j++){
            printf("%d\t", mat[i][j]);

        }printf("\n");
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}

int verificaDiagonais(int mat[][COLUNA], int lin, int col){
    int i, j;
    j=col-1;
    for (i=0;i<lin;i++){
        if(mat[i][i]!=mat[i][j]){
            return 0; //falso sao diferentes
        }
        j--;
    }
    return 1;
}

void preencheMatrizLosango(int mat[TAM][TAM], int tamanho){
   int i, j, meio, p1, p2;
   for (i=0;i<tamanho;i++){
    for (j=0;j<tamanho;j++){
        mat[i][j]=0;
    }
   }
   meio = tamanho/2;
   p1=meio;
   p2=meio;
   for(i=0;i<=meio;i++){
        mat[i][p1]=1;
        mat[i][p2]=1;
        mat[tamanho-1-i][p1--]=1;
        mat[tamanho-1-i][p2++]=1;
    }

}
