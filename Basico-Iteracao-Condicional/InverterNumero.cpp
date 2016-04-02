#include <stdio.h>
#include <stdlib.h>
/*  Função : Inverte um número de até 10 números
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/

main(){
    int numero, digitoDireita;
    printf ("Digite um numero positivo de ate 10 numeros: ");
    scanf("%d", &numero);
    printf ("\nO numero invertido e': \n");
    do{
        digitoDireita = numero % 10;
        printf("%d", digitoDireita);
        numero/=10;
    }while(numero!=0);

    getchar();
}
