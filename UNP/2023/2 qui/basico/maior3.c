#include <stdio.h>
#include <stdlib.h>
int maiord3(int, int, int);
int main(){
    int n1, n2, n3;
    printf("Digite os 3 numeros separados por virgulas: ");
    scanf(" %d, %d, %d", &n1, &n2, &n3);
    printf("O maior e': %d", maiord3(n1, n2, n3));
    return 1;
}
int maiord3(int x, int y, int z ){
    int maior;
    maior = x;
    if(y > maior)
        maior = y;
    if(z > maior )
        maior = z;

    return maior;
}
