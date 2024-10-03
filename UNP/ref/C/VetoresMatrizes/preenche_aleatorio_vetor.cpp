#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100 // tamanho máximo do vetor
/*  Função : Preenche vetor com números aleatórios (vetores)
    Autor : Edkallenn  - Data : 06/04/2012
    Observações: Usa a função rand() e srand para gerar números aleatórios
*/
void preenche_vetor_random(int[]); // prototipação das funções
void exibe_vetor_int(int[]);
int random(int n);

void exibe_vetor_int(int *v)
{ // Exibe o vetor
    int t;
    printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t = 0; t < MAX; t++)
        printf("%-3d\t", v[t]);
}
void preenche_vetor_random(int vet[])
{ // Preenche com valores randômicos
    int i, valor;
    for (i = 0; i < MAX; ++i)
    {
        valor = (random(200)); // gera ate 200
        vet[i] = valor;
    }
}
int random(int n)
{ // função para gerar aleatórios
    return rand() % n + 1;
}

int main()
{
    int x[MAX];        // vetor original
    srand(time(NULL)); // inicializa gerador de nos. aleatórios
    preenche_vetor_random(x);
    exibe_vetor_int(x);
    getchar();
    return 0;
}
