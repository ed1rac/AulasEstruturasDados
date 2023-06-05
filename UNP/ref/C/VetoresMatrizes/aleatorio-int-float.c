#include <stdlib.h>
#include <time.h>

void preencher_aleatorio_int(int *array, int tamanho, int limite)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = rand() % limite;
    }
}

void preencher_aleatorio_float(float *array, int tamanho, float limite)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = (float)rand() / RAND_MAX * limite;
    }
}

int main()
{
    int n;
    printf("Digite o tamanho do array (de inteiros): ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    // tamanho do array
    int tamanho = (int)(sizeof(array) / sizeof(array[0]));
    // exibir o tamanho do array
    printf("Tamanho do array: %d\n", tamanho);
    if (array == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    preencher_aleatorio_int(array, n, 100);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);

    printf("Digite o tamanho do array (de float): ");
    scanf("%d", &n);
    float *array2 = (float *)malloc(n * sizeof(float));
    // tamanho do array
    tamanho = (int)(sizeof(array2) / sizeof(array2[0]));
    // exibir o tamanho do array
    printf("Tamanho do array: %d\n", tamanho);
    if (array2 == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    preencher_aleatorio_float(array2, n, 100.0);
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", array2[i]);
    }
    printf("\n");
    free(array2);

    return 1;
}
