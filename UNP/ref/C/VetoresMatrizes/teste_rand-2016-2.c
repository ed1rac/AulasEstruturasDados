#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random(int numero);

int main()
{
	srand(time(NULL));				  // reinicializa a semente
	printf("%d\n", rand() % 100 + 1); // jeito antigo
	for (int i = 1; i < 10; ++i)
	{
		printf("%d\n", random(100)); // jeito novo usando a função
	}

	// getchar();
	return 0;
}
int random(int numero)
{
	return (int)(rand() % numero) + 1;
}