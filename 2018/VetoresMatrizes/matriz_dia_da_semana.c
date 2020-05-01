#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Função : Impriome o dia da semana a partir dde uma data
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                                    */
#define PULA printf("\n")
int dia_semana(int, int, int);
main(){
    char diasemana[7][14]= {"Domingo",
                            "Segunda-feira",
                            "Terca-Feira",
                            "Quarta-Feira",
                            "Quinta-Feira",
                            "Sexta-Feira",
                            "Sabado"
                            };

    int dia, mes, ano;
    const char ESC = 27;
    do{
        puts("Programa que exibe o dia da semana de uma data"); PULA;
        printf("Digite a data na forma dd, mm, aaaa: ");
        scanf("%d, %d, %d", &dia, &mes, &ano);
        printf("\nO dia da semana desta data e: %s\n\n",
               diasemana[dia_semana(dia, mes, ano)]);
        printf("ESC para terminar ou ENTER para recomecar\n\n");
    }while (getchar()!=ESC);
    getchar();
    return 0;
}
int dia_semana( int dia, int mes, int ano){
    int dSemana = ano + dia + 3 * (mes - 1) - 1;
    if (mes<3)
        ano--;
    else
        dSemana -= (int)(0.4*mes+2.3);
    dSemana+= (int)(ano/4)- (int)((ano/100+1)*0.75);
    dSemana %= 7;
    return dSemana;
}
