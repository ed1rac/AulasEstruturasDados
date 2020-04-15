#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Função : Exemplos de matrizes - random
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                                    */
#define LINHA 10
#define COLUNA 10
#define PULA printf("\n\n")

void lematriz_random(int b[][COLUNA], int, int, int);
void exibematriz(int b[][COLUNA], int, int);
void ordena_bolha_int(int a[][COLUNA], int linha, int coluna);
int random(int n);
main(){
    int b[LINHA][COLUNA];           //declara
    srand((unsigned)time(NULL));    //inicializa nos. aleatorios
    puts("Gera matriz randomica");
    PULA;
    lematriz_random(b, LINHA, COLUNA, 100);     //lê
    exibematriz(b, LINHA, COLUNA);  //exibe
  //  ordena_bolha_int(b, LINHA, COLUNA);
    PULA;
    exibematriz(b, LINHA, COLUNA);  //exibe
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
void exibematriz(int mat[][COLUNA], int lin, int col){
 int i, j;
 for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf(" %d\t", mat[i][j]);

        }printf("\n");
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
void ordena_bolha_int(int a[][COLUNA], int linha, int coluna){
    int pass, i, j, aux;
    for (pass=1;pass<(linha*coluna);pass++)  //passadas
        for(i=0;i<=linha-2;i++){    //uma passada
            for(j=0;j<coluna;j++){
            if(a[i*coluna+j]>a[(i*coluna+j)+1]){    //uma comparacao
                aux=a[(i*coluna+j)];       //uma permuta
                a[i*coluna+j]=a[(i*coluna+j)+1];
                a[(i*coluna+j)+1]=aux;
            }
        }
        }
}
