#include<stdio.h>
#include<stdlib.h>

main(){

    int a,b;
    printf("Digite o valor de a: ");
    scanf(" %d", &a);
    printf("Digite o valor de b: ");
    scanf(" %d", &b);

    while(a<=b){
        printf("%d \n", a);
        a++;        
    }

    getchar();
}
