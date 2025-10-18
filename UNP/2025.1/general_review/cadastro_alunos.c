#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void listarRecursivo(Aluno *alunos, int n) {
    if (n == 0) return;
    listarRecursivo(alunos, n - 1);
    printf("Aluno %d:\n", n);
    printf("Nome: %s", alunos[n - 1].nome);
    printf("Idade: %d\n", alunos[n - 1].idade);
    printf("Nota: %.2f\n\n", alunos[n - 1].nota);
}

float mediaNotas(Aluno *alunos, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += alunos[i].nota;
    return soma / n;
}

int main() {
    int n;
    printf("Quantos alunos deseja cadastrar? ");
    scanf(" %d", &n);
    getchar(); // limpar buffer

    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, 50, stdin);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        getchar(); // limpar buffer
    }

    printf("\n--- Lista de Alunos (Recursiva) ---\n");
    listarRecursivo(alunos, n);

    printf("Média das notas: %.2f\n", mediaNotas(alunos, n));

    free(alunos);
    return 0;
}
