#include <stdio.h>
// #define EOF -1

int main() /* copy input to output; 2nd version */
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);

    return 0;
}
