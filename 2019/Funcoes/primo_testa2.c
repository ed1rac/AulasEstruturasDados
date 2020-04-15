#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    for (int i = 0; i <= num; ++i){
       // if (i%5==0) printf("\n");        
        if (verifica_primo(i)){
            printf("%d\t", i);
        }
    } printf("\n");
    return 0;
}

int verifica_primo(int numero){
    if (numero==2){
        return 1;
    }else if (numero<2 || (numero%2==0)){
        return 0;
    }else {
        int lim = (int) sqrt(numero);
        for (int i = 3; i <= lim; i+=2){
            if (numero%i==0){
                return 0;
            }
        }
    return 1;
    }
}

