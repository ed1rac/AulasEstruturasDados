#include <stdio.h>
#include <stdlib.h>

int main(){
        int num, i, j;
        printf("Digite um número: ");
        scanf(" %d", &num);
        j=2;
        while(j<=num){
          printf("Tabuada de %d\n", j);
          i = 1;  //inicializacao
          while(i<=10){
                printf("%d x %d = %d\n", j, i, j * i);
                i++;
          }
        j++;
        }
        getchar();
}
