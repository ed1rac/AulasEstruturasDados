#include <stdio.h>
#include <math.h>
int main(){
    //entrada
    float a,b,c,d, media, media_h, media_g, media_q;

    printf("Digite o primeiro valor: ");
    scanf(" %f", &a);
    printf("Digite o segundo valor: ");
    scanf(" %f", &b); 
    printf("Digite o terceiro valor: ");
    scanf(" %f", &c); 
    printf("Digite o quarto valor: ");
    scanf(" %f", &d);  
    //processamento    
   media = (a+b+c+d)/4;
   media_h = 4/((1/a)+(1/b)+(1/c)+(1/d));
   media_g = pow(a*b*c*d, 0.25);
   //media_q = pow((a*a+b*b+c*c+d*d)/4,0.5);
   media_q = sqrt((a*a+b*b+c*c+d*d)/4);

    //saídas
   printf("A média é: %.3f", media);
   printf("A média harmônica é: %.3f", media_h);
   printf("A média geomátrica é: %.3f", media_g);
   printf("A média quadrática é: %.3f", media_q);
   getchar();        
   
}