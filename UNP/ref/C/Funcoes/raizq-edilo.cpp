#include <stdio.h>
#include <stdlib.h>

float raiz(float x);

main(){
 	   float a,r; 
	   printf ("\n Introduza um número:");
	   scanf("%f",&a);
	   r=raiz(a);
	   printf ("\n\nA raiz quadrada de %f é %f",a,r);
	   getchar();
}

float raiz(float x){
	  float y,z;
	  y=x;
	  printf("X\t\tZ\t\tY\n======================================");
	  do{	
		  z=y;
		  y=(z+x/z)/2;
		  printf("\n%f\t%f\t%f", x, z, y);
	  }while (z!=y);
	  
	  return (y);
}
