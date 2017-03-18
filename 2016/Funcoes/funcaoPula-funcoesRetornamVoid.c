#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Pula quantidade x de linhas
    Autor : Edkallenn  -  Data : 03/10/2013
    Observaçőes:
*/

void pula();

main(){

    printf("Teste da funcao");
    pula(); pula();
    printf("Deve pular uma linha");
    getch();
}
void pula(){
    printf("\n");
}
