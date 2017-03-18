/* Funçăo : Pilhas usando vetores
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observaçőes:
*/
#include <stdio.h>
#include <stdlib.h>
#define QL printf("\n")

#define MAX 50 /* número máximo de elementos */
struct pilha {
    int n;          /* vet[n]: primeira posição livre do vetor */
    float vet[MAX];   /* vet[n-1]: topo da pilha */
                    /* vet[0] a vet[MAX-1]: posições ocupáveis */
};

typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);

Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}

void pilha_push (Pilha* p, float v)
{
    if (p->n == MAX) { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++; /* equivalente a: p->n = p->n + 1 */
}

float pilha_pop (Pilha* p)
{
        float v;
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    } /* aborta programa */
    /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

int pilha_vazia (Pilha* p)
{
    return (p->n == 0);
}

void pilha_libera (Pilha* p)
{
    free(p);
}
void pilha_imprime (Pilha* p){
    int i;
    for (i=p->n-1; i>=0; i--)
        printf("%f\n",p->vet[i]);
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
