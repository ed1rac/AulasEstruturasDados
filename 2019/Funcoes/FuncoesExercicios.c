#include <stdio.h>
#include <stdlib.h>
/*  Função: Funcoes pereba
    Autor: Edkallenn
    Data:05/03/2015
    Observações:
*/

float areaEsfera (float r);
float vm (float km, float horas);
int somatorio (int num);
float converteGrauRadiano (float angulo);


main(){
   float raio, espaco, tempo, ang;
   int num1;
   printf("Digite o raio de uma esfera: ");
   scanf("%f" ,&raio);
   printf("A area da esfera de raio %f = %f\n\n", raio, areaEsfera(raio));

   printf("Digite o espaco percorrido: "); scanf("%f", &espaco);
   printf("Digite o tempo gasto: ");       scanf("%f", &tempo);
   printf("A velocidade media do percurso foi = %f km/h\n\n", vm(espaco,tempo));

   printf("Digite um numero inteiro: "); scanf("%d",&num1);
   printf("O somatorio eh = %d\n", somatorio(num1));

   printf("Digite o angulo: "); scanf("%f", &ang);
   printf("o angulo %f convertido para radianos = %f", ang, converteGrauRadiano(ang));

   getch();
}

float areaEsfera (float r){
    return 4 * 3.141592 * r * r;
}
float vm (float km, float horas){
    float resultado;
    resultado = km/horas;
    return resultado;
}
int somatorio (int num){
    int i, soma;
    soma = 0;
    for (i=1;i<=num;i++){
        soma = soma + i;
    }
    return soma;
}
float converteGrauRadiano (float angulo){
    float resultado;
    resultado=(angulo * 3.141592) / 180 ;
    return resultado;
}

