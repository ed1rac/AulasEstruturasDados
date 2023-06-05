#include <stdio.h>
#include <stdlib.h>

void calculaMedia(Aluno *a);
void exibeAluno(Aluno a);
Aluno leAluno();

typedef struct
{
    int ra;
    char nome[50];
    float nota1, nota2, nota3;
    float media;
} Aluno;

int main()
{
    Aluno a = leAluno();
    calculaMedia(&a);
    exibeAluno(a);

    return 0;
}

void calculaMedia(Aluno *a)
{
    a->media = (a->nota1 + a->nota2 + a->nota3) / 3.0;
}

void exibeAluno(Aluno a)
{
    printf("RA: %d\n", a.ra);
    printf("Nome: %s\n", a.nome);
    printf("Nota 1: %.2f\n", a.nota1);
    printf("Nota 2: %.2f\n", a.nota2);
    printf("Nota 3: %.2f\n", a.nota3);
    printf("Media: %.2f\n", a.media);
}

Aluno leAluno()
{
    Aluno a;

    printf("Digite o RA do aluno: ");
    scanf("%d", &a.ra);
    printf("Digite o nome do aluno: ");
    getchar(); // Consumir o caractere '\n' deixado pelo scanf
    fgets(a.nome, 50, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0'; // Remover o caractere '\n' do final da string
    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &a.nota1);
    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &a.nota2);
    printf("Digite a nota 3 do aluno: ");
    scanf("%f", &a.nota3);

    return a;
}