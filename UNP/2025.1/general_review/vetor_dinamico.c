#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL;
    int tamanho = 0, valor;

    printf("Digite números inteiros (negativo para parar):\n");

    while (1) {
        scanf("%d", &valor);
        if (valor < 0) break;

        int *temp = realloc(vetor, (tamanho + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Erro de alocação.\n");
            free(vetor);
            return 1;
        }
        vetor = temp;
        vetor[tamanho++] = valor;
    }

    printf("Valores inseridos:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);

    free(vetor);
    return 0;
}
