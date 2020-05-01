#include <stdio.h>
#include "lista.h"

int main(void){
    Lista* l;               //declara uma lista nao atualizada
    l = lst_cria();         //cria e inicializa lista como vazia
    l = lst_insere(l, 23);  //insere na lista o elemento 23
    l = lst_insere(l, 45);  //insere na lista o elemento 45
    l = lst_insere(l, 32);  //insere na lista o elemento 32
    l = lst_insere(l, 48);  //insere na lista o elemento 32
//  ...
    lst_imprime(l);
    l = lst_retira(l, 48);
    printf("\n");
    lst_imprime(l);
    lst_libera(l);
    return 0;
}
