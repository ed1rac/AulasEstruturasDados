/* Função : Exemplo do uso de Listas Encadeadas
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações:
*/
#include <stdio.h>
#include <stdlib.h>

//definicao
struct lista{
    int info;
    struct lista* prox;
};
//sinonimo
typedef struct lista Lista;



Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
Lista* lst_retira(Lista* l, int v);
void lst_libera (Lista* l);
Lista* lst_insere_ordenado(Lista* l, int v);
void lst_imprime_rec(Lista* l);
void lst_imprime_rec2(Lista* l);
Lista* lst_retira_rec (Lista* l, int v);
void lst_libera_rec(Lista* l);
int lst_igual (Lista* l1, Lista* l2);
int lst_igual_rec (Lista* l1, Lista* l2);
void lcirc_imprime (Lista* l);

int lst_conta_elemento(Lista* l, int v);


//Funcao de Criacao - retorna uma lista vazia
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

//funcao imprime: imprime valores dos elementos
void lst_imprime(Lista* l){
    Lista* p;   //variavel auxiliar para percorrer a lista
    for(p = l; p !=NULL; p = p->prox)
        printf("info = %d\n", p->info);
}
/*
//funcao vazia: retorna 1 se vazia ou 0 se nao vazia
int lst_vazia(Lista* l){
    if (l == NULL)
        return 1;
    else
        return 0;
}
*/
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

int lst_conta_elemento(Lista* l, int v){
    Lista* p; int i=0;
    for(p=l;p!=NULL;p=p->prox){
        i++;
        if(p->info == v)
            return i;
    }
}

//função para retornar a quantidade de elementos de uma lista encadeada
int lst_contaElementos(Lista* l){
    Lista* p;
    if(lst_vazia(l))
        return 0;
    else{
        int i=0;
        for(p=l;p!=NULL;p=p->prox){
            i++;
        }
        return i;
    }
}




//funcao retira: retira elemento da lista
Lista* lst_retira(Lista* l, int v){
    Lista* ant = NULL;  //ponteiro para elemento anterior
    Lista* p = l;       //ponteiro para percorrer a lista

    //procura elemento na lista, guardando o anterior
    while (p!=NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    //verifica se achou o elemento
    if(p == NULL)
        return l;   //nao achou: retorna lista original

    //retira o elemento
    if(ant == NULL){
        //retira o elemento do inicio
        l = p->prox;
    }
    else{
        //retira o elemento do meio da lista
        ant->prox = p->prox;
    }
    free(p);
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

int main(void){
    Lista* l;               //declara uma lista nao atualizada
    l = lst_cria();         //cria e inicializa lista como vazia
    l = lst_insere(l, 23);  //insere na lista o elemento 23
    l = lst_insere(l, 45);  //insere na lista o elemento 45
    l = lst_insere(l, 32);  //insere na lista o elemento 32
    l = lst_insere(l, 48);  //insere na lista o elemento 32
    l = lst_insere(l, 33);  //insere na lista o elemento 32

    lst_imprime(l);
    printf("\nA lista tem %d elementos\n", lst_contaElementos(l));

    //para buscar um elemento
    int num;
    printf("\nDigite um elemento para eu buscar na lista: ");
    scanf("%d", &num);

    if(lst_busca(l,num)){
        printf("\nO numero %d esta na lista!\n", num);
        int posicao;
        posicao = lst_conta_elemento(l, num);
        printf("\nO numero %d esta na Posicao %d!\n", num, posicao);
        lst_retira(l, num);
    }else
        printf("\nO numero %d nao esta na lista!\n", num);


//  ...
/*
   l = lst_retira_rec(l, 48);
    printf("\n");
    lst_imprime(l);
    l = lst_retira_rec(l, 32);
    printf("\n");
    lst_imprime(l);
    l = lst_retira_rec(l, 45);
    printf("\n");
    lst_imprime_rec(l);
    printf("\n");

    l = lst_insere_ordenado(l, 48);
    l = lst_insere_ordenado(l, 32);
    l = lst_insere_ordenado(l, 45);
    lst_imprime_rec(l);
    printf("\n");
   // lcirc_imprime(l);
*/
    lst_imprime(l);
    getchar();
    lst_libera_rec(l);
    return 0;
}
/*
//insercao no inicio: atualiza valor da lista
void lst_insere(Lista** l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = *l;
    *l = novo;
}
Lista* l = lst_cria();  //cria lista vazia
lst_insere(&l, 23);     //insere o elemento 23
*/
/*funcao insere_ordenado: insere o elemento em ordem*/
Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;  //ponteiro para elemento anterior
    Lista* p = l;       //ponteiro para percorrer a lista

    //procura posicao de insercao
    while(p != NULL && p->info < v){
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

//Funcao imprime recursividade
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
/* Fun��o retira recursiva */
Lista* lst_retira_rec (Lista* l, int v){
    if (!lst_vazia(l)) {
    /* verifica se elemento a ser retirado � o primeiro */
        if (l->info == v) {
            Lista* t = l; /* tempor�rio para poder liberar */
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

void lst_libera_rec(Lista* l){
    if(!lst_vazia(l)){
        lst_libera_rec(l->prox);
        free(l);
    }
}

int lst_igual (Lista* l1, Lista* l2){
    Lista* p1; /* ponteiro para percorrer l1 */
    Lista* p2; /* ponteiro para percorrer l2 */
    for (p1=l1, p2=l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox)
    {
        if (p1->info != p2->info)
            return 0;
    }
    return p1==p2;
}

//compara recursiva
int lst_igual_rec (Lista* l1, Lista* l2){
    if (l1 == NULL && l2 == NULL)
        return 1;
    else if (l1 == NULL || l2 == NULL)
            return 0;
        else
            return l1->info == l2->info && lst_igual(l1->prox, l2->prox);
}

/* fun��o imprime: imprime valores dos elementos */
void lcirc_imprime (Lista* l){
    Lista* p = l; /* faz p apontar para o n� inicial */
    /* testa se lista n�o � vazia e ent�o percorre com do-while */
    if (p) do {
        printf("%d\n", p->info); /* imprime informa��o do n� */
        p = p->prox; /* avan�a para o pr�ximo n� */
    } while (p != l);
}
