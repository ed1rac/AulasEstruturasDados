#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Função : Teste de funcoes de manipulacao de string
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/
main(){
    char s1[80], s2[80];
    printf("Digite uma string: ");
    gets(s1);
    printf("Digite outra string: ");
    gets(s2);

    printf("Comprimetos: %d e %d\n", strlen(s1), strlen(s2));

    if(!strcmp(s1, s2)) printf ("As strings sao iguais\n");
    strcat(s1, s2);
    printf("%s\n", s1);
    printf("O Comprimetos de s1(concatenada): eh %d\n", strlen(s1));

    strcpy(s1, "Isso eh um teste.\n");
    printf(s1);
   /* if(strchr("alo", 'o')) printf("o estah em alo\n");if(strstr("ola aqui", "ola")) printf ("ola encontrado"); */
    getchar();
}
