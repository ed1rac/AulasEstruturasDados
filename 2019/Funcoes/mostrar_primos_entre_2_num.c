#include <stdio.h>
#include <stdlib.h>
/*  Função : mostrar primos esntre dois numeros.
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int e_primo(int);

main(){
    int i, num1, num2;
    do{
        printf("\nEntre com dois numeros inteiro positivos: ");
        scanf("%d, %d", &num1, &num2);
    }while((num1<=0) || (num2<=0));

    printf("\nNumeros primos entre %d e %d\n", num1, num2);
    for(i=num1;i<=num2;i++){
        if (e_primo(i))
            printf("%d\n", i);
    }
    getch();
}

int e_primo(int x){
    int cont_primo = 0;
    int i;
    for (i = 1;i<=x;i++){
        if ((x%i)==0)
           cont_primo+=1;
    }
    if(cont_primo==2)
        return 1; //é primo
    else
        return 0; //nao eh primo

}
