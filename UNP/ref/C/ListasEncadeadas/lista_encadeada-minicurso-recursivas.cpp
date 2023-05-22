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
Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);
Lista* lst_insere_ordenado(Lista* l, int v);
Lista* lst_insere_ordenado_dec(Lista* l, int v);
void lst_imprime_rec(Lista* l);
void lst_imprime_rec2 (Lista* l);
void lst_libera_rec(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
Lista* lst_retira_rec(Lista* l, int v);
void lst_libera (Lista* l);
main(){
    Lista *l_nova;
    l_nova = lst_cria();
    int opcao, num;

    do{
        system("cls");
        printf("Programa de Lista Encadeada"); QL;
        printf("\t OPCOES \t"); QL;
        printf("1 - Inserir elementos na lista"); QL;
        printf("2 - Exibir elementos"); QL;
        printf("3 - Remove elementos"); QL;
        printf("5 - Sair");QL; QL;
        do{
            scanf("%d", &opcao);
        }while ((opcao!=1)&&(opcao!=2)&&(opcao!=3)&&(opcao!=5));
        if(opcao==1){
            QL; printf("Digite um numero para inserir na lista: ");
            scanf("%d", &num);
            l_nova = lst_insere_ordenado(l_nova, num);
            lst_imprime_rec(l_nova); system("pause");
        }
        if(opcao==2){
            QL; printf("Lista Encadeada digitada: ");QL;
            lst_imprime_rec(l_nova);
            system("pause");
        }
        if(opcao==3){
            QL; printf("Digite um numero a ser removido da lista: ");
            scanf("%d", &num);
            l_nova = lst_retira_rec(l_nova, num); QL; lst_imprime_rec2(l_nova);
            system("pause");
        }
    }while(opcao!=5);
  lst_libera_rec(l_nova);
  getchar();
}

//Função de criação
//Retorna uma lista vazia
Lista* lst_cria(void){
    return NULL;
}
//Insercao no inicio - retorna a lista atualizada
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}
//funcao vazia: retorna 1 se vazia ou 0 se nao vazia
int lst_vazia(Lista* l){
    return (l == NULL);
}

//funcao busca: busca um elemento na lista
Lista* lst_busca(Lista* l, int v){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;    //nao achou o elemento
}



Lista* lst_retira_rec (Lista* l, int v){
    if (!lst_vazia(l)) {
    /* verifica se elemento a ser retirado é o primeiro */
        if (l->info == v) {
            Lista* t = l; /* temporário para poder liberar */
            l = l->prox;
            free(t);
        }
        else {
            /* retira de sub-lista */
            l->prox = lst_retira_rec(l->prox,v);
        }
    }
    return l;
}



void lst_libera (Lista* l){
    Lista* p = l;
    while(p!=NULL){
        Lista* t = p->prox; //guarda referencia ao proximo elemento
        free(p);            //libera a memoria apontada por p
        p = t;              //faz p apontar para o proximo
    }
}

Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;  //ponteiro para elemento anterior
    Lista* p = l;       //ponteiro para percorrer a lista

    //procura posicao de insercao
    while(p != NULL && p->info < v){  //percorre naturalmente
        ant = p;
        p = p->prox;
    }

    //cria o novo elemento
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    //encadeia elemento
    if(ant == NULL){    //insere o elemento no inicio
        novo->prox = l;
        l = novo;
    }
    else{               //insere elemento no meio da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}
Lista* lst_insere_ordenado_dec(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;  //ponteiro para elemento anterior
    Lista* p = l;       //ponteiro para percorrer a lista

    //procura posicao de insercao
    while(p != NULL && p->info > v){  //percorre naturalmente
        ant = p;
        p = p->prox;
    }

    //cria o novo elemento
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    //encadeia elemento
    if(ant == NULL){    //insere o elemento no inicio
        novo->prox = l;
        l = novo;
    }
    else{               //insere elemento no meio da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

void lst_imprime_rec(Lista* l){
    if(lst_vazia(l))
        return;
    else{
        //imprime o primeiro elemento
        printf("info = %d\n", l->info);
        //imprime a sublista
        lst_imprime_rec(l->prox);
    }
}
//imprime recursiva
void lst_imprime_rec2 (Lista* l){
    if(!lst_vazia(l)){
        //imprime o primeiro elemento
        printf("info = %d\n", l->info);
        //imprime a sublista
        lst_imprime_rec2(l->prox);
    }
}
void lst_libera_rec(Lista* l){
    if(!lst_vazia(l)){
        lst_libera_rec(l->prox);
        free(l);
    }
}
