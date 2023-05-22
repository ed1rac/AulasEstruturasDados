#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float a, b, c, delta, x1,x2, raizdelta;
	printf("Digite os coeficientes a, b e c de uma eq. de 2º grau: ");
	scanf("%f, %f, %f", &a, &b, &c);
	printf("\na = %f, b = %f, c = %f\n", a, b, c);

	if (a==0){
		printf("Não e' equação do segundo grau!\n\n");
		exit(-1);
	}else{
		delta = (b*b)-(4*a*c);
		printf("Delta = %f\n", delta);
		if(delta<0){
			printf("Não existem raizes reais\n\n");
			exit(-1);
		}else{
			if(delta==0){
				printf("A raiz é: %f", -b/(2*a));
			}else{
				raizdelta = sqrt(delta);
				printf("A raiz de delta e': %f\n", raizdelta);
				x1 = (-b + raizdelta) / (2*a);
				x2 = (-b - raizdelta) / (2*a);
				printf("As raizes sao:\nx1 = %f\nx2 = %f\n\n", x1, x2);
			}
		}
	}	
    getchar();
    return 1;
}
