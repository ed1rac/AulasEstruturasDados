#include <stdio.h>
#include <stdlib.h>

int main(){
        float i, num, fatorial;
        printf("Digite um número: ");
        scanf(" %f", &num);
        fatorial = 1;
        for(i=1;i<=num;i++){
          fatorial*=i;

        }
        printf("O fatorial de %f é = %f\n\n",num, fatorial);
        getchar();
}
