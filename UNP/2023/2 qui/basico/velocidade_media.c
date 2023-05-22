#include <stdio.h>
#include <stdlib.h>
float velocidade_media(float distancia, float tempo);
int main(){
    float dist, horas, vm;
    printf("Digite a distancia percorrida (em km): ");
    scanf(" %f", &dist);
    printf("Digite o tempo gasto (em horas): ");
    scanf(" %f", &horas);
    vm = velocidade_media(dist, horas);
    printf("A velocidade media do percurso e' : %.2f km/h\n",  vm);
   // getchar();
    return 1;
}

float velocidade_media(float distancia, float tempo){
    float vm;
    vm = distancia / tempo;
    return vm;
    //return distancia/tempo;
}
