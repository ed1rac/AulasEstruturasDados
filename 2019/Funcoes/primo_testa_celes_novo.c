#include <stdio.h>
#include <stdlib.h>
/*  Fun?o: Primalidade de um numero
    Autor: Waldemar Celes
    Data: 21/10/2016
    Observa?es: Verifica se um n?mero dado ?primo!
*/
int verifica_primo(int);
int main(){
    int num;
    printf("\nDigite um número: "); 
    scanf(" %d", &num);
    printf("Primos entre 1 e %d\n", num );
    for (int i = 0; i < num; ++i){
        if (verifica_primo(i)){
            printf("%d\t", i);
        }
    } printf("\n");
    return 0;
}

int verifica_primo(int numero){
    if (numero<2){
        return 0;
    }
    for (int i = 2; i < numero; ++i){
        if (numero%i==0){
            return 0;
        }
    }
    return 1;
}


