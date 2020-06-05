#include <stdio.h>
#define QL printf("\n")
//Funções envolvendo structs com passagem de parâmtros por referência
typedef struct ponto{
    char letra;
    float x;
    float y;
}Ponto;

void imprime(Ponto*);
void get_valores(Ponto*);

int main() {
    Ponto p;
    get_valores(&p);
    imprime(&p);
    getchar();   
    return 0;
}

void imprime(Ponto* pp){
  printf("O ponto digitado é: %c(%.2f, %.2f)\n", pp->letra, pp->x, pp->y);
}

void get_valores(Ponto* pp){
  printf("Digite a letra referente ao ponto: ");
  scanf(" %c", &pp->letra);
  printf("Digite as coordenadas do ponto %c(x,y): ", pp->letra);
  scanf(" %f, %f", &pp->x, &pp->y);  
}


