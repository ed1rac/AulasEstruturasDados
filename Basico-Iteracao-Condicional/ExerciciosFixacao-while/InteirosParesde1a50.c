#include <stdio.h>
#include <stdlib.h>
/*  Função : Exibir inteiros de 100 a 1
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/

main(){
    int cont;
    cont = 2;
    while(cont<=50){
        printf("%d\n", cont);
        cont+=2;
    }
    getch();
}
