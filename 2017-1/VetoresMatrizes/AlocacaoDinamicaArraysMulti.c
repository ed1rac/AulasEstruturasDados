#include <stdio.h>
#include <stdlib.h>
/*  Função : Alocação dinâmica de arrays multidimensionais
    Autor : Edkallenn  - Data : 06/04/2012 */
#define N 3  //tamanho maximo do array

main(){
    int **p;
    int i, j;
    //cria e lê o array
    p = (int**) malloc(N*sizeof(int*));  //cria as linhas
    for (i=0;i<N;i++){
        p[i]=(int *) malloc(N*sizeof(int)); //cria as colunas
        for (j=0;j<N;j++){
            printf("Digite o elemento [%d][%d] do array: ",i,j);
            scanf("%d", &p[i][j]);
        }
    }
    printf("\n\nExibindo o array:\n\n");
    //exibe o array
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("[%d][%d] = %d\t", i,j,p[i][j]);
        } printf("\n");
    }

    getch();
}

