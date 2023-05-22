#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros, i, tamanho;
    printf("Digite o tamanho do array: ");
    scanf(" %d", &tamanho);
    printf("Tamanho: %d", tamanho);
    // alocação = reserva
    // array alocado dinamicamente
    numeros = (int *)malloc(tamanho * sizeof(int));
    if (numeros == NULL)
    {
        printf("Erro ao alocar a memoria!\n");
        exit(1);
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("preenchendo\n");
        numeros[i] = i + 1;
    }

    for (i = 0; i < tamanho; i++)
    {
        printf("exibindo\n");
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }

    free(numeros);

    return 1;
}