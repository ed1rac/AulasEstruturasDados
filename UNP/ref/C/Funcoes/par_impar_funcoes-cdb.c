#include <stdio.h>
#include <stdlib.h>

int leia_int(void);
void par(int);

void main(void){
    int num=0;
    while (num!=-1){
        num = leia_int();
        if (num==-1) break;
        par(num);
    }
    getch();
}
int leia_int(){
    int numero;
    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);
    return (int) numero;
}
void par(int epar){
    if ((epar%2) == 0)
        printf("\n\n O numero %d e par!\n\n", epar);
    else
        printf("\n\n O numero %d e impar!\n\n", epar);
}
