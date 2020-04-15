#include <stdio.h>
#define PULA printf("\n")  //CONSTANTE SIMBÓLICA
#define PI 3.141592
#define AREA_CIRCULO(raio) (PI * (raio) * (raio) ) //MACRO


int main(void) {
  printf("Hello World"); PULA;
  printf("Pulou uma linha lá em cima!"); PULA;
  printf("O valor de pi = %f", PI); PULA;
  double area = AREA_CIRCULO(4);
  printf("A área do círculo de raio 4 = %f", area); PULA;
  return 0;
}