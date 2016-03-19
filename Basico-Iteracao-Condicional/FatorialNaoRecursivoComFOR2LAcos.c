#include <stdio.h>
#include <stdlib.h>
/*  Função: Fatorial nao recursivo
    Autor: Edkallenn
    Data:05/09/2013
    Observações:
*/
main(){
    int cont, num, i;
    double fat;
    printf("\n\nDigite um numero inteiro nao-negativo: ");
    scanf("%d", &num);

    fat = 1;
    for(i=num;i>=1;i--){
        //calculo do fatorial
        for(cont=1;cont<=i;cont++){
            fat=fat*cont;
        }
    printf("\n%d! = %f \n", i, fat);
    fat = 1;
    }
   system("pause");
}
