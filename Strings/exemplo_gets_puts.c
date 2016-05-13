#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Função : Mostra leitrua de string com gets
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/

main(){
    char nome[80];
    printf("Digite o seu nome: ");
    gets(nome);
    puts("Saudacoes");
    puts(nome);
    puts("puts() pula de linha sozinha");
    puts(&nome[4]);
    getchar();
}
