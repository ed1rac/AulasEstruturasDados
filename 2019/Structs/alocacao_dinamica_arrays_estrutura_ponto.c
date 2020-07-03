#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
  char nome;
  float x, y;
}Ponto; 

void exibe_ponto(Ponto p);
Ponto leia_ponto();
void mostra(Ponto *pp);
void leia(Ponto *pp);

int main(void) {

  Ponto p, q;
  Ponto* pontos;
  int i;

  printf("tamanho: %lu", sizeof(Ponto));
  //alocação dinâmica de estruturas
  pontos = (Ponto*) malloc(5*sizeof(Ponto));

  printf("\n");

  for (i =0;i<5;i++){
    Ponto temp;
    temp = leia_ponto();
    pontos[i] = temp;
  }
  for (i =0;i<5;i++){
    exibe_ponto(pontos[i]);
  }

  return 0;
}
void exibe_ponto(Ponto p){
  printf("Ponto..: %c(%.2f, %.2f)\n", p.nome, p.x, p.y);  
}
Ponto leia_ponto(){  //função que retorna um registro (estrutura)
  Ponto temp;
  printf("Digite o nome do ponto (Ex: A): ");
  scanf(" %c", &temp.nome);
  printf("Digite os valores de x e y do ponto %c: ", temp.nome);
  scanf(" %f, %f", &temp.x, &temp.y);
  return temp;
}

void mostra(Ponto *pp){
  printf("Ponto..: %c(%.2f, %.2f)\n", pp->nome, pp->x, pp->y);  
}

void leia(Ponto *pp){  
  printf("Digite o nome do ponto (Ex: A): ");
  scanf(" %c", &pp->nome);
  printf("Digite os valores de x e y do ponto %c: ", pp->nome);
  scanf(" %f, %f", &pp->x, &pp->y);
}