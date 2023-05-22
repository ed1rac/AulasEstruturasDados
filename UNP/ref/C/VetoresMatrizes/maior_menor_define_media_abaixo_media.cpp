#include <stdio.h>
#include <stdlib.h>
#define TAM 10  //tamanho maximo do vetor
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
/*  Função :Ler notas, dizer a maior, a menor, a media e quantas abaixo
**    Autor : Edkallenn  - Data : 06/04/2012
**   Observações: Usa macro define para achar o maior e o menor
*/
void preenche_vetor_float(int n, float []);   //prototipo das funcoes
void exibe_vetor_float(int n, float vet[TAM]);
float media(int n, float *v);

main(){
    int j, abaixo=0;       //vetor original
    float notas[TAM], maior, menor, med;  //e outras variaveis
    maior =-1; menor = 11;
    preenche_vetor_float(TAM, notas);
    exibe_vetor_float(TAM, notas);
    med = media(TAM, notas);
    for(j=0;j<TAM;j++){
        maior = MAX(maior, notas[j]);
        menor = MIN(menor, notas[j]);
        if(notas[j]<med)
            abaixo++;
    }
    printf("\nA media eh: %5.2f\nA maior nota eh: %5.2f", med, maior);
    printf("\nA menor eh: %5.2f\nAbaixo da media: %d\n\n", menor, abaixo);
    getchar();
    return 0;
}
void exibe_vetor_float(int n, float v[]){      //Exibe o vetor de floats
    int t;
    printf("\nO vetor digitado eh\n\n");
    for (t=0;t<n;t++)
        printf("\t%5.2f\t", v[t]);
}
void preenche_vetor_float(int n, float vet[]){  // Preenche o vetor com float
    int i;
    for (i=0;i<n;i++){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%f", &vet[i]);
    }
}
float media(int n, float *v){   //funcao que calcula a media de um vetor
    float soma;
    soma =0.0f;
    int i;
    for (i=0;i<n;i++)
        soma+=v[i];
    return soma/n;
}
