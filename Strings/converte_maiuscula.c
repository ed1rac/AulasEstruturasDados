#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Verifica Digito
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: Testa se um caractere c é um letra ou não! */
 #define QL printf("\n")
char maiuscula(char c);
main(){
    int i;
    char texto[]= "Tabela de Codigo ASCII - by Edk";
    QL;
    for(i=0;texto[i]!='\0';i++){
        printf("%c ", texto[i]);
    } QL; QL;
    for(i=0;texto[i]!='\0';i++){
        printf("%c ", maiuscula(texto[i]));
    }
    getchar();
}
char maiuscula(char c){
    //verifica se é letra minuscula
    if(c>='a' && c<='z')
        c = c-'a'+'A'; //converte para maiuscula

    return c;
}
