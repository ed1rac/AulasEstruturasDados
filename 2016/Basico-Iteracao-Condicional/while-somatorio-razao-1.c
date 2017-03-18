#include<stdio.h>
#include<stdlib.h>

main(){

    int num, soma, cont;

    printf("\nDigite um numero: ");
    scanf("%d", &num);
    soma=0;

    cont=1;
    while(cont<=num){
        soma+=cont; //soma = soma + cont;
        cont++;     //cont = cont +1;

    }
    printf("\nO somatorio eh: %d", soma);
    getch();
}
