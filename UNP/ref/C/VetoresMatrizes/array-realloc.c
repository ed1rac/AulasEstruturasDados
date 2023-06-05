#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite o tamanho inicial do array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    // Preencher o array com valores
    for (int i = 0; i < n; i++)
    {
        array[i] = i * 2;
    }

    // Imprimir o array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Realocar o array para um tamanho maior
    int m;
    printf("Digite o tamanho final do array: ");
    scanf("%d", &m);

    int *temp = (int *)realloc(array, m * sizeof(int));
    if (temp == NULL)
    {
        printf("Erro ao realocar memoria\n");
        free(array);
        return 1;
    }
    array = temp;

    // Preencher o restante do array com valores
    for (int i = n; i < m; i++)
    {
        array[i] = i * 2;
    }

    // Imprimir o array
    for (int i = 0; i < m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar a memoria alocada
    free(array);

    return 0;
}
