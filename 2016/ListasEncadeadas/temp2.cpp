/*
Função : Exemplo simples de listas encadeadas
Autor : Edkallenn - Data : 06/04/2012
Observações:                                */
#include <stdio.h>
#include <stdlib.h>
#define QL printf("\n")
//definicao
struct lista{
    int info;
    struct lista* prox;
};
//sinonimo
typedef struct lista Lista;
//prototipos
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
Lista* lst_cria(void);

main(){

    Lista* l;               /* declara uma lista não inicializada */
    l = lst_cria();         /* cria e inicializa lista como vazia */
    l = lst_insere(l, 13);  /* insere na lista o elemento 13 */
    l = lst_insere(l, 45);  /* insere na lista o elemento 45 */
    l = lst_insere(l, 666); /* insere na lista o elemento 666*/
    lst_imprime(l);
    system("pause");
}

Lista* lst_cria(void){
    return NULL;
}
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}
void lst_imprime(Lista* l){
    Lista* p;   //variavel auxiliar para percorrer a lista
    for(p = l; p !=NULL; p = p->prox)
        printf("info = %d\n", p->info);
}
