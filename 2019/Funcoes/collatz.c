#include <stdio.h>

int collatz(int a)
{
    int k = 1;
    while (a != 1)
    {
        printf("%d ", a);
        if (k % 10 == 0)
            putchar('\n');
        if (a % 2 == 0)
            a = a / 2;
        else
            a = 3 * a + 1;
        k++;
    }
    printf("1\n");
    return k;
}

int main(void)
{
    int a;
    scanf("%d", &a);
    printf("\n%d\n", collatz(a));
    return 0;
}
