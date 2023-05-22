#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define QL printf("\n")
main(){
	float num1, num2;
	char c, op;
    do{
            printf("\nDigite: numero OP numero\n");
            scanf("%f %c %f", &num1, &op, &num2);
            switch(op)
            {
                case'+':{
                        printf("=%g\n", num1+num2);
                        printf("\nA operacao foi de adicao\n");
                }break;
                case'-':    printf("=%g\n", num1-num2); break;
                case'*':    printf("=%g\n", num1*num2); break;
                case'/':    printf("=%g\n", num1/num2); break;
                case'^':    printf("=%g\n", pow(num1,num2)); break;
                default:    printf("Operador Invalido\n"); break;
            } 
            QL;
	      printf("Continua(S/N)?");
        scanf(" %c", &c);
    }while((c == 'S')||(c == 's')); 
    QL;
    system("pause");
}
