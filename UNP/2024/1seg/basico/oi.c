#include <stdio.h>

int main()
{

    char *palavras[2];

    palavras[0] = "OI!";
    palavras[1] = "BYE!";

    printf("%d %d %d %d %d %d\n", palavras[0][0], palavras[0][1], palavras[0][2], palavras[0][3], palavras[0][4], palavras[0][5]);
    printf("%c %c %c %c %c %c\n", palavras[0][0], palavras[0][1], palavras[0][2], palavras[0][3], palavras[0][4], palavras[0][5]);
    printf("%c%c%c%c\n", palavras[1][0], palavras[1][1], palavras[1][2], palavras[1][3]);
}