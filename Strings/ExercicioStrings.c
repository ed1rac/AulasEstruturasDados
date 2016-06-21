#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Função : Teste de funcoes de manipulacao de string
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/
main(){
    char s1[40], s2[40], s3[80], s4[80];
    printf("Digite uma string: ");
    gets(s1);
    printf("Digite outra string: ");
    gets(s2);
    printf("Digite outra string: ");
    gets(s3);
    printf("Digite outra string: ");
    gets(s4);
    printf("As strings sao: \nString 1: %s\nString 2: %s", s1,s2);
    printf("\nString 3: %s\nString 4: %s", s3,s4);

    printf("\n\nComprimentos:\n%s: %d\n%s:%d\n", s1,strlen(s1),s2, strlen(s2));
    printf("%s:%d\n%s:%d\n", s3,strlen(s3), s4,strlen(s4));

    strcat(s1, s2);	strcat(s3, s4);//concatena e depois exibe
    printf("\n\nConcatenadas:\ns1 e s2:%s\ns3 e s4:%s", s1,s3);
    printf("\n\nTamanhos:\n%s: %d\n%s: %d\n", s1,strlen(s1),s3, strlen(s3));

    //concatena TODAS e exibe
    strcat(s1,s3);
    printf("\n\nConcatenadas:\n%s - tamanho: %d", s1,strlen(s1));

    getchar();
}
