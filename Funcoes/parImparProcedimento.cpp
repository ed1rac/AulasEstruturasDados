#include <stdio.h>
#include <stdlib.h>

int leia_int(void);    //prototipação de funções
void par(int);

main()
{     //declaracao de variaveis
      int num;
     do{
        num = leia_int();
         if (num==-1) break;
             par(num);
     }while (num!=-1);
     //getch();  ----> Essa funcao precisa da biblioteca conio.h
     system("pause");
}

int leia_int()
{

 int numero;
 printf("Insira um numero inteiro (-1 p/ fim): ");
 scanf("%d", &numero);
 return numero;
}

void par(int epar)
{

 if ((epar%2) == 0)
    printf("\n\n O numero %d e par!\n\n", epar);
 else
     printf("\n\n O numero %d e impar!\n\n", epar);
}

