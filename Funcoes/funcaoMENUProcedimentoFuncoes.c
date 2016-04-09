#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : exibe menu
    Autor : Edkallenn  -  Data : 03/10/2013
    Observaçőes:
*/

void exibe_menu(); //menu
int leia_int(); //retorna o valor digitado pelo usuario testando a entrada
void opcoes(int n);
void pula(int x);
float fat(int);
int pot(int, int);
double combinacao(int, int);
void calculaFat();
void eleva();
void calculaCombinacao();


main(){
    int num;
    do{
        exibe_menu();
        num = leia_int();
        opcoes(num);
        getch();
    }while(num!=0);
    getch();
}
void pula(int x){
    int i;
    for(i=1;i<=x;i++)
        printf("\n");
}
void exibe_menu(){
    system("cls");
    pula(2);
    printf(" ====== MENU PRINCIPAL ======"); pula(2);
    printf(" 1  -  Calcula fatorial     \n");
    printf(" 2  -  Calcula Combinacao   \n");
    printf(" 3  -  Eleva x a y          \n"); pula(1);
    printf(" 0  -  S  A  I  R           \n"); pula(2);
}
int leia_int(){
    int numero; pula(1);
    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);
    return (int) numero;
}
void opcoes(int n){
    switch(n){
    case 1: calculaFat();           break;
    case 2: calculaCombinacao();    break;
    case 3: eleva();                break;
    case 0: return;                 break;
    default: printf("\nValor digitado eh invalido\n"); break;
    };
}

void calculaFat(){
    int num;
    num = leia_int();
    printf("\nO fatorial de %d = %.3f", num, fat(num));
}

void calculaCombinacao(){
    int num1, num2;
    double res;
    num1 = leia_int();
    num2 = leia_int();
    res  = combinacao(num1, num2);
    printf("\nA combinacao de %d agrupados de %d a %d = %.3f", num1, num2, num2, res);
}
void eleva(){
    int num1, num2;
    num1 = leia_int();
    num2 = leia_int();
    printf("\n%d elevado a %d = %d", num1, num2, pot(num1, num2));
}

int pot(int x, int n){
    int p;
    for (p=1;n>0;--n){
        p = p*x;
    }
    return(p);
}

double combinacao(int n, int s){
    return fat(n)/(fat(s)*fat(n-s));
}

float fat(int n){

    if (n==0)
        return 1;
    else
        return n*fat(n-1);

}

