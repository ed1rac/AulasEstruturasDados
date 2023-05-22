#include <stdio.h>

#define YES 1
#define NO 0

int main() /* count lines, words, chars in input */
{
    int c, nl, nw, nc, word;

    word = NO;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            word = NO;
        else if (word == NO)
        {
            word = YES;
            ++nw;
        }
    }
    printf("Linhas: %d - Palavras: %d - Caracteres: %d\n", nl, nw, nc);
}