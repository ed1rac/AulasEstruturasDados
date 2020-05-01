
#include <stdio.h>
#include <stdlib.h>
/*  Funcao: Fatorial nao recursivo
    Autor: Edkallenn -     Data:05/09/2013
    Observacoes:  */
main(){    
    int cont, num;
    double fat;
    do{
        printf("\n\nDigite um numero inteiro nao-negativo: ");
        scanf(" %d", &num);
    }while(num<0);

    fat = 1;
    for(cont=1;cont<=num;cont++){   //calculo do fatorial
        fat = fat * cont;
    }
    printf("\n\nO fatorial de %d eh %g \n\n", num, fat);
    system("pause");
}
