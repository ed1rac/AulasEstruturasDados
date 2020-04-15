#include <stdio.h>
#include <stdlib.h>
/*  Fun��o : Funcao fatorial nao-recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observa��es:
*/

double fat(int n); //protótipo da função!

int main(){
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

double fat(int n){
    int cont;
    double fatorial;
    fatorial = 1;
    for(cont=1;cont<=n;cont++){
        fatorial*=cont;
    }
    return fatorial;
}
