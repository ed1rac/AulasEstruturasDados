#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //para fabs

double f (double x, double c, double N); //fun?o a ser calculada
double derivF (double x, double n);     //derivada da fun?o a ser calculada
double NewtonRaphson(double num, double n, double x0, double precisao, int);  //Função recursiva para calcular raiz

int main(){
    double n,num, raizn;
   /* do{
        printf("\nEntre com um numero positivo maior que zero: ");
        scanf("%lf", &num);
    }while(num<=0);
   */ 
    num = 0.2; //numero para se extrair a raiz
    n=2; //raiz n
    int iteracoes = 1;
    printf("\n\nCalculando a %g-ésima raiz pelo metodo de Newton-Raphson\n", n);
    printf("Com aproximacao inicial igual a 1\n\n");
    printf("\n Iter.\t| x\t\t\t| f(x) \t\t\t| f'(x) \t\t|  Erro\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    raizn = NewtonRaphson(num, n, 1,0.000001, iteracoes);
    //printf("\n\nA %g-ésima raiz de %g eh %.5lf\n\n",n, num, raizn);
    printf("\n\nA %g-ésima raiz de %lf eh %g\n\n",n, num, raizn);

  //  getchar();
}
double f (double x, double c, double N){    //função a ser calculada
    return (pow(x,N)-c);                    //pode ser generalizado para a raiz N de qualquer numero c
}                                           // basta fazer pow(x, N) e na funcao abaixo, derivF fazer N*x^N-1
double derivF (double x, double N){
    return pow(N*x,N-1) ;
}
double NewtonRaphson(double num, double n, double x0, double precisao, int iteracoes){
    double x1;
    x1 = x0 - ( f(x0, num,n)/ derivF(x0,n) );
    printf("%5d\t|%10.5lf\t\t|% -10.5lf\t\t|% -10.5lf\t\t|% -.6lf\n", iteracoes, x0, f(x0, num,n), derivF(x0,n), fabs(x0-x1));
    if(fabs(x0-x1)>precisao){        //testa o erro com a precisao
        x1= NewtonRaphson(num, n, x1, precisao, ++iteracoes);
    }
   // printf("\n\nEm %d iteracoes. Chegou-se ao resultado...", iteracoes);
    return x1;
}
