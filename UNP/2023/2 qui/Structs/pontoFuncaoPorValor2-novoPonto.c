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
void imprime(Ponto);    //protótipos
Ponto captura();
void exibeQuadrante(Ponto p);
main(){
    Ponto p;
    p = captura();
    imprime(p);
    exibeQuadrante(p);
    getch();
}
void imprime(Ponto p){
    printf("O ponto fornecido foi: %c(%.2f, %.2f)\n", p.letra, p.x, p.y);
}
Ponto captura(){
    Ponto b;
    printf("Digite o nome do ponto (uma letra apenas):");
    b.letra = getchar();
    //printf("O nome do ponto e': %c", b.letra);
    printf("\nDigite as coordenadas do ponto(x,y): ");
    scanf("%f,%f", &b.x, &b.y);
    return b;
}
void exibeQuadrante(Ponto p){
    if ((p.x>0)&&(p.y>0)) printf("O ponto esta' no 1o. quadrante\n");
    if ((p.x<0)&&(p.y>0)) printf("O ponto esta' no 2o. quadrante\n");
    if ((p.x<0)&&(p.y<0)) printf("O ponto esta' no 3o. quadrante\n");
    if ((p.x>0)&&(p.y<0)) printf("O ponto esta' no 4o. quadrante\n");
    if ((p.x==0)&&(p.y==0)) printf("O ponto esta' na origem\n");
    if ((p.x==0)&&(p.y!=0)) printf("O ponto esta' na abscissa\n");
    if ((p.x!=0)&&(p.y==0)) printf("O ponto esta' na Ordenada\n");
}


