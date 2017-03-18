#include <stdio.h>
#include <stdlib.h>
/*  Função : Exibir inteiros de 100 a 1
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/

main(){
    int cont;
    cont = 50;
    while(cont>=1){
        if(cont%2!=0){
            printf("%d\n", cont);
        }
        cont--;
    }
    getch();
}
