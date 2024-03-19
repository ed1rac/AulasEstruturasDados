#include <stdio.h>

int main()
{
    // calcular a area do circulo
    float raio, area;
    printf("Programa para calcular a área do círculo\n");
    printf("Digite o raio: ");
    scanf(" %f", &raio);
    // processamento
    area = 3.141592 * raio * raio;
    // saida
    printf("A área do círculo de raio %g é: %f\n\n", raio, area);
}
