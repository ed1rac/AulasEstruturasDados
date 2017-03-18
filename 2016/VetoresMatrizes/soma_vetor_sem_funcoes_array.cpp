#include <stdio.h>
#include <stdlib.h>
/*  Função : Soma de elementos de um vetor sem funcoes
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/
#define MAX 12

main(){
    //incializacao do vetor vet. Poderia ter sido vet[] = { valores };
    int i, vet[MAX] = {-45, 6, 0, 72, 1543, -89, 0, 62, -3, 1, 6453, 78};
    int j, s=0, soma;

    for(i=0;i<MAX;i++){  //Exibe o vetor
        printf("O elemento %d do vetor eh: %d\n", i, vet[i]);
    }
    for(j=0;j<MAX;j++){ // Soma os elementos
        s+=vet[j];
    }
    soma=s;

    printf("\n\nA soma dos elementos do vetor eh: %d\n\n", soma);
    printf("A media dos elementos do vetor eh: %d\n\n", soma/MAX);

}
