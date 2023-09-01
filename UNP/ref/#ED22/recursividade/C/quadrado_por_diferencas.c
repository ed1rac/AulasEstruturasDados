#include <stdio.h>

long quad(int);

int main()
{
    int i;
    for (i = 0; i <= 40; i++)
    {
        printf("%d ^ 2 = %ld\n", i, quad(i));
    }
    return 1;
}

long quad(int x)
{
    if ((x == 0) || (x == 1))
        return x;
    if (x == 2)
        return 4;
    return 2 + quad(x - 1) + (quad(x - 1) - quad(x - 2));
}