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
    printf("Digite seu nome: ");
    gets(nome);
    printf("%s%s\n", saudacao, nome +5);
    printf("\n\n");
    getchar();
}
