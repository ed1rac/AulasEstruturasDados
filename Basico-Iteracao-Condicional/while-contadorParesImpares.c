#include <stdio.h>
main(){
    int num, cont_pares, cont_impares;
    cont_pares=0;
    cont_impares=0;
    do{
        printf("\nDigite um numero: ");
        scanf("%d", &num);
        if((num%2)==0){
            printf("\n%d eh par\n", num);
            cont_pares++;
        }else{
            if(num>=0){
                printf("\n%d eh impar\n", num);
                cont_impares++;
            }
        }
    }while(num>=0);
    printf("\nForam digitados %d pares", cont_pares);
    printf("\nForam digitados %d impares", cont_impares);

    getch();
}
