#include <stdio.h>
#include <stdlib.h>
/* Função : Exemplo da passagem de estruturas inteiras
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações:
*/

struct ponto{
    int x;
    int y;
};

//define um tipo de estrutura
struct struct_exemplo{
    int a,b;
    char ch;
};

//prototipo da funcao que recebe a estrutura
void funcao1(struct struct_exemplo parametro);

main(){

    struct ponto *pp, p;

    pp = &p;
    (*pp).x = 12.0;
    pp->x = 12.0;

    struct struct_exemplo argumento;
    argumento.a=1000;
    funcao1(argumento);
    getchar();
    return(0);
}
void funcao1(struct struct_exemplo parametro){
    printf("%d\n", parametro.a);
    parametro.a = parametro.a * 2;
    printf("%d", parametro.a);
}
