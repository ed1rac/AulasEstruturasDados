#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct {
    int matricula;
    char nome_aluno[50];
    char curso[40];
    float valor_parcela;
} Aluno;
 
 
Aluno lerDadosdoAluno();
 
 
void inserirAluno(Aluno *banco_alunos, int *n, Aluno novo_aluno);
 
 
void exibirAlunos(Aluno *banco_alunos, int n);
 
 
int main() {
    int n = 0;
    Aluno *banco_alunos = NULL;
    return 0;
}
 
 
Aluno lerDadosdoAluno() {
    Aluno a;
    printf("Digite a matricula: ");
    scanf("%d", &a.matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", a.nome_aluno);
    printf("Digite o curso: ");
    scanf("%s", a.curso);
    printf("Digite o valor da parcela: ");
    scanf("%f", &a.valor_parcela);
    return a;
}
 
 
void inserirAluno(Aluno *banco_alunos, int *n, Aluno novo_aluno) {
    banco_alunos = realloc(banco_alunos, (*n + 1) * sizeof(Aluno));
    if(banco_alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    banco_alunos[*n] = novo_aluno;
    (*n)++;
}
 
 
void exibirAlunos(Aluno *banco_alunos, int n) {
    for(int i = 0; i < n; i++) {
        printf("Matricula: %d\n", banco_alunos[i].matricula);
        printf("Nome: %s\n", banco_alunos[i].nome_aluno);
        printf("Curso: %s\n", banco_alunos[i].curso);
        printf("Valor da Parcela: %.2f\n", banco_alunos[i].valor_parcela);
    }
}