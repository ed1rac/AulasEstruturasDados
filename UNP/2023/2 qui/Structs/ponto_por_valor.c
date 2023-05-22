#include <stdio.h>
#define QL printf("\n")
//Funções envolvendo structs com passagem de parâmtros por valor
typedef struct ponto{
    char letra;
    float x;
    float y;
}Ponto;

void imprime(Ponto);
Ponto get_valores();

int main() {
    Ponto p;
    p = get_valores();
    imprime(p);
    getchar();   
    return 0;
}

void imprime(Ponto p){
  printf("O ponto digitado é: %c(%.2f, %.2f)\n", p.letra, p.x, p.y);
}

Ponto get_valores(){
  Ponto temp;
  printf("Digite a letra referente ao ponto: ");
  scanf(" %c", &temp.letra);
  printf("Digite as coordenadas do ponto %c(x,y): ", temp.letra);
  scanf(" %f, %f", &temp.x, &temp.y);
  return temp;
}


