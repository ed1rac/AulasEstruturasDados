#include <stdio.h>
#include <stdlib.h>
/*  Funçãoo : Função cubo e quadrado por valor e por referencia
    Autor : Edkallenn
    Data : 07/05/2013
    Observações: Exercício em sala.
*/
#define QL printf("\n")     //constante simbólica Quebra Linha
double quadValor(int n);
double quadReferencia(int *);
double cuboValor(int n);
double cuboReferencia(int *);

main(){
    int i,num;
    do{
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<=0);
    //Quadrado por valor
    for (i=0;i<=num;i++){
        printf("\nO quadrado (valor) de %d e': %g", i, quadValor(i));
    } QL;QL; getch();
    //Quadrado por Referencia
    for (i=0;i<=num;i++){
        printf("\nO quadrado (ref) de %d e': %g", i, quadReferencia(&i));
    } QL;QL; getch();
    //Cubo por valor
    for (i=0;i<=num;i++){
        printf("\nO Cubo (valor) de %d e': %g", i, cuboValor(i));
    } QL;QL; getch();
    //Cubo por Referencia
    for (i=0;i<=num;i++){
        printf("\nO cubo (ref) de %d e': %g", i, cuboReferencia(&i));
    } QL; getch();
    getchar();
}

double quadValor(int n){
    return n*n;
}
double quadReferencia(int *n){
    return *n * *n;
}
double cuboValor(int n){
    return n * n * n;
}
double cuboReferencia(int *n){
    return *n * *n * *n;
}
