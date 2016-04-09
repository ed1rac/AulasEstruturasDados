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

main(){
    int num;
    do{
        exibe_menu();
        num = leia_int();
        opcoes(num);
        getch();    //system("pause");
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
    printf(" 1  -  I n s e r i r       \n");
    printf(" 2  -  C o n s u l t a r   \n");
    printf(" 3  -  C a l c u l a r     \n");
    printf(" 0  -  S A I R             \n"); pula(2);
}
int leia_int(){
    int numero;
    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);
    return (int) numero;
}
void opcoes(int n){
    switch(n){
    case 1: printf("\nOpcao 1\n"); break;
    case 2: printf("\nOpcao 2\n"); break;
    case 3: printf("\nOpcao 3\n"); break;
    case 0: return; break;
    default: printf("\nValor digitado eh invalido\n"); break;
    };
}
