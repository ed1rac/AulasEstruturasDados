#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*  Função : Teste de random
**  Autor  : Edkallenn
**  Data : 06/04/2012
*/
int random(int n);

main(){
    srand((unsigned)time(NULL));
    int i;
    printf("Alguns numeros randomicos\n");
    for(i=1;i<=10;i++){
        printf("%d\t", 1 + random(10));
    }
    getchar();
}
int random(int n){
    return rand()%n;
}
