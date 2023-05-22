#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // c lculo da raiz quadrada de um n£mero pelo m‚todo de heron
    float a, est, y, erro, dif;
    int passo;
    printf("Digite um n£mero: ");
    scanf(" %f", &a);

    if ((a == (int)a) && (a >= 3))
    {
        est = a / 2;
    }
    else
    {
        // gerar um n£mero real aleat¢rio entre 0 e a/2
        est = (float)rand() / (float)(RAND_MAX / (a / 2));
    }
    passo = 1;
    dif = (est * est) - a;
    printf("======================================\n");
    printf(" #  |\test\t       |\t   dif  \n");
    printf("======================================\n");
    printf("%d\t%f\t\t%f\n", passo, est, dif);

    erro = fabs(dif);
    while (erro > 0.0001)
    {
        est = (est + a / est) / 2;
        passo++;

        dif = (est * est) - a;
        erro = fabs(dif);
        if (passo == 2)
        {
            printf("%d\t%g\t\t\t%g\n", passo, est, dif);
            continue;
        }
        printf("%d\t%g\t\t\t%g\n", passo, est, dif);
    }
    printf("\n\nA raiz quadrada de %g ‚ %f\n\n", a, est);
    return 0;
}