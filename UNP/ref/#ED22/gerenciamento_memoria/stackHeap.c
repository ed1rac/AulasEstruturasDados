#include <stdio.h>

int main()
{
    // alocação estática
    int x, y;
    x = 5;
    printf("x = %d\n", x);

    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    ptr = &y;
    *ptr = 5;
    // exibindo o conteúdo de *ptr
    printf("*ptr = %d\n", *ptr);
}