#include <stdio.h>

typedef int inteiro;

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char nome[50];
    inteiro idade;
    Data data_nascimento;
} Pessoa;

int main()
{
    Pessoa p;
    p.data_nascimento.dia = 7;
    p.data_nascimento.mes = 7;
    p.data_nascimento.ano = 1980;
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    printf("Digite a idade: ");
    scanf(" %d", &p.idade);

    printf("Nome: %s - Idade: %d\n", p.nome, p.idade);
    printf("Data de Nascimento: %02d/%02d/%04d\n", p.data_nascimento.dia, p.data_nascimento.mes, p.data_nascimento.ano);
    return 0;
}
