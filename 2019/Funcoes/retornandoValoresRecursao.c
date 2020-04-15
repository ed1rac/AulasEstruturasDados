#include <stdio.h>
/** Funçăo : mostra o funcionamento da recursão
* Autor : Edkallenn
* Data : 22/06/2015
* Obs:                                        */

float fatorial(int valor);

main(){
    int num;
    printf("Entre com um valor inteiro: ");
    scanf("%d", &num);
    printf("\nO fatorial de %d = %g\n", num, fatorial(num));
    getchar();
}

float fatorial(int valor){
    printf("\nNa funcao fatorial com o valor: %d\n", valor);
    if(valor == 1){
        printf("Retornando o valor 1\n");
        return valor;
    }else{
        printf("\nRetornando %d * fatorial(%d)\n", valor, valor-1);
        return(valor * fatorial(valor-1));
    }
}

