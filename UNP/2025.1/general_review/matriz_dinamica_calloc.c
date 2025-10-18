#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas = 3, colunas = 3;
    int **matriz = (int **)calloc(linhas, sizeof(int *));
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)calloc(colunas, sizeof(int));
    }

    printf("Preenchendo matriz 3x3:\n");
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = i + j;

    printf("Matriz resultante:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) free(matriz[i]);
    free(matriz);
    return 0;
}
