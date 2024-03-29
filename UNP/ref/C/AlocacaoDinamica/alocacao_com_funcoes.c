#include <stdio.h>
#include <stdlib.h>
/*  Funcao: C�lculo da m�dia e da vari�ncia de n reais
    Autor: Edkallenn - Data: 20/05/2012
    Obs: Usando funcoes para TUDO                   */
int le_quant_int();
float *aloca(int n, float *);   //funcao para ALOCAR n floats
void preenche_vetor(int n, float []);
void exibe_vetor(int tamanho, float v[]);
float media(int n, float *v);
float variancia(int n, float *v, float med);

int main(){
    int i, n;
    float *vetor, *p_vetor; //declara o vetor (como ponteiro)
    float med, var;         //declara as variaveis
    n = le_quant_int(); // leitura do tamanho do vetor
    if (p_vetor = aloca(n, vetor)){
        preenche_vetor(n, p_vetor);
        exibe_vetor(n, p_vetor);
        med = media(n,p_vetor);
        var = variancia(n,p_vetor,med);
        printf("\n\nMedia = %g Variancia = %g \n", med, var);
        free(p_vetor);
    }else
        exit(1);    //sai do programa
    getchar();
    return 0;
}
float *aloca(int n, float *vetor){
    //funcao que aloca dinamicamente n floats
    vetor = (float*) calloc(n, sizeof(float));
    if (vetor==NULL){
        printf("Memoria insuficiente.\n");
        return 0;
    }
    return vetor;
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
