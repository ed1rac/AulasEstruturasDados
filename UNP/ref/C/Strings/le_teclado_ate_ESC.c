#include <stdio.h>
 
int main(void)
{
 
   char cTeclado;
 
   /* fica lendo do teclado até que seja pressionado a tecla ESC */
   while((cTeclado=getchar())!=27)
   {
      printf("\n%c - %d", cTeclado, cTeclado);
   }
 
   return (0);
}