#include <stdio.h>
#include <stdlib.h>

#define QL printf("\n")

int main(){
        int num, i;
        char c;

        do{
          printf("Digite um número inteiro: ");
          scanf(" %d", &num);
        
          printf("Tabuada de %d\n", num);
          for(i=1;i<=10;i++){
                printf("%d x %d = %d\n", num, i, num * i);
          }
          QL;
          printf("Continua: (S/N)?");
          scanf(" %c", &c);
          QL;
        }while((c=='s')||(c=='S'));
        QL;

        getchar();
}
