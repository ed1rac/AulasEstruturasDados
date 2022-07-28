#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*  Função : Teste de random
**  Autor  : Edkallenn
**  Data : 06/04/2012
*/
int aleatorio(int n);

int main(){
    //srand((unsigned)time(NULL));
    srand(time(NULL));
    int i;
    printf("Alguns numeros randomicos\n");
    for(i=1;i<=10;i++){
        printf("%d\t", 1 + aleatorio(100));
    }
    getchar();
}
int aleatorio(int n){
    return rand()%n;
}
