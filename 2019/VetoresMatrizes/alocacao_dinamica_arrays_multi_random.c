#include <stdio.h>
#include <stdlib.h>
/*  Função : Alocação dinâmica de arrays multidimensionais
    Autor : Edkallenn  - Data : 06/04/2012 */
#define LINHAS 8  //tamanho maximo do array
#define COLUNAS 4

int aleatorio(int n);

int main(){
    int **matriz;
    int i, j;
    //cria e lê o array
    matriz = (int**) malloc(LINHAS*sizeof(int*));  //cria as linhas
    for (i=0;i<LINHAS;i++){
        matriz[i]=(int *) malloc(COLUNAS*sizeof(int)); //cria as colunas
        for (j=0;j<COLUNAS;j++){
            //printf("Digite o elemento [%d][%d] do array: ",i,j);
            //scanf("%d", &matriz[i][j]);
            matriz[i][j] = aleatorio(100);
        }
    }
    printf("\n\nExibindo o array:\n\n"); //exibe o array    
    for(i=0;i<LINHAS;i++){
        for(j=0;j<COLUNAS;j++){
            printf("[%d][%d] = %d\t", i,j,matriz[i][j]);
        } printf("\n");
    }
    getchar();
}

int aleatorio(int n){
  return (rand() % n) + 1;
}