#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite o tamanho do array: ");
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

    // Liberar a memoria alocada
    free(array);

    return 0;
}
