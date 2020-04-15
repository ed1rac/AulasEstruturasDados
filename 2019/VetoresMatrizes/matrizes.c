#include <stdio.h>
#include <stdlib.h>
/*  Função : Exemplos de matrizes
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                        ERRADO!            */
#define LINHA 4
#define COLUNA 3

main(){
    int i, j, b[LINHA][COLUNA];
    //lê
    for(i=0;i<LINHA;i++){             //linha
        for(j=0;j<COLUNA;j++){    //coluna
            printf("Digite o elemento b[%d][%d]:", i+1, j+1);
            scanf("%d, %d", &b[i][j]);
        }
    }
    printf("\n\n");

    //exibe
    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            printf("b[%d][%d]: %d\t", i, j, b[i][j]);

        }printf("\n");
    }

    printf("\n\n");
    getchar();
}
