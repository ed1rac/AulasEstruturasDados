#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Função : Mostra leitura de string com fgets
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/

main(){
    char nome[30];
    printf("Digite o seu nome: ");
    fgets(nome, 30, stdin);
    puts("Saudacoes");
    puts(nome);

    getchar();
}
