#include <stdio.h>
#include <math.h>
#define QL printf("\n")
//Funções envolvendo structs com passagem de parâmtros por referência
typedef struct ponto{
    char letra;
    float x;
    float y;
}Ponto;

void imprime(Ponto*);
Ponto get_valores();
float calcula_distancia(Ponto p1, Ponto p2);

int main() {
    Ponto p, p2;
    float distancia;
    p = get_valores();
    p2 = get_valores();
    imprime(&p);
    imprime(&p2);
    distancia = calcula_distancia(p, p2);
    printf("A distância entre os pontos é: %g", distancia); 
    getchar();   
    return 0;
}

void imprime(Ponto* pp){
  printf("O ponto digitado é: %c(%.2f, %.2f)\n", pp->letra, pp->x, pp->y);
}

Ponto get_valores(){
  Ponto temp;
  printf("Digite a letra referente ao ponto: ");
  scanf(" %c", &temp.letra);
  printf("Digite as coordenadas do ponto %c(x,y): ", temp.letra);
  scanf(" %f, %f", &temp.x, &temp.y);
  return temp;
}

float calcula_distancia(Ponto p1, Ponto p2){
  return (float) sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}


