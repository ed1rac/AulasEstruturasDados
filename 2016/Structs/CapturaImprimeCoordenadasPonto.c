#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x;
    float y;
};

main(){
    struct ponto p;
    printf("\n\nDigite as coordenadas do ponto(x,y): ");
    scanf("%f,%f", &p.x, &p.y);
    printf("\n\nO ponto digitado foi: P(%.2f, %.2f)\n", p.x, p.y);
    getchar();
}
