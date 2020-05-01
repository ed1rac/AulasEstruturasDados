#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num>0){
        if(num<1000){
            if(num%2==0){
                printf("O numero %d e' par!\n", num);
            }else{
                printf("O numero %d e' impar!\n", num);
            }  
        }else{
            printf("O numero e' maior que 1000!\n");
        }
    }else{
        printf("O numero e' menor que zero!\n\n'");
    } 
    system("pause");
}
