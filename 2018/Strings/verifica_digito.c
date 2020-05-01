#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Verifica Digito
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: Testa se um caractere c é um digito ou não! */
 #define QL printf("\n")

int digito(char c);
int letra(char);

main(){
    int i;
    char texto[]= "987 - Tabela de Codigo ASCII - teste 123";
    QL;
    for(i=0;texto[i]!='\0';i++){
        if(digito(texto[i]))
            printf("%c %s", texto[i],  "digito\n");
        else
            printf("%c %s", texto[i],  "nao eh digito\n");
    }
    getchar();
}

int digito(char c){
    if((c>='0')&&(c<='9'))
        return 1; //eh digito
    else
        return 0; //não eh digito

}

int letra(char c){
    if((c>='A')&&(c<='z'))
        return 1; //eh letra
    else
        return 0; //não eh letra

}
