#include <stdio.h>

int main()
{
    int i, tamanho;

    printf("Digite um tamanho de array [máx: 100]");
    scanf(" %d", &tamanho);

    int array[tamanho];
    for (i = 0; i < tamanho; i++)
    {
        array[i] = 2 * i + 1;
        printf("Endereço de array[%d] = %p\n", i, &array[i]);
    }
    printf("\n============================\n");
    // exibindo
    for (int i = 0; i < tamanho; i++)
    {
        printf("array[%d] = %d\n", i + 1, array[i]);
    }
    return 1;
}
