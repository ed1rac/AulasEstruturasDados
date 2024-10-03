#include <stdio.h>
#include <stdlib.h>
/*  Função : Inicialização com inputs (vetores) -
    Autor : Edkallenn  - Data : 06/04/2012
    Observações: Usa a passagem por referencia do primeiro elemento
    do vetor como parâmetro. Demonstra como o relacionamento entre ponteiros e
    matrizes é estreito em C.
*/
#define MAX 5               // tamanho máximo do vetor
void preenche_vetor(int[]); // protótipo das funcoes (procedimentos)
void exibe_vetor(int *);    // prototipo alternativo (demonstra uso ponteiros)
int main()
{
    int x[MAX];        // vetor
    preenche_vetor(x); // nome de um vetor é um ponteiro para o primeiro elemento desse vetor
    exibe_vetor(x);
    getchar();
    return 1;
}
void preenche_vetor(int *vet)
{ // Preenche o vetor
    int i;
    for (i = 0; i < MAX; ++i)
    { // quaisquer alteracoes aqui afetam x[MAX] (referencia)
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void exibe_vetor(int v[])
{ // Exibe
    int t;
    printf("\nO vetor digitado eh\n");
    for (t = 0; t < MAX; t++)
        printf("%-3d ", v[t]);
    printf("\n");
}
