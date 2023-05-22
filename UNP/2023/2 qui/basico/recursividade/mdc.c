#include <stdio.h>
int mdc(int x, int y);
int main()
{
    printf("O MDC de 30 e 12 é: %d", mdc(30, 12));

    return 1;
}

int mdc(int x, int y)
{
    if (y == 0)
        return x;
    else
    {
        if (x < y)
        {
            return mdc(y, x);
        }
        else
        {
            return mdc(y, x % y);
        }
    }
}