#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //para fabs

float f (float x, float c); //função a ser calculada
float derivF (float x);     //derivada da função a ser calculada
float NewtonRaphson(float num, float x0, float precisao);  //Função recursiva para calcular raiz

int main(){
    float num, raizq;
    do{
        printf("\nEntre com um numero positivo maior que zero: ");
        scanf("%f", &num);
    }while(num<=0);
    printf("\n\nCalculando a Raiz quadrada pelo metodo de Newton-Raphson\n");
    printf("Com aproximacao inicial igual a 1\n\n");
    printf("\n x\t\t| f(x) \t\t\t| f'(x) \t\t|  Erro\n");
    printf("---------------------------------------------------------------------------\n");
    raizq = NewtonRaphson(num, 1,0.001);
    printf("\n\nRaiz quadrada de %g eh %f\n\n", num, raizq);

    getchar();
}
float f (float x, float c){ //função a ser calculada
    return ((x*x)-c);    //pode ser generalizado para a raiz N de qualquer numero c
}                       // basta fazer pow(x, N) e na funcao abaixo, derivF fazer N*x
float derivF (float x){
    return 2*x;
}
float NewtonRaphson(float num, float x0, float precisao){
    float x1;
    x1 = x0 - ( f(x0, num)/ derivF(x0) );
    printf("%.5f\t\t|% .5f\t\t|% .5f\t\t|% .6f\n", x0, f(x0, num), derivF(x0), fabs(x0-x1));
    if(fabs(x0-x1)>precisao){        //testa o erro com a precisao
        x1= NewtonRaphson(num, x1, precisao);
    }
    return x1;
}
