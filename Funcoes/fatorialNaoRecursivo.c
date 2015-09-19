#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao fatorial nao-recursiva
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:            */
double fat(int n);  //prototipo da funcao
main(){
    int i,num;
    do{         //laco enquanto nao for positivo nao continua
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
    }while(num<0);
    for (i=0;i<=num;i++){   //modtra TODOS os fatoriais de 1 ate num
        printf("\nFatorial de %d eh: %g", i, fat(i));
    }
    getch();
}
double fat(int n){
    int cont;
    double fatorial;
    fatorial = 1;
    for(cont=1;cont<=n;cont++){
        fatorial*=cont;
    }
    return fatorial;
}
