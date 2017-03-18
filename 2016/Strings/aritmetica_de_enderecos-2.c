#include <stdio.h>
#include <stdlib.h>
/*  Função : Mostra exemplo de aritmética de ponteiros com
             strings
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/
#define TAM 80  //tamanho maximo do vetor

main(){
    char saudacao[] = "Saudacoes, ";
    char nome[TAM];
    int i, len;
    printf("Digite seu nome: ");
    gets(nome);
    puts(saudacao);
    for (i=0;i<strlen(nome);i++)
    //for (i=strlen(nome);i>=0;i--)
        printf("%c\n", nome+i);

    getchar();
}
