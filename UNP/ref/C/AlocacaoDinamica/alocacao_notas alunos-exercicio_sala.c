/* Cálculo da média e da variância de n reais */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
float media(int n, float *v);
float variancia(int n, float *v, float med);
void preencheVetorFloatRandom(int n,int num, float *v);
void exibeVetorFloatRandom(int tamanho, float *v);
int random(int n);
float desvioPadrao(float varia);

int main (void)
{
    srand((unsigned)time(NULL));
    int i, n, abaixo, acima, namedia;
    float *v, med, var, desvioP, maior, menor;
    /* leitura do número de valores */
    printf("Digite a quantidade de alunos:");
    scanf("%d", &n);
    /* alocação dinâmica */
    v = (float*) malloc(n*sizeof(float));
    if (v==NULL) {
        printf("Memoria insuficiente.\n");
        return 1;
    }
    /* leitura dos valores */
    preencheVetorFloatRandom(n,10, v);
    exibeVetorFloatRandom(n, v);

    med = media(n,v);
    var = variancia(n,v,med);
    desvioP = desvioPadrao(var);

    maior=-2; menor=20; abaixo=0;acima=0;namedia=0;
    for(i=0;i<n;i++){
        if(v[i]>maior)
            maior=v[i];
        if(v[i]<menor)
            menor=v[i];
        if(v[i] > med)
            acima++;
        else
            if(v[i]==med)
                namedia++;
        else
            abaixo++;

    }





    printf("\n\nMedia = %f Variancia = %f \nDesvio-Padrao=%f\n\n", med, var, desvioP);
    printf("\nAcima da media = %d", acima);
    printf("\nAbaixo da media = %d", abaixo);
    printf("\nNa media = %d", namedia);
    printf("\nA maior nota eh = %f", maior);
    printf("\nA menor nota eh = %f\n\n", menor);
    /* libera memória */
    free(v);
    return 0;
}
float media(int n, float *v){   // calcula a media de um vetor
    int i;
    float soma=0.0f;            //de n elementos
    for (i=0;i<n;i++)
        soma+=v[i];
    return soma/n;
}
float variancia(int n, float *v, float med){ //calcula a variancia
    int i;                                 //dada a media
    float s = 0.0f;                        //que eh passada como parametro
    for (i = 0;i<n;i++)                    //alem do tamanho n do vetor
        s+=((v[i]-med)*(v[i]-med));
    return s/n;
}
float desvioPadrao(float varia){
    return pow(varia, 0.5);
}
void preencheVetorFloatRandom(int n, int maximo, float vet[]){
    int i;
    float valor, num;
    for (i=0;i<n;++i)
    {
        num = 1 + random(maximo);
        valor = ((1+(10/num)) + random(maximo-1));
        if (valor > 10) valor = 10.0;
        vet[i]=valor;
    }//int n,

}
int random(int n){
    return rand() % n;
}

void exibeVetorFloatRandom(int n, float v[]){
    int t;
    printf("\nO vetor gerado pelo computador eh: \n\n");
    for(t=0;t<n;t++)
        printf("\t%4.2f\t", v[t]);
}
