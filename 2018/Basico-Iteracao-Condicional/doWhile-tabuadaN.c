#include <stdio.h>
#include <stdlib.h>
#define QL printf("\n")
main(){
	int x, i;
	char c;
    do{
        printf("Digite um numero inteiro: ");
        scanf("%d", &x);
        printf("\nTabuada de %d\n", x);
        for (i=1;i<=10;i++)
			printf("%d X %d = %d\n", x,i, x*i );

        QL;
        printf("Continua(S/N)?");
        c = getch();
        QL;
    }while((c == 'S') || (c == 's'));
    QL;
    system("pause");
}

