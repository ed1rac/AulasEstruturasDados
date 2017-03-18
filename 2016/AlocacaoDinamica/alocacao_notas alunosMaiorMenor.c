/* Cálculo da média e da variância de n reais */
#include <stdio.h>
#include <stdlib.h>
float media(int n, float *v);
float variancia(int n, float *v, float med);
float maior(int n, float *);
float menor(int, float*);

int main (void)
{
    int i, n, acima, abaixo;
    float *v;
    float med, var, maximo, minimo;
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
    for (i = 0; i < n; i++){
        printf("Digite a media do %do. aluno: ", i+1);
        //scanf("%f", &v[i]);
        scanf("%f", v+i);
    }
    med = media(n,v);
    var = variancia(n,v,med);
    maximo = maior(n, v);
    minimo = menor(n, v);
    printf("Media = %f Variancia = %f \n", med, var);

    /* descobre acima e abaixo da media */
    acima = 0;
    abaixo = 0;
    for (i = 0; i < n; i++){
        if(v[i]> med)
            acima++;
        if(v[i]< med)
            abaixo++;
    }
    printf("A maior nota eh: %.2f\n", maximo);
    printf("A menor nota eh: %.2f\n", minimo);
    printf("Ha %d notas acima da media\n", acima);
    printf("Ha %d notas abaixo da media\n", abaixo);
    /* libera memória */
    free(v);
    getch();
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
float maior(int n, float v[]){
    int i;
    float max;
    max = v[0];    //max = v[0];
    for(i=1;i<n;i++){
        if(v[i]>max)
            max = v[i];
    }
    return max;

}
float menor(int n, float v[]){
    int i;
    float min;
    min = v[0];    //max = v[0];
    for(i=1;i<n;i++){
        if(v[i]<min)
            min = v[i];
    }
    return min;
}




