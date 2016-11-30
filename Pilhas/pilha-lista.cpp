/* Função : Exemplo do uso de pilhas
/ Autor : Edkallenn
/ Data : 12/06/2012
/ Observações:
*/
#include <stdio.h>
#include <stdlib.h>


/* nó da lista para armazenar valores reais */
struct lista {
    float info;
    struct lista* prox;
};

typedef struct lista Lista;

/* estrutura da pilha */

struct pilha {
    Lista* prim; /* aponta para o topo da pilha */
};

typedef struct pilha Pilha;

//prototipos
Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime(Pilha* p);

Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push (Pilha* p, float v)
{
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}


float pilha_pop (Pilha* p)
{
    Lista* t;
    float v;
    if (pilha_vazia(p))
        {
            printf("Pilha vazia.\n");
            exit(1);
        } /* aborta programa */
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}



void pilha_libera (Pilha* p)
{
    Lista* q = p->prim;
    while (q!=NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

int pilha_vazia(Pilha* p)
{
    return (p->prim == NULL);
}

//versao com lista
void pilha_imprime(Pilha* p){
    Lista* q;
    for (q=p->prim;q!=NULL;q=q->prox)
        printf("%f\n", q->info);
}

int main(){
    Pilha *c = pilha_cria();
    pilha_push(c, 12.5);
    pilha_push(c, 0.5);
    pilha_push(c, 11);
    pilha_push(c, 4);
    pilha_imprime(c); printf("\n");
    pilha_pop(c);
    pilha_imprime(c);

    return(0);
}
