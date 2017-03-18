#include <stdio.h>
#include <stdlib.h>
/*  Funcao: Cálculo da média e da variância de n reais
    Autor: Edkallenn - Data: 20/05/2012
    Obs:                                            */
int le_quant_int();
void preenche_vetor(int n, float []);
void exibe_vetor(int tamanho, float v[]);
float media(int n, float *v);
float variancia(int n, float *v, float med);

int main ( void ){
    int i, n;
    float *vetor;    //declara o vetor (como ponteiro)
    float med, var;
    n = le_quant_int(); // leitura do tamanho do vetor
    // alocação dinâmica
    vetor = (float*) calloc(n, sizeof(float));
    if (vetor==NULL){
        printf("Memoria insuficiente.\n");
        return 1;
    }
    preenche_vetor(n, vetor);
    exibe_vetor(n, vetor);
    med = media(n,vetor);
    var = variancia(n,vetor,med);
    printf("\n\nMedia = %-4.2f Variancia = %-4.2f \n", med, var);
    free(vetor);
    return 0;
}
int le_quant_int(){
    int valor;
    printf("Digite a quantidade de alunos:");
    scanf("%d", &valor);
    return valor;
}
void preenche_vetor(int n, float vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<n;i++){
        do{
            printf("\nDigite a media do %do. aluno: ", i+1);
            scanf("%g", &vet[i]);
        }while(vet[i]>10);
    }
}
void exibe_vetor(int tamanho, float v[]){     //Exibe o vetor do tipo float
    int t;
    printf("\nO vetor digitado eh:\n");
    for (t=0;t<tamanho;t++)
        printf("%-4.2f ", v[t]);
}
float media(int n, float *v){   // calcula a media de um vetor
    int i;                      //de n elementos
    float soma=0.0f;
    for (i=0;i<n;i++)
        soma+=v[i];
    return soma/n;
}
float variancia(int n, float *v, float med){ //calcula a variancia
    int i;                                  //dada a media
    float s = 0.0f;                         //que eh passada como parametro
    for (i = 0;i<n;i++)                     //alem do tamanho n do vetor
        s+=((v[i]-med)*(v[i]-med));
    return s/n;
}
