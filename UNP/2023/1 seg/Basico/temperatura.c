#include <stdio.h>

// protótipos
float obter_float();
float celsius_para_fahrenheit(float celsius);
float fahrenheit_para_celsius(float fahrenheit);

int main()
{
    int opcao;
    float celsius, fahrenheit;
    do
    {
        printf("1 - Celsius para Fahrenheit\n");
        printf("2 - Fahrenheit para Celsius\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            celsius = obter_float();
            fahrenheit = celsius_para_fahrenheit(celsius);
            printf("A temperatura em Fahrenheit é: %f\n", fahrenheit);
            break;
        case 2:
            fahrenheit = obter_float();
            celsius = fahrenheit_para_celsius(fahrenheit);
            printf("A temperatura em celsius é: %f\n", celsius);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 1;
}

float obter_float()
{
    float num;
    printf("Digite uma temperatura: ");
    scanf(" %f", &num);
    return num;
}

float celsius_para_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_para_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}
