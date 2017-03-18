/* Função : Aula de TAD
/ Autor : Edkallenn
/ Data : 02/06/2012
/ Observações: Mostra a construção de um TAD ponto
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct frac{
    int num;
    int den;
}frac;

//prototipos
void obter_fracoes( frac *, frac *);
void somar_fracoes(frac, frac);
void subtrair_fracoes(frac, frac);
void multiplicar_fracoes(frac, frac);
void dividir_fracoes(frac, frac);
void simplificar_fracao(frac);
int mdc(int x, int y);

main(){
    char resposta;
    frac a,b;

    while(1){
        system("CLS");
        printf("==== MENU ====\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. SAIR\n");
        resposta = getche();
        if(resposta == '9')
            break;
        obter_fracoes(&a, &b);
        switch(resposta){
            case '1': somar_fracoes(a,b); break;
            case '2': subtrair_fracoes(a,b); break;
            case '3': multiplicar_fracoes(a,b); break;
            case '4': dividir_fracoes(a,b); break;
        }
    }
    getchar(); return(0);
}
void obter_fracoes(frac *a, frac *b){
    printf("\nDigite o Numerador da 1a. Fracao: ");
    scanf("%d", &((*a).num));
    printf("\nDigite o Denominador da 1a. Fracao: ");
    scanf("%d", &((*a).den));
    printf("\nDigite o Numerador da 2a. Fracao: ");
    scanf("%d", &((*b).num));
    printf("\nDigite o Denominador da 2a. Fracao: ");
    scanf("%d", &((*b).den));
    printf("\nA fracao 1 e: %d / %d\n", (*a).num, (*a).den);
    printf("A fracao 2 e: %d / %d\n", (*b).num, (*b).den);
    system("pause");
    return;
}
void somar_fracoes(frac x, frac y){
    frac f;
    f.num = x.num*y.den + y.num*x.den;
    f.den = x.den*y.den;
    simplificar_fracao(f);
}
void subtrair_fracoes(frac x, frac y){
    frac f;
    f.num = x.num*y.den - y.num*x.den;
    f.den = x.den*y.den;
    simplificar_fracao(f);
}
void multiplicar_fracoes(frac x, frac y){
    frac f;
    f.num = x.num*y.num;
    f.den = x.den*y.den;
    simplificar_fracao(f);
}
void dividir_fracoes(frac x, frac y){
    frac f;
    f.num = x.num*y.den;
    f.den = x.den*y.num;
    simplificar_fracao(f);
}
void simplificar_fracao(frac f){
    int m;
    m = mdc(f.num, f.den);
    f.num = f.num/m;
    f.den = f.den/m;
    printf("Resultado: %d / %d\n", f.num, f.den);
    system("pause");
}
int mdc(int x, int y){
    int r;
    while(r!=0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
