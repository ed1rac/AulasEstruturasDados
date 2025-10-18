#include <stdio.h>

float fatorial(int);

int main()
{
    int num = 20;
    for (int i = 0; i <= num; i++)
    {
        printf("%d! = %g\n", i, fatorial(i));
    }

    return 0;
}

float fatorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}
