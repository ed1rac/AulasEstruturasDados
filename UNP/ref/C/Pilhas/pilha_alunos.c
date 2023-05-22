#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Tipo Aluno
typedef struct aluno{
  int matricula;
  char curso[40];
  float valor_parcela;
}Aluno;

typedef struct pilha{
  int n;  //quantidade de elementos da pilha
  int topo;
  Aluno vet[MAX];
}Pilha;

//protótipos
Pilha* cria_pilha();
Aluno le_aluno();
int pilha_vazia(Pilha *p);
Aluno pop(Pilha* p);
void pilha_libera(Pilha* p);
void push(Pilha* p, Aluno temp);
void pilha_imprime(Pilha *p);

int main(){
  Pilha* pilha_alunos;
  Aluno aluno;
  pilha_alunos = cria_pilha();
  push(pilha_alunos, le_aluno());
  push(pilha_alunos, le_aluno());
  push(pilha_alunos, le_aluno());  
  pilha_imprime(pilha_alunos);
  aluno = pop(pilha_alunos);
  printf("Retiramos o curso: %s\n", aluno.curso);
  pilha_imprime(pilha_alunos);
  pilha_libera(pilha_alunos);
  return 0;
}

Aluno le_aluno(){
  Aluno temp;
  printf("Digite a matricula.........: "); scanf(" %d", &temp.matricula);
  printf("Digite o curso.............: "); scanf(" %40[^\n]", temp.curso);
  printf("Digite o valor da parcela..: "); scanf(" %f", &temp.valor_parcela);
  printf("\n");
  return temp;
}

Pilha* cria_pilha(){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->n = 0;
  p->topo = 0;
  return p;
}
void push(Pilha* p, Aluno temp){
  if(p->n == MAX){     //capacidade esgotada -> stack overflow
    printf("Capacidad da pilha estourou!\nStack Overflow!\n");
    exit(1);  //aborta o programa
  }
  //insere elemento na próxima posição livre
  p->vet[p->n] = temp;
  p->n++;
  p->topo = p->n-1;
}
Aluno pop(Pilha* p){
  Aluno temp;
  if(pilha_vazia(p)){
    printf("Pilha Vazia!\n");
    exit(1);
  }
  temp = p->vet[p->topo];
  p->n--;
  p->topo = p->n-1;
  return temp;
}

int pilha_vazia(Pilha *p){
  return (p->n ==0);
}

void pilha_libera(Pilha* p){
  free(p);
}

void pilha_imprime(Pilha *p){
  int i;
  printf("Conteúdo da Pilha: \n==================\n");
  for(i = p->topo;i>=0;i--){
    printf("Matricula.........: %d\n", p->vet[i].matricula); 
    printf("Curso.............: %s\n",p->vet[i].curso); 
    printf("Valor da parcela..: %f\n",p->vet[i].valor_parcela); 
    printf("\n");
  }

}



