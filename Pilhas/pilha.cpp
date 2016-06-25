/* Fun��o : Exemplo do uso de pilhas
/ Autor : Edkallenn
/ Data : 12/06/2012
/ Observa��es:
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 50      // n�mero m�ximo de elementos

struct pilha {
    int n;        // vet[n]: primeira posi��o livre do vetor
    float vet[TAM]; // vet[n-1]: topo da pilha
                  // vet[0] a vet[N-1]: posi��es ocup�veis
};
typedef struct pilha Pilha;

//prototipos
Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);

Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;       /* inicializa com zero elementos */
    return p;
}

void pilha_push (Pilha* p, float v)
{
    if (p->n == TAM) {    /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1);    /* aborta programa */
    }
        /* insere elemento na pr�xima posi��o livre */
        p->vet[p->n] = v;
        p->n++;     /* equivalente a: p->n = p->n + 1 */
}

float pilha_pop (Pilha* p)
{
    float v;
    if (pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }   /* aborta programa */
    /* retira elemento do topo */
    v = p->vet[p->n-1]; //acessa o topo da pilha
    p->n--;
    return v;
}

int pilha_vazia(Pilha* p)
{
    return (p->n == 0);
}

void pilha_libera(Pilha* p)
{
    free(p);
}

void pilha_imprime(Pilha* p){
    int i;
    for(i=p->n-1;i>=0;i--)
         printf("%f\n", p->vet[i]);

}

int main(){
    Pilha *a, stack;
    a = pilha_cria();
    pilha_push(a, 12.5);
    pilha_push(a, 0.5);
    pilha_push(a, 11);
    pilha_push(a, 4);
    pilha_imprime(a);

    return(0);
}
