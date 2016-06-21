/*  Funçăo : Pilhas usando lista linear
    Autor : Edkallenn
    Data : 06/04/2012
    Observaçőes:
*/
#include <stdio.h>
#include <stdlib.h>
#define QL printf("\n")

/* nó da lista para armazenar valores reais */
struct lista {
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

/* estrutura da pilha */
struct pilha {
    Lista* prim;    /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);
int pilha_vazia (Pilha* p);

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

float pilha_pop (Pilha* p){
    Lista* t;
    float v;
    if (pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);    /* aborta programa */
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void pilha_libera (Pilha* p){
    Lista* q = p->prim;
    while (q!=NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}


int pilha_vazia (Pilha* p)
{
    return (p->prim==NULL);
}

/* imprime: versão com lista */
void pilha_imprime (Pilha* p)
{
    Lista* q;
    for (q=p->prim; q!=NULL; q=q->prox)
    printf("%f\n",q->info);
}

main(){

    Pilha* nova_pilha;

    nova_pilha = pilha_cria();
    pilha_push(nova_pilha, 25);
    pilha_push(nova_pilha, 15);
    pilha_push(nova_pilha, 40);
    pilha_push(nova_pilha, 60);
    pilha_push(nova_pilha, 13.56);
    printf("Pilha Original: "); QL;
    pilha_imprime(nova_pilha);  QL;
    pilha_pop(nova_pilha);
    printf("Pilha Original apos um pop(): "); QL;
    pilha_imprime(nova_pilha);
    pilha_push(nova_pilha, 75);
    printf("Pilha Original apos um push(): "); QL;
    pilha_imprime(nova_pilha);
    pilha_pop(nova_pilha);
    printf("Pilha Original apos um pop(): "); QL;
    pilha_imprime(nova_pilha);

    pilha_libera(nova_pilha);

}
