/*  Funçăo : |Trocando variáveis com ponteiros
    Autor : Edkallenn  -  Data : 06/04/2012
    Observaçőes: Exemplos de utilizaçăo de ponteiros
*/
#include <stdio.h>
#include <stdlib.h>

void troca_var(int *, int *);

main(){
    int a,b;
    a = 5; b = 7;
    troca_var(&a, &b); //passamos o endereço das variaveis
    printf("%d %d \n", a, b);
    system("pause");
}
void troca_var(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
