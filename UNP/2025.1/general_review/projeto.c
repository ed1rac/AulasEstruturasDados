#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void imprimirRecursivo(Pessoa pessoas[], int n) {
    if (n == 0) return;
    imprimirRecursivo(pessoas, n - 1);
    printf("Pessoa %d: %sIdade: %d\n", n, pessoas[n - 1].nome, pessoas[n - 1].idade);
}

float mediaIdades(Pessoa pessoas[], int n) {
    int soma = 0;
    int i;
    for ( i = 0; i < n; i++)
        soma += pessoas[i].idade;
    return (float)soma / n;
}

int main() {
    int n;
    printf("Quantas pessoas? ");
    scanf("%d", &n);
    getchar(); // limpa buffer

    Pessoa lista[n];
    int i;
    for ( i = 0; i < n; i++) {
        printf("Nome: ");
        fgets(lista[i].nome, 50, stdin);
        printf("Idade: ");
        scanf("%d", &lista[i].idade);
        getchar(); // limpa buffer
    }

    printf("\n--- Listagem Recursiva ---\n");
    imprimirRecursivo(lista, n);

    printf("\nMédia das idades: %.2f\n", mediaIdades(lista, n));
    return 0;
}
