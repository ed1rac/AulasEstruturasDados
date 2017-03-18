#include <stdio.h>
#include <stdlib.h>
//protótipos
double fat(int);
double combinacao(int n, int r);
double arranjo(int n, int p);
main(){
    int num1, num2;
    printf("Programa que calcula a combinacao de n a p -> C(n,p)\n");
    printf("e o Arranjo de n a p -> A(n,p)\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("A comb(%d,%d)\t=%g\n", num1,num2,combinacao(num1,num2));
    printf("O arranjo(%d,%d)\t=%g\n", num1,num2,arranjo(num1,num2));
    getch();
    
}

double fat(int num){
    int i;
    double fatorial;
    fatorial = 1;
    for(i=1;i<=num;i++){
        fatorial*=i;
    }
    return fatorial;
}

double combinacao(int n, int r){
    return (fat(n)/(fat(r)*fat(n-r)));
}

double arranjo(int n, int p){
    return (fat(n)/fat(n-p));
}
