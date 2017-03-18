#include <stdio.h>
#include <stdlib.h>
/*  Função : Média e variância de 10 numeros reais (vetores)
    Autor : Edkallenn  - Data : 06/04/2012 */
#define MAX 10  //tamanho maximo do vetor
void preenche_vetor(float z[MAX]);    //prototipo das funcoes (procedimentos)
void exibe_vetor(float []);
float media(int n, float *);     //prototipo alternativo(mostra uso ponteiros)
float variancia(int n, float *v, float med);
main(){
    float med, var, x[MAX];       //media, variancia e vetor original
    preenche_vetor(x);
    med = media(MAX, x);
    var = variancia(MAX, x, med);
    exibe_vetor(x);
    printf("\n\nA Media = %g e a Variancia = %g \n", med, var);
    getchar(); //no devC++ antes desta coloque system("pause"); ou getchar();
}
float media(int n, float *v){   //funcao que calcula a media de um vetor
    float soma;                  //de n elementos
    soma=0.0f;
    int i;
    for (i=0;i<n;i++)
        soma+=v[i];
    return soma/n;
}
float variancia(int n, float *v, float med){ //calcula a variancia dada a media
    float s;                                 //que eh passada como parametro
    int i;                                  //alem do tamanho n do vetor
    s = 0.0f;
    for (i = 0;i<n;i++)
        s+=((v[i]-med)*(v[i]-med));
    return s/n;
}
void exibe_vetor(float v[]){     //Exibe o vetor do tipo float
    int t;
    printf("\nO vetor digitado eh\n\n");
    for (t=0;t<MAX;t++)
        printf("%-3g ", v[t]);
}
void preenche_vetor(float vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<MAX;++i){ //quaisquer alteracoes aqui afetam x[MAX] (referencia)
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%g", &vet[i]);
        }
}
