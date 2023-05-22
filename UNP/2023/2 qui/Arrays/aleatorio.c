#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    printf("%d\n", RAND_MAX);
    printf("Inteiros\n===============\n");
    for (int j = 1; j <= 10; j++)
    {
        for (int i = 1; i <= 6; i++)
        {
            printf("%d\t", rand() % 61);
        }
        printf("\n");
    }
    printf("Reais\n===============\n");
    for (int j = 1; j <= 10; j++)
    {
        for (int i = 1; i <= 6; i++)
        {
            printf("%.2f\t", (float)rand() / RAND_MAX * 100);
        }
        printf("\n");
    }
    return 1;
}