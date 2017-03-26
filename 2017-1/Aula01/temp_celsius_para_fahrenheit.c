#include<stdio.h>
#include<stdlib.h>

int main(){
    //declarar as variaveis
    float celsius, fahrenheit;
    //ENTRADA
    printf("Digite uma temperatura em graus celsius: ");  
    scanf(" %f", &celsius);  
    //PROCESSAMENTO
    fahrenheit = (9*celsius+160)/5;
    //SAIDA
    printf("%.2fo. C = %.2fo. Fahrenheit\n\n", celsius, fahrenheit);
    system("pause");
}
