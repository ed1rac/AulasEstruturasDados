#include <stdio.h>
#include <stdlib.h>
/*  Função : Inicializacao com inputs (vetores)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: arquivo-> declaracao_preenchimento_com_input.cpp
*/
#define MAX 10  //tamanho maximo do vetor
main(){
    int x[MAX];
    int i, t;

    // Preenche o vetor
    for (i=0;i<MAX;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &x[i]);
    }
    //Exibe
    printf("\nO vetor digitado eh\n");
    for (t=0;t<MAX;t++)
        printf("%-3d ", x[t]);
    printf("\n");
    getchar();
}
