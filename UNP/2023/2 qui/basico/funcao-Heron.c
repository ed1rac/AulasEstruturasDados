#include <stdio.h>
#include <locale.h> //para localização
#include <math.h>   //para o fabs
#include <stdio.h>  //entrada e saída padrão
#include <stdlib.h> //para o rand()
// #include <iostream> //para os parametros de entrada e saida padrão
float heron(float x, float tol);
int main()
{
    // instrução para localizar o programa
    setlocale(LC_ALL, "Portuguese");
    // menu de opções
    int opcao;
    /* printf("Escolha uma opção:\n");
    printf("1 - Cálculo da raiz quadrada de um número pelo método de Heron\n");
    printf("2 - Cálculo da raiz quadrada de um intervalo de números \n");
    printf("3 - Cálculo da raiz quadrada de um intervalo de números com passo definido \n");
    printf("4 - Cálculo da raiz quadrada de um intervalo de números com passo definido e com erro definido \n");
    scanf("%d", &opcao);
    */
    // laço de 1 até 100 mostrando as raizes
    for (int i = 1; i <= 100; i++)
    {
        printf("A raiz quadrada de %d é %g\n", i, heron(i, 0.0001));
    }
    return 1;
}

float heron(float x, float tol)
{
    float est, erro, dif;
    tol = 0.0001;
    if ((x == (int)x) && (x >= 3)){
        est = x / 2;
    }
    else{
        // gerar um número real aleatório entre 0 e x/2
        est = (float)rand() / (float)(RAND_MAX / (x / 2));
    }

    dif = (est * est) - x;
    erro = fabs(dif);

    while (erro > tol){
        est = (est + x / est) / 2;
        dif = (est * est) - x;
        erro = fabs(dif);
    }
    return est;
}