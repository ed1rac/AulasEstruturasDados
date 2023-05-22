#include <stdio.h>
#include <locale.h> //para localização

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // variáveis
    float celsius, farenheit;
    // entradas
    printf("Digite uma temperatura em º Celsius: ");
    scanf("%f", &celsius);
    // processamento
    farenheit = (celsius * 9 / 5) + 32;
    // saída
    printf("%g ºC = %g ºF\n", celsius, farenheit);

    if (celsius < 15)
    {
        printf("Está CONGELANDO!\n");
    }
    else
    {
        if (celsius >= 15 && celsius < 20)
        {
            printf("Está frio!\n");
        }
        else
        {
            if (celsius >= 20 && celsius < 30)
            {
                printf("Está agradável!\n");
            }
            else
            {
                if (celsius >= 30 && celsius < 40)
                {
                    printf("Está quente!\n");
                }
                else
                {
                    printf("Está MUITO QUENTE!\n");
                }
            }
        }
    }

    return 1;
}