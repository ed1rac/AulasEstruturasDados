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
   i = 1;
   while(i<=num){
        //calculo do fatorial
        cont = 1;
        while(cont<=i){
            fat=fat*cont;
            cont++;
        }
   printf("O fatorial de %d eh %g \n\n", i, fat);
   i++;fat = 1;
   }
   system("pause");
}
