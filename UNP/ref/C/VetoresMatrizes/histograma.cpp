#include <stdio.h>
#include <stdlib.h>
/*  Função : Programa para imprimir histograma
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: Programa interessante para imprimir histograma!
*/
#define TAMANHO 10  //tamanho maximo do vetor

main(){
    int n[TAMANHO] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
    int i, j;

    printf("%s%13s%17s\n", "Elemento", "Valor", "Histograma");

    for(i = 0;i<TAMANHO;i++)
    {
        printf("%8d%13d       ", i, n[i]);   // 07 espacos em branco

        for(j = 1;j<=n[i];j++)   //Imprime uma barra de asteriscos
            printf("%c", '*');

            printf("\n");

    }
    //no DevC++ coloque aqui system("pause"); ou getchar();
    return 0;
}
