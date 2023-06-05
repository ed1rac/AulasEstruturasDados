#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    float **matriz = (float **)malloc(linhas * sizeof(float *));
    if (matriz == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memoria\n");
            return 1;
        }
    }

    // Preencher a matriz com valores
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = i * j / 2.0;
        }
    }

    // Imprimir a matriz
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar a memoria alocada
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
