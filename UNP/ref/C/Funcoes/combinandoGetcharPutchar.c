#include <stdio.h>
/** Funçăo : combinando getchar e putchar
* Autor : Edkallenn
* Data : 22/06/2015
* Obs:                                        */

main(){

    char *letra;

    do{
        letra = getchar();
        putchar(letra);
        //putchar(letra=getchar()); //---> pode ser assim!
    }while (letra != '\n');
    //getchar();

}
