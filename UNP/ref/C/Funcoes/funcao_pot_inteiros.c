#include <stdio.h>
#include <stdlib.h>
/*  Função : Função pot(m,n)
    Autor : Edkallenn - Data : 06/04/2012
    Observações:
*/
int pot(int, int);  //prototipo da funcao
main(){
    int n, p;
    char c;
    do{
        printf("\nDigite um numero inteiro:");
        scanf("%d", &n);
        printf("Digite a potencia para elevar %d:", n);
        scanf("%d", &p);
        int m = pot(n, p);
        printf("\nO numero %d elevado a %d eh %d", n, p, m);
        printf("\n\nContinua(S/N)?");
        c = toupper(getche(c));
        printf("\n\n");
    }while(c == 'S');
}
int pot(int x, int n){
    int p;
    for (p=1;n>0;--n){
        p = p*x;
    }
    return(p);
}
