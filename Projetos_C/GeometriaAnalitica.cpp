#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//ESTÉTICA

float distancia(float a, float b, float c, float d)
{
      float distancia1;

      distancia1 = sqrt((pow((c-a), 2.0))+(pow((d-b), 2.0)));

      return (distancia1);
}
void cabecalho()
{
     printf("Geometria Analitica\npor Felipe Serachiani Clemente, 3E2");
     printf("\n\n");
}

int menu()
{
    int a;

     printf("1-Segmentos\n");
     printf("2-Circunferencia");
     printf("\n\nEntre com o numero da opcao:");
     scanf("%d", &a);
     return (a);
}

int menuptos()
{
    int a;


    system("cls");

    printf("1-Distancia entre 2 pontos\n");
    printf("2-Ponto medio de um segmento\n");
    printf("3-Razao de um ponto que divide um segmento\n");
    printf("4-Baricentro de um triangulo\n");

    printf("\n\nEntre com o numero da opcao:");
    scanf("%d", &a);

    if(a==1)
    {
            float a, b, c, d, dis;

            system("cls");
            printf("Entre com A=(a, b)\n\na:");
            scanf("%f", &a);
            printf("\nb:");
            scanf("%f", &b);
            printf("\n\nEntre com B=(c, d)\n\nc:");
            scanf("%f", &c);
            printf("\nd:");
            scanf("%f", &d);

            dis=distancia(a, b, c, d);

            system("cls");

            printf("Distancia AB = %.2f\n", dis);
           // getch();
    }
}

//MATEMATICA

int main()
{
    //escolhas
    int escolha1, escolha2;

    cabecalho();
    escolha1=menu();

    if(escolha1==1)
    {
                  menuptos();
    }


    system("pause");
    return 0;
}
