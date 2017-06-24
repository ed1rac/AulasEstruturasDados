#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){

    int i, qtdCarro, hora[30];
    //char *placa[10][30];
    char *placa[30];
    float valorHora, valor[30], total[30], total_geral=0;
    
    printf("Valor por hora: ");
    scanf(" %f", &valorHora);
    
    do{
        printf("Numero de carros: ");
        scanf(" %d", &qtdCarro);
        if(qtdCarro > 30)
          printf("\nO Estacionamento so possui 30 vagas\n");
        
    }while(qtdCarro>30);
   
    for (i=0;i<qtdCarro; i++){
        printf("Placa do veiculo %d: ", i+1);
        scanf(" %s", placa + i);
        printf("Placa do veiculo %d é %s\n", i+1, placa + i);              
        printf("Horas do veiculo %d: ", i+1);
        scanf("%d", &hora[i]);
        printf("\n");      
    }   
    
    for(i=0;i<qtdCarro;i++){
      total[i] = hora[i] * valorHora;
      total_geral+=total[i];
      printf("Veiculo da placa %s ficou %d horas e gastou %f reais \n", placa+i, hora[i], total[i]);
    }
    printf("\nValor total arrecadado no estacionamento é de: %f \n", total_geral);
 
}

