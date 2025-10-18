#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidade = 100;
    int *numeros = malloc(capacidade * sizeof(int));
    int n = 0, valor;

    printf("Digite até 100 números (negativo para parar):\n");
    while (n < capacidade) {
        scanf("%d", &valor);
        if (valor < 0) break;
        numeros[n++] = valor;
    }

    // Redimensionar para o número real de elementos usados
    numeros = realloc(numeros, n * sizeof(int));

    printf("Números armazenados:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", numeros[i]);

    free(numeros);
    return 0;
}
