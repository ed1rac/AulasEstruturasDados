#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Verifica Letra
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: Testa se um caractere c é um letra ou não! */
 #define QL printf("\n")
int letra(char);
main(){
    int i;
    char texto[]= "321 - Tabela de Codigo ASCII - 123";
    QL;
    for(i=0;texto[i]!='\0';i++){
        if(letra(texto[i]))
            printf("%c %s", texto[i],  "e' letra\n");
        else
            printf("%c %s", texto[i],  "nao e' letra\n");
    } QL; QL;
   getchar();
}
int letra(char c){
    if((c>='A')&&(c<='z'))
        return 1; //eh letra
    else
        return 0; //não eh letra
}