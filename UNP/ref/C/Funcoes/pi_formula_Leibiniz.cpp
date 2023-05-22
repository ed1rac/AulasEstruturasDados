#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Função : Calcula PI pela formula de Leibiniz
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações:
*/

double pi(int n);   //protótipo da função

main(){
    int num;
    printf("Programa que calcula PI pela formula de Leibiniz\n\n");
    do{
        printf("Digite o valor do numero N: ");
        scanf("%d", &num);
    }while(num<0);

    double valor = pi(num);
    printf("O valor de PI pela formula de Leibiniz, com n= %d e: %-15.12f\n\n", num, valor);
    getchar();
    return(0);
}
double pi(int n){
    double p, soma;
    int i;
    soma = 0.0;
    for (i=0;i<=n;i++){
        soma+=(pow(-1, i))/(2*i+1);
    }
    p = 4*soma;
    return p;
}
