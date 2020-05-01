#include <stdio.h>
#include <stdlib.h>



struct ponto{
    float x;    //POderia ser float x,y;
    float y;
};

main(){
    struct ponto p; //declara��o da vari�vel p do tipo strucut ponto

    p.x = 10.0;
    p.y = 5.0;

    printf("O ponto = P(%f,%f)\n", p.x,p.y);
    

    getchar();
}
