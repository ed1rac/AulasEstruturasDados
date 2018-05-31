#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*  Função : Teste de aleatorio
**  Autor  : Edkallenn
**  Data : 06/04/2012
*/
int aleatorio(int n);

main(){
    srand(time(NULL));
    int i;
    printf("Alguns numeros randomicos\n");
    for(i=1;i<=10;i++){
        printf("%d\t", 1 + aleatorio(20));
    }
    getchar();
}
int aleatorio(int n){
    return rand()%n;
}
