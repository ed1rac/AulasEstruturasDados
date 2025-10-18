#include <stdio.h>
#include <math.h>

typedef struct
{
    char nome;
    float x;
    float y;
} Ponto;

// operações com pontos
Ponto criar_ponto(char nome, float x, float y);
float distancia(Ponto p1, Ponto p2);
void imprimir_ponto(Ponto p);

float distancia(Ponto p1, Ponto p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Ponto criar_ponto(char nome, float x, float y)
{
    Ponto p;
    p.nome = nome;
    p.x = x;
    p.y = y;
    return p;
}

void imprimir_ponto(Ponto p)
{
    printf("Ponto %c: (%.2f, %.2f)\n", p.nome, p.x, p.y);
}

int main()
{
    Ponto p1 = criar_ponto('A', 1.0, 2.0);
    Ponto p2 = criar_ponto('B', 4.0, 6.0);

    imprimir_ponto(p1);
    imprimir_ponto(p2);

    float d = distancia(p1, p2);
    printf("Distância entre %c e %c: %.2f\n", p1.nome, p2.nome, d);

    return 0;
}