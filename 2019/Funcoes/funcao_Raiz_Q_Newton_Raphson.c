#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //para fabs

double f (double x, double c); //fun?o a ser calculada
double derivF (double x);     //derivada da fun?o a ser calculada
double NewtonRaphson(double num, double x0, double precisao, int);  //Fun?o recursiva para calcular raiz

int main(){
    double num, raizq;
   /* do{
        printf("\nEntre com um numero positivo maior que zero: ");
        scanf("%lf", &num);
    }while(num<=0);
   */ 
    num = 2000;
    int iteracoes = 1;
    printf("\n\nCalculando a Raiz quadrada pelo metodo de Newton-Raphson\n");
    printf("Com aproximacao inicial igual a 1\n\n");
    printf("\n Iter.\t| x\t\t\t| f(x) \t\t\t| f'(x) \t\t|  Erro\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    raizq = NewtonRaphson(num, 1,0.0001, iteracoes);
    printf("\n\nRaiz quadrada de %g eh %.5lf\n\n", num, raizq);

  //  getchar();
}
double f (double x, double c){ //fun?o a ser calculada
    return ((x*x)-c);    //pode ser generalizado para a raiz N de qualquer numero c
}                       // basta fazer pow(x, N) e na funcao abaixo, derivF fazer N*x
double derivF (double x){
    return 2*x;
}
double NewtonRaphson(double num, double x0, double precisao, int iteracoes){
    double x1;
    x1 = x0 - ( f(x0, num)/ derivF(x0) );
    printf("%5d\t|%10.5lf\t\t|% -10.5lf\t\t|% -10.5lf\t\t|% -.6lf\n", iteracoes, x0, f(x0, num), derivF(x0), fabs(x0-x1));
    if(fabs(x0-x1)>precisao){        //testa o erro com a precisao
        x1= NewtonRaphson(num, x1, precisao, ++iteracoes);
    }
   // printf("\n\nEm %d iteracoes. Chegou-se ao resultado...", iteracoes);
    return x1;
}
