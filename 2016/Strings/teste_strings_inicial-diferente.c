#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Strings
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: testa strings  */
 #define QL printf("\n")

main(){

    char texto[81];
    QL;
    printf("Digite uma cadeia: ");
    scanf(" %80[^\n]", texto); QL;
    printf("A cadeia digitada eh: %s", texto);
    QL; QL;
    getchar();
}

