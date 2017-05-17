#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Função : Teste de random
**  Autor  : Edkallenn
**  Data : 06/04/2012
*/
int aleatorio (int n);
main(){
    srand(time(NULL));  //reinicializa o gerador de numeros aleatorios
    int i;
    printf("Alguns numeros aleatorios\n");
    for(i=1;i<=10;i++){
        printf("%d\t", 1 + aleatorio(100));
    }
    printf("\n");
    getchar();
}
int aleatorio (int n){
    return rand()%n;
}
