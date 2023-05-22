#include <stdio.h>
float fatorial(int n);
int main()
{
    int i;
    for (int i = 0; i <= 20; i++)
    {
        printf("O fatorial de %d é %.0f\n", i, fatorial(i));
    }
    return 0;
}

float fatorial(int n)
{
    float fat;
    int i;
    fat = 1;
    for (int i = 1; i <= n; i++)
    {
        fat = fat * i; // fat*=1;
    }
    return fat;
}