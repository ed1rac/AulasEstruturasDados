#include <stdio.h>
#include <stdlib.h>
/*
    Função: calcula a área da esfera
    Autor: Edkallenn
    Data: 31/03/2016
    Observações:
*/
float areaEsfera(float raio);     //protótipo
main(){
    float raio;
    printf("  ==== Programa que calcula a area da esfera ====\n");
    printf("Digite o raio: ");
    scanf("%f", &raio);
    printf("\nA area da esfera de raio = %.3f = %f", raio, areaEsfera(raio));
    getch();
}

float areaEsfera(float raio){
    return (4 * 3.141592 * raio * raio);
}
