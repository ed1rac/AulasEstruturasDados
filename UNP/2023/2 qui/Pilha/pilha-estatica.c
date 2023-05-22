#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct pilha
{
    int topo;
    int data[N];
} Pilha;

Pilha *novaPilha();
void push(Pilha *p, int value);
int pop(Pilha *p);
int peek(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void exibe_topo(Pilha *p);

int main()
{
    int num1;
    Pilha *p;
    p = novaPilha();
    if (pilha_vazia(p))
    {
        printf("Pilha está vazia\n");
    }
    num1 = peek(p);
    push(p, 10);
    exibe_topo(p);
    push(p, 20);
    exibe_topo(p);
    push(p, 30);
    exibe_topo(p);
    push(p, 40);
    exibe_pilha(p);

    if (!pilha_cheia(p))
    {
        printf("Pilha não está cheia\n");
    }
    return 1;
}

Pilha *novaPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int pilha_vazia(Pilha *p)
{
    return p->topo == 0;
}

int pilha_cheia(Pilha *p)
{
    return p->topo == N;
}
void push(Pilha *p, int valor)
{
    if (pilha_cheia(p))
    {
        printf("Stack overflow - Pilha cheia\nNão é possível inserir!\n");
        return;
    }
    p->data[p->topo] = valor;
    p->topo++;
}
int pop(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\nNão é possível remover!\n");
        return -1;
    }
    p->topo--;
    return p->data[p->topo];
}
int peek(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\nNão é possível observar!\n");
        return -1;
    }
    return p->data[p->topo - 1];
}
void exibe_topo(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\nNão é possível exibir!\n");
        return;
    }
    printf("Topo: %d\n", p->data[p->topo - 1]);
}

void exibe_pilha(Pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\nNão é possível exibir!\n");
        return;
    }
    printf("Exibindo a Pilha toda: ");
    for (int i = 0; i < p->topo; i++)
    {
        printf("%d ", p->data[i]);
    }
    printf("\n");
}