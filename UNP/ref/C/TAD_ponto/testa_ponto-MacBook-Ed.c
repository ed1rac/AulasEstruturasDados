/* Função : Exemplo de uso do TAD Ponto
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações: Salve este arquivo como testa_ponto.c
*/
#include <stdio.h>
#include <math.h>
#include "ponto.h"

int main (void)
{
    //float x, y;

    Ponto *p = pto_cria(2.0,1.0);
    Ponto *q = pto_cria(3.4,2.1);

    float d = pto_distancia(p,q);

    printf("Distancia entre pontos: %f\n",d);

    pto_libera(q);
    pto_libera(p);
    getchar();
    return 0;
}

