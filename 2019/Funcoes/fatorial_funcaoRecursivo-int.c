#include <stdio.h>
#include <stdlib.h>
/*  Fun��o : Funcao fatorial recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observa��es:
*/
float fat(int n);     //prot�tipo
main(){
    int i,num;
    do{
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<=0);
    for (i=1;i<=num;i++){
        printf("\nFatorial de %d eh: %f", i, fat(i));
    }
    getch();
}

float fat(int n){

    if (n==0)
        return 1;
    else
        return n*fat(n-1);

}
