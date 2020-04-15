#include <stdio.h>
#include <stdlib.h>
/* Função : Converte altura em metros para pés e polegadas
// Autor : Waldemar Celes
// Data : 06/04/2012
// Observações: Demonstra o uso de scanf
*/
int main(){
    int pes;                //numero de pes
    float polegadas,altura; //polegadas e altura em metros

    //Captura a altura em metros
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    //calcula a altura em pés e polegadas
    altura*= 100; // altura = altura * 100   //converte em centimetros
    pes = (int) (altura/30.48);    //calcula o numero de pes - casting
    polegadas = (altura-pes * 30.48)/ 2.54 ;

    //exibe a altura convertida
    printf("Altura: %d pes %.2f polegadas\n", pes, polegadas);
    system("pause");
    //system("read");
    return 0;
}
