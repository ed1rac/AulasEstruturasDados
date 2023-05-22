/* Função : Série de Taylor
/ Autor : Edkallenn
/ Data : 04/10/2012
/ Observações: A série de Taylor é uma série de funções especificada em: http://pt.wikipedia.org/wiki/S%C3%A9rie_de_Taylor
/ Muito utilizada no Cálculo e na Análise Matemática
/ este programa usará a série de Taylor para desenvolver a exponencial (e ^ x) com x e N(precisao) digitado pelo usuario
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fat(int);
double exp(float, int);

int main(void){
    double resposta;
    float x;
    int num;
    printf("--- Programa para calcular a funcao exponencial e^x usando a serie de Taylor ---\n\n");
    printf("Digite o valor de x: "); scanf("%f", &x);
    printf("Digite a precisao (qtde de iteracoes - um inteiro): "); scanf("%d", &num);
    //printf("Fatorial de %d eh %f\n\n", num, fat(num));
    resposta = exp(x, num);
    printf("\n\nEXPONENCIAL -> e ^ %.3f eh: %f\n\n", x,resposta);
    return 0;
}

double fat(int x){
    if ((x ==1) || (x ==0))
        return 1;
    else
        return x * fat(x-1);
}
double exp(float a, int num){
    double value;
    int i;
    value=1;
    for(i=1;i<=num;i++){
        printf("\nPASSO %d %f e %f\n", i, pow(a,i), fat(i));
        value= value + (pow(a,i) / fat(i));

    }
    return value;
}
