#include <stdio.h>

typedef struct celula *link;

typedef struct celula
{ // estrutura autorreferenciada
    int info;
    link prox; // link é um ponteiro para um elemento igual a própria struct
} Celula;

int main(void)
{

    Celula *e1, *e2, *e3;

    e1 = (Celula *)malloc(sizeof(Celula)); // alocação dinamica de uma celula: e1
    e2 = (Celula *)malloc(sizeof(Celula)); // alocação dinamica de uma celula: e2
    e3 = (Celula *)malloc(sizeof(Celula)); // alocação dinamica de uma celula: e3

    e1->info = 4;
    e2->info = 5;
    e3->info = 6;
    // e1 --> e2 --> e3 --> NULL
    e1->prox = e2;
    e2->prox = e3;
    e3->prox = NULL;

    // percorrer o encadeamento
    Celula *temp;
    for (temp = e1; temp != NULL; temp = temp->prox)
    {
        printf("info = %d --> \t", temp->info);
    }
    printf("NULL\n");

    // percorrer os elementos para destruí-los
    for (temp = e1; temp != NULL; temp = e1)
    {
        e1 = e1->prox;
        free(temp);
    }

    return 0;
}