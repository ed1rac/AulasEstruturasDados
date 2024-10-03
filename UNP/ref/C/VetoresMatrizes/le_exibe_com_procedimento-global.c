#include <stdio.h>
#include <stdlib.h>
/*  Função : Inicialização com inputs (vetores)
    Autor : Edkallenn  - Data : 06/04/2012
    Observações: procedimentos. O vetor é global
*/
#define MAX 5  //tamanho máximo do vetor

void preenche_vetor();   //protótipo das funções (procedimentos)
void exibe_vetor();       //protótipo alternativo (demonstra uso ponteiros)
int x[MAX]; //vetor

main(){    
    preenche_vetor();
    exibe_vetor();
    getchar();
}
void preenche_vetor(){  // Preenche o vetor
    int i;
    for (i=0;i<MAX;++i){   
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &x[i]);
    }
}
void exibe_vetor(){     //Exibe
    int t;
    printf("\nO vetor digitado eh\n");
    for (t=0;t<MAX;t++)
        printf("%-3d ", x[t]);
}
