#include <stdio.h>
#include <stdlib.h>

typedef struct lista* link;

typedef struct lista{
  int info;
  link prox;
}Lista;
//protótipos
Lista* lst_cria();
Lista* lst_insere(Lista *lista, int valor);
void lst_imprime(Lista *l);
int lst_vazia(Lista *l);
void mensagem_vazia(Lista* lista);
Lista* lst_busca(Lista* lista, int valor);

Lista* lst_cria(){
  return NULL;
}

Lista* lst_insere(Lista* lista, int valor){
  Lista* novo = (Lista*) malloc(sizeof (lista));
  novo->info = valor;
  novo->prox = lista;
  return novo;
}

void lst_imprime(Lista *l){
  Lista *temp;
  for(temp = l; temp != NULL; temp = temp->prox)
  {
    printf("|\t%d\t| -->", temp ->info);
  }
  printf("| NULL | \n");
}

int lst_vazia(Lista *lista){
  return lista == NULL;
}

void mensagem_vazia(Lista* lista){
  if(!lst_vazia(lista)){
    printf("Lista não vazia\n");
    return;
  }
  printf("Lista vazia\n");
}

Lista* lst_busca(Lista* lista, int valor){
  Lista* temp;
  for(temp=lista; temp!=NULL; temp = temp->prox){
    if(temp->info == valor)
      return temp;
  }
  return NULL;
}
int main(){
  Lista *p; int num;
  mensagem_vazia(p);
  p = lst_cria();
   lst_imprime(p);
  p = lst_insere(p, 4);
   lst_imprime(p);
  p = lst_insere(p, 5);
   lst_imprime(p);
  p = lst_insere(p, 6);
  lst_imprime(p);
  p = lst_insere(p, 7);
  lst_imprime(p);
  mensagem_vazia(p);
  printf("\nDigite um elemento para eu buscar na lista: "); scanf(" %d", &num);
  if(lst_busca(p, num)){
    printf("\nO elemento %d está na lista!\n", num);    
  }else printf("\nO elemento %d não está na lista!\n", num);
  return 0;
}