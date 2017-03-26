#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    //declarar as variaveis
    float lado_a, lado_b, lado_c, semi, area;
    //ENTRADA
    printf("Digite o lado a: ");  
    scanf(" %f", &lado_a);  
    printf("Digite o lado b: ");  
    scanf(" %f", &lado_b);  
    printf("Digite o lado c: ");  
    scanf(" %f", &lado_c);  
    //PROCESSAMENTO
    semi = (lado_a+lado_b+lado_c)/2.0;
    area = sqrt((semi*(semi-lado_a)*(semi-lado_b)*(semi-lado_c)));
    //SAIDA
    printf("A area do triangulo de lados a = %f, b = %f e c = %f é = %f\n\n", lado_a, lado_b, lado_c, area);
    system("pause");
}
