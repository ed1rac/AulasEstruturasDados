#include <stdio.h>
#include <stdlib.h>

/*  Função: Calcula a vm
    Autor: Edkallenn
    Data:05/09/2013
    Observações:klajkdjlçfj lasjf
*/
float velocidadeMedia(float, float);
main(){
    float km, tempo, resultado;
    printf("\nDigite a quilometragem: ");
    scanf("%f", &km);
    printf("\nDigite o tempo gasto: ");
    scanf("%f", &tempo);
    resultado = velocidadeMedia(km, tempo);
    printf("\nA Velocidade Media do percurso foi %f", resultado);
    getch();
}

float velocidadeMedia (float tupi, float guarani){
    float vm;
    vm =tupi/guarani;
    return vm;
}


