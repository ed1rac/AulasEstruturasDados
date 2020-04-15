#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592
/*  Função: Calcula a area do circulo
    Autor: Edkallenn
    Data:05/09/2013
    Observações:klajkdjlçfj lasjf
*/
float areaCirculo(float);
main(){
    float raio, resultado;
    printf("\nDigite o valor do raio: "); scanf("%f", &raio);
    resultado = areaCirculo(raio);
    printf("\nA area do circulo de raio %f eh %f", raio, resultado);
    getch();
}

float areaCirculo (float r){
    float area;
    area =4*PI*r*r;
    return area;
}


