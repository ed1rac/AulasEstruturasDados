#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int aleatorio(int numero);
int main()
{
	srand(time(NULL));				  // reinicializa a semente
	printf("%d\n", rand() % 100 + 1); // jeito antigo
	for (int i = 1; i < 10; ++i)
	{
		printf("%d\n", aleatorio(100)); // jeito novo usando a funcao
	}

	// getchar();
	return 1;
}
int aleatorio(int numero)
{
	return (int)(rand() % numero) + 1;
}