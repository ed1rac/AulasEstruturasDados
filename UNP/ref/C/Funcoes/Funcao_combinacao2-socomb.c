#include <stdio.h>
#include <stdlib.h>
/*  Função: Combinacao de n elementos agrupados p a p
    Autor: Edkallenn - Data:05/09/2013 - Observações:
*/
double fat(int n);
double combinacao(int n, int s);
main(){
    int num1, num2;
    double resultado;
    printf("\nEste programa calcula a combinacao de 2 numeros");
    printf("\nDigite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    resultado = combinacao(num1, num2);
    printf("\nA combinacao(%d, %d) = %g",num1, num2, resultado);
    getch();
}
double fat(int n){
    int cont;
    double fatorial;
    fatorial = 1;
    for(cont=1;cont<=n;cont++){
        fatorial=fatorial*cont;
    }
    return fatorial;
}
double combinacao(int n, int s){
    double resposta;
    resposta = fat(n)/(fat(s)*fat(n-s));
    return resposta;
}












