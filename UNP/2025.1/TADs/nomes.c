#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nomes[MAX][50];
    int quantidade;
} Cadastro;

void adicionar(Cadastro *c, const char *nome)
{
    if (c->quantidade < MAX)
    {
        strcpy(c->nomes[c->quantidade], nome);
        c->quantidade++;
    }
}

void listar(Cadastro *c)
{
    printf("Lista de nomes:\n");
    for (int i = 0; i < c->quantidade; i++)
    {
        printf("- %s\n", c->nomes[i]);
    }
}

int main()
{
    Cadastro c = {.quantidade = 0};
    adicionar(&c, "Ana");
    adicionar(&c, "Carlos");
    adicionar(&c, "Beatriz");
    listar(&c);
    return 0;
}
