#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao fatorial nao-recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/

main(){
    int cont,num,k;
    double fat=1;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &num);
    for (k=1;k<=num;k++){   //loop de 1 ate num
        //calculo do fatorial
        for(cont=1;cont<=k;cont++){
            fat=fat*cont;
        }
        //exibe o fatorial
        printf("O fatorial de %d eh %f\n", k, fat);
        //reinicia a variavel acumuladora
        fat=1;
    }
    getch();
}
