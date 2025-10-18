#include <stdio.h>
#include <stdlib.h>
/* função: bubbleSort
 * descrição: ordena um vetor de inteiros usando o algoritmo Bubble Sort
 * parâmetros: vetor - vetor a ser ordenado
 *             n - tamanho do vetor
 */
#define TAM 10
void ordena_bolha_int(int tamanho, int vetor[]);
void preenche_vetor(int tamanho, int vetor[]);
void imprime_vetor(int tamanho, int vetor[]);

int main()
{
    int vetor[TAM];
    preenche_vetor(TAM, vetor);
    printf("Vetor antes da ordenacao:\n");
    imprime_vetor(TAM, vetor);
    ordena_bolha_int(TAM, vetor);
    printf("Vetor depois da ordenacao:\n");
    imprime_vetor(TAM, vetor);
    printf("\n\n");
    return 0;
}

void preenche_vetor(int tamanho, int vetor[])
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf(" %d", &vetor[i]);
    }
}

void imprime_vetor(int tamanho, int vetor[])
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void ordena_bolha_int(int tamanho, int vetor[])
{
    int pass, i, aux;
    for (pass = 1; pass < tamanho; pass++)
    {
        for (i = 0; i <= tamanho - pass; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
            imprime_vetor(tamanho, vetor);
        }
    }
}
