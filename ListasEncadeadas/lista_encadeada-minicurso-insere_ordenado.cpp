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
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
Lista* lst_retira(Lista* l, int v);
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
            l_nova = lst_insere_ordenado_dec(l_nova, num);
        }
        if(opcao==2){
            QL; printf("Lista Encadeada digitada: ");QL;
            lst_imprime(l_nova);
            system("pause");
        }
        if(opcao==3){
            QL; printf("Digite um numero a ser removido da lista: ");
            scanf("%d", &num);
            l_nova = lst_retira(l_nova, num); QL; lst_imprime(l_nova);
            system("pause");
        }
    }while(opcao!=5);
  lst_libera(l_nova);
  getchar();
}
    /*l_nova = lst_insere(l_nova, 13);
    l_nova = lst_insere(l_nova, 45);
    l_nova = lst_insere(l_nova, 666);
    lst_imprime(l_nova);
    lst_retira(l_nova, 45); QL;
    lst_imprime(l_nova);
    lst_libera(l_nova);*/
//}

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
