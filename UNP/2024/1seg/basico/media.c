#include <stdio.h>

int main(){
    float n1, n2, media;
    printf("Digite a nota 1: ");
    scanf(" %f", &n1);
    printf("Digite a nota 2: ");
    scanf(" %f", &n2);
    media = (n1 + n2)/2.0;
    if(media>=7){
        printf("Você foi aprovado com média %g\n", media);
    }else{
       if (media<4){
            printf("Você está reprovado!\n");
       }else{
            printf("Você vai fazer final por: %f\n", 10-media);
       }
    }
}
