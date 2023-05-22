#include <stdio.h>
#include <stdlib.h>

int main(){
    int temp;
    printf("Digite a temperatura: "); 
    scanf(" %d", &temp);
    
    if(temp<10)
        printf("Temperatura muito fria\n");
        else
            if(temp<20)
                printf("Temperatura fria\n");
                else
                    if(temp<30)
                        printf("Temperatura agradável\n");
                        else
                            printf("Você, provavelmente está em Rio Branco\n");
               
     return 0;
}
