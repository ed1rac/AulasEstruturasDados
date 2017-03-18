#include <stdio.h>
#include <stdlib.h>
/*  Funçãoo : Funcao fatorial recursiva por valor e por referencia
    Autor : Edkallenn
    Data : 07/05/2013
    Observações:
*/
#define QL printf("\n")

double fat_valor(int n);
double fat_referencia(int *);

main(){
    register int i,num;
    do{
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<=0);
    //valor
    for (i=0;i<=num;i++){
        printf("\nFatorial de %d eh: %.0f", i, fat_valor(i));
    } QL;
    //Referencia
    for (i=0;i<=num;i++){
        printf("\nFatorial de %d eh: %.0f", i, fat_referencia(&i));
    }

    getchar();

}

double fat_valor(int n){

    if (n==0)
        return 1;
    else
        return n*fat_valor(n-1);

}
double fat_referencia(int *n){
    register double fat;
    register int i, a;
    a = *n;
    fat=1;
    for(i=1;i<=a;i++)
        fat*=i;

    return fat;
}
