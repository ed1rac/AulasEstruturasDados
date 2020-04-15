#include <stdio.h>
#include <stdlib.h>
/*  Função : Duas horas e diferença entre elas.
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int dif_horas(int hora1, int hora2);

main()
{
    int h1, min1, h2, min2, diferenca, horas, minutos;

    printf("\n\nPrograma que calcula o intervalo de tempo entre duas horas de um mesmo dia\n\n");
    printf("\nDigite a primeira hora (formato hh:mm):" );
    scanf("%d:%d", &h1, &min1);
    printf("\nDigite a segunda hora (formato hh:mm):" );
    scanf("%d:%d", &h2, &min2);

    diferenca = dif_horas(h1*60+min1, h2*60+min2);

    //escreve no formato hh:mm
    horas = (int) diferenca/60;
    minutos = (int) diferenca % 60;

    printf("\n\n%d:%d - %d:%d eh: %d:%d\n", h1,min1, h2, min2, horas, minutos  );
printf("\nOu o intervalo de tempo entre %d:%d e %d:%d eh: %0d:%0d\n\n",
                                                    h2,min2, h1, min1, horas, minutos);
    getch();
}

//a funcao dif_horas recebe os parametros em minutos
int dif_horas(int hora1, int hora2)
{
    return(hora2-hora1);
}
