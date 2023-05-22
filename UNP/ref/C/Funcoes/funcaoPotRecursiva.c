#include <stdio.h>
#include <stdlib.h>

int pot (int, int);

main(){
    int num1, num2;
    printf("Digite a base: ");
    scanf("%d", &num1);
    printf("Digite o expoente: ");
    scanf("%d", &num2);
    printf("%d ^ %d eh: %d", num1, num2, pot(num1, num2));
    getche();
}
int pot (int base, int exp){
    if(exp==0)
        return 1;
    else
        return base * pot(base, exp -1);
}
