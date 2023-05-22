#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota1, nota2, media, exame, quanto_falta;
    printf("Digite a N1 da disciplina: ");
    scanf(" %f", &nota1);
    printf("Digite a N2 da disciplina: ");
    scanf(" %f", &nota2);
    media = (nota1 + nota2)/2;
   if(media>=7){   //tomada de decisão
        printf("Voce foi APROVADO com media %.2f\n\n", media);
   }else{
       if(media>=4.0){
           quanto_falta = 10.0-media;
           printf("Voce faz final por %.2f\n\n", quanto_falta);
           printf("Quanto vc tirou na final?: ");
           scanf(" %f", &exame);
           if(exame>=quanto_falta){
               printf("Voce passou ARRASTADO!\n\n\n");
           }else{
               printf("Voce FEZ FINAL E FOI REPROVADO!!\n\n");
           }
       }else{
           printf("Voce foi REPROVADO!!\n\n");
        }
   }
   printf("Acabou!");
   system("pause");
}
