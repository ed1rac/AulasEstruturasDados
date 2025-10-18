#include <stdio.h>

#define MAX 100

typedef struct
{
    int numeros[MAX];
    int quantidade;
} ListaInt;

void adicionar(ListaInt *l, int valor)
{
    if (l->quantidade < MAX)
    {
        l->numeros[l->quantidade++] = valor;
    }
}

int soma(ListaInt *l)
{
    int total = 0;
    for (int i = 0; i < l->quantidade; i++)
        total += l->numeros[i];
    return total;
}

int main()
{
    ListaInt l = {.quantidade = 0};
    adicionar(&l, 10);
    adicionar(&l, 20);
    adicionar(&l, 5);

    printf("Soma dos elementos: %d\n", soma(&l));
    return 0;
}
