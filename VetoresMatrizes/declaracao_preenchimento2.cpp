#include <stdio.h>
#include <stdlib.h>
/*  Função : Segundo contato com arrays (vetores)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: arquivo-> declaracao_preenchimento.cpp
*/
#define MAX 100  //tamanho maximo do vetor

main(){
    int x[MAX];
    int t;

    // Preenche o vetor
    for (t=0;t<MAX;++t)
        x[t]=t*2+1; //forma normal - impares

    //Exibe
    for (t=0;t<MAX;t++)
        printf("%-3d ", x[t]);

    getchar();
}
