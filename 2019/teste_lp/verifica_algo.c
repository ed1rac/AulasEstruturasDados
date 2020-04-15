#include <stdio.h>
int verifica_algo(int);
int main(void) {
  int i;
  for(int i = 1;i<=15;i++){
    printf("%d\t%d\n", i, verifica_algo(i));
  }


  return 0;
}
int verifica_algo(int n){
  int x,y,z, soma = 0;
  for(x=0;x<=n;x++){
    for(y=0;y<=x;y++){
      for(z=y;z<=x;z++){
        soma++;
      }
    }
  }
  return soma;
}