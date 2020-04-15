#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao fatorial recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/
float fat(int n);
main(){
    int i,num;
    do{
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<=0);
    for (i=1;i<=num;i++){
        printf("\nFatorial de %d eh: %.0f", i, fat(i));
    }
    getchar();
}

float fat(int n){
    if (n==0)
        return 1;
    else
        return n*fat(n-1);
}
