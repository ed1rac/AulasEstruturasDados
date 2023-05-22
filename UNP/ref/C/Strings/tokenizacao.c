#include <stdio.h>
#include <string.h>

int main(void){
	
	int toknum = 0;
	char src[] = "Ola, mundo cruel. Meu nome e' Edkallenn, o lindo!";
	const char delimiters[] = ", !";
	char *token = strtok(src, delimiters);
	while (token != NULL){	
		printf("%d: [%s]\n", ++toknum, token);
		token = strtok(NULL, delimiters);
	}
/* source is now "Hello\0, world\0\0" */
}
