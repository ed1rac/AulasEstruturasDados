#include <stdio.h>
#include <stdlib.h>
/*  Função : Exibir inteiros de 1 a 100
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/

main(){
    int cont;
    cont = 1;
    while(cont<=100){
        printf("%d\t", cont);
        cont++;
    }
    getch();
}
