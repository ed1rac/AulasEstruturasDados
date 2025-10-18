#include <stdio.h>

typedef struct
{
    float largura;
    float altura;
} Retangulo;

float calcular_area(Retangulo r)
{
    return r.largura * r.altura;
}

float calcular_perimetro(Retangulo r)
{
    return 2 * (r.largura + r.altura);
}
void exibir_retangulo(Retangulo r)
{
    printf("Largura: %.2f\n", r.largura);
    printf("Altura: %.2f\n", r.altura);
    printf("Área: %.2f\n", calcular_area(r));
    printf("Perímetro: %.2f\n", calcular_perimetro(r));
}

int main()
{
    Retangulo r = {5.0, 3.0};
    printf("Área: %.2f\n", calcular_area(r));
    printf("Perímetro: %.2f\n", calcular_perimetro(r));
    return 0;
}
