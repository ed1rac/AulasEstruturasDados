#include <stdio.h>
#include <stdlib.h>
/*  Fun��o : Funcao fatorial recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observa��es:
*/
double fat(int n);

int main(){
    int i,num;  
    do{
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<=0);

    for (i=1;i<=num;i++){
        printf("\nFatorial de %d eh: %g", i, fat(i));
    }
    getchar();
}

double fat(int n){
    if (n==0)
        return 1;
    else
        return n*fat(n-1);
}
