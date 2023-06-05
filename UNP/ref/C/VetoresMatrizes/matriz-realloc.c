#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
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
            matriz[i][j] = i * j * 0.5;
        }
    }

    // Imprimir a matriz
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Realocar a matriz para um tamanho maior
    int novas_linhas, novas_colunas;
    printf("Digite o numero de novas linhas da matriz: ");
    scanf("%d", &novas_linhas);
    printf("Digite o numero de novas colunas da matriz: ");
    scanf("%d", &novas_colunas);

    float **temp = (float **)realloc(matriz, novas_linhas * sizeof(float *));
    if (temp == NULL)
    {
        printf("Erro ao realocar memoria\n");
        for (int i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
        return 1;
    }
    matriz = temp;

    for (int i = linhas; i < novas_linhas; i++)
    {
        matriz[i] = (float *)malloc(novas_colunas * sizeof(float));
        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memoria\n");
            return 1;
        }
    }

    for (int i = 0; i < novas_linhas; i++)
    {
        for (int j = colunas; j < novas_colunas; j++)
        {
            matriz[i][j] = i * j * 0.5;
        }
    }

    // Imprimir a matriz
    for (int i = 0; i < novas_linhas; i++)
    {
        for (int j = 0; j < novas_colunas; j++)
        {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar a memoria alocada
    for (int i = 0; i < novas_linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
