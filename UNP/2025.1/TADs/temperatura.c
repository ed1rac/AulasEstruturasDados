#include <stdio.h>

typedef struct
{
    float valor;
} Temperatura;

float para_fahrenheit(Temperatura t)
{
    return (t.valor * 9.0 / 5.0) + 32;
}

float para_celsius(Temperatura t)
{
    return (t.valor - 32) * 5.0 / 9.0;
}

int main()
{
    Temperatura t = {30.0};
    printf("Celsius: %.2f → Fahrenheit: %.2f\n", t.valor, para_fahrenheit(t));
    return 0;
}
