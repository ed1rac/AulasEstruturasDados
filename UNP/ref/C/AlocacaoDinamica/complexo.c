#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double real;
    double imag;
} Complexo;

Complexo *criarComplexo(double real, double imag)
{
    Complexo *complexo = (Complexo *)malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->imag = imag;
    return complexo;
}
void destruiComplexo(Complexo *complexo)
{

    free(complexo);
}
void lerComplexo(Complexo *complexo)
{
    printf("Digite a parte real: ");
    scanf("%lf", &(complexo->real));
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &(complexo->imag));
}
void mostrarComplexo(Complexo *complexo)
{
    printf("(%lf, %lf)\n", complexo->real, complexo->imag);
}
Complexo *somaComplexos(Complexo *c1, Complexo *c2)
{
    double real = c1->real + c2->real;
    double imag = c1->imag + c2->imag;
    return criarComplexo(real, imag);
}
Complexo *subtraiComplexos(Complexo *c1, Complexo *c2)
{
    double real = c1->real - c2->real;
    double imag = c1->imag - c2->imag;
    return criarComplexo(real, imag);
}
Complexo *multiplicarComplexos(Complexo *c1, Complexo *c2)
{
    double real = (c1->real * c2->real) - (c1->imag * c2->imag);
    double imag = (c1->real * c2->imag) + (c1->imag * c2->real);
    return criarComplexo(real, imag);
}
Complexo *dividirComplexos(Complexo *c1, Complexo *c2)
{
    double denominador = (c2->real * c2->real) + (c2->imag * c2->imag);
    double real = ((c1->real * c2->real) + (c1->imag * c2->imag)) / denominador;
    double imag = ((c1->imag * c2->real) - (c1->real * c2->imag)) / denominador;
    return criarComplexo(real, imag);
}
int main()
{
    Complexo *c1 = criarComplexo(0, 0);
    Complexo *c2 = criarComplexo(0, 0);
    Complexo *resultado = NULL;

    printf("\nPrimeiro numero Complexo\n");
    lerComplexo(c1);
    printf("\nSegundo numero Complexo\n");
    lerComplexo(c2);
    printf("Adicao: \n");
    resultado = somaComplexos(c1, c2);
    mostrarComplexo(resultado);
    printf("Subtracao: \n");
    resultado = subtraiComplexos(c1, c2);
    mostrarComplexo(resultado);
    printf("Multiplicacao: \n");
    resultado = multiplicarComplexos(c1, c2);
    mostrarComplexo(resultado);
    printf("Divisao: \n");
    resultado = dividirComplexos(c1, c2);
    mostrarComplexo(resultado);
    destruiComplexo(c1);
    destruiComplexo(c2);

    return 0;
}