#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    char nome;
    float x, y;
} Ponto;

Ponto le_ponto();
void exibe_ponto(Ponto p);

int main(void)
{
    Ponto p1, p2, *pontos;
    pontos = (Ponto *)malloc(sizeof(Ponto) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        pontos[i] = le_ponto();
    }
    for (int i = 0; i < MAX; i++)
    {
        exibe_ponto(pontos[i]);
    }
    return 0;
}

Ponto le_ponto()
{
    Ponto temp;
    printf("Digite a letra que representa o ponto: ");
    scanf(" %c", &temp.nome);
    printf("Digite o valor da abscissa x: ");
    scanf(" %f", &temp.x);
    printf("Digite o valor da ordenada y: ");
    scanf(" %f", &temp.y);
    return temp;
}

void exibe_ponto(Ponto p)
{
    printf("Ponto %c(%f, %f)\n", p.nome, p.x, p.y);
}