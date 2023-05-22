#include <stdio.h>
#include <math.h>

int main() {
    printf("Raiz Quadrada - método divisão e média\n==================\n");

  int num, i;
  double raiz1, tol, raiz2, erro;
  printf("Digite um número para extair a raiz: ");
  scanf(" %d",  &num);  

  tol = 0.000001;
  erro = 0.1;
  i = 0;
  

  if (num>0){
    raiz1 = num/2.0;
    while(erro>tol){
      printf("Iteração %d\n", ++i);
      printf("Raiz 1 = %f\n", raiz1);
      raiz2 = (raiz1 + (num/raiz1))/2.0;
      erro = fabs((raiz2-raiz1)/raiz2);
      printf("Raiz 2 = %f\n", raiz2);
      printf("Erro = %f\n==========\n", erro);
      raiz1 = raiz2;
    }
    printf("A raiz de %d é %f\n", num, raiz1);   
    
  }else{
    printf("Raiz quadrada de números negativos não pertence aos Reais!\n");
  }
  getchar();    
  return 0;
}