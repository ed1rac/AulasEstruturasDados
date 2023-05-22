#include <stdlib.h>
#include <stdio.h>
/*  Função : Captura e imprime um ponto
    Autor : Edkallenn  - Data : 10/04/2012
    Obs: Usando passagem por referencia          */
struct ponto{
    float x;
    float y;
};
void imprime(struct ponto*);
void captura(struct ponto*);
main(){
    struct ponto p;
    captura(&p);
    imprime(&p);
    getch();
}
void imprime(struct ponto* pp){
    printf("O ponto fornecido foi: (%.2f, %.2f)\n", pp->x, pp->y);
}
void captura(struct ponto* pp){
    printf("Digite as coordenadas do ponto(x,y): ");
    scanf("%f %f", &pp->x, &pp->y);
}

