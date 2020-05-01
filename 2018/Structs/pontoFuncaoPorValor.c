#include <stdio.h>
#include <stdlib.h>
/*  Função : Captura e imprime um ponto
    Autor : Edkallenn  - Data : 02/06/2016
    Obs: Usando passagem por valor          */
typedef struct ponto{
    char letra;
    float x;
    float y;
}Ponto;

void imprime(Ponto);
Ponto captura();

main(){
    Ponto p;
    p = captura();
    imprime(p);
    getchar();
}
void imprime(Ponto p){
    printf("O ponto fornecido foi: (%.2f, %.2f)\n", p.x, p.y);
}
Ponto captura(){
    Ponto b;
    printf("Digite as coordenadas do ponto(x,y): ");
    scanf("%f,%f", &b.x, &b.y);
    return b;
}

