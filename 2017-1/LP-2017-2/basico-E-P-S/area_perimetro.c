#include <stdio.h>>

int main(){
	
	float base, altura, perimetro, area;   //declaração de variáveis
	
	//Entrada
	printf("Digite a base do retângulo: ");   
	scanf(" %f", &base);
	printf("Digite a altura do retângulo: ");   
	scanf(" %f", &altura);
	//Processamento
	perimetro = (2*base) + (2*altura);
	area = base * altura;	
	//Saída
	printf("A area do retangulo = %f\n", area);  
	printf("O perimetro do retangulo = %f\n", perimetro);
	
	getchar();
	return 0;
}
