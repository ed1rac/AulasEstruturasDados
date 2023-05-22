#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{  //tipo Aluno
  char nome[40];
  int matricula;
  char curso[40];
  float valor_parcela;
}Aluno;

typedef struct lista* link;  //link para uma lista igual
typedef struct lista{ //tipo Lista
  Aluno aluno;
  link prox;
}Lista;

Aluno le_aluno(){
  Aluno temp;
  printf("Digite o nome do aluno...: "); scanf(" %40[^\n]", temp.nome);
  printf("Digite a matrícula.......: "); scanf(" %d", &temp.matricula);
  printf("Digite o curso...........: "); scanf(" %40[^\n]", temp.curso);
  printf("Digite o valor da parcela: "); scanf(" %f", &temp.valor_parcela);
  printf("\n");
  return temp;
}

Lista* lista_cria(){
  return NULL;
}
Lista* lista_insere(Lista* lista, Aluno temp){
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  strcpy(novo->aluno.nome, temp.nome);
  novo->aluno.matricula = temp.matricula;
  strcpy(novo->aluno.curso, temp.curso);
  novo->aluno.valor_parcela = temp.valor_parcela;
  novo->prox = lista;

  return novo;
}

void lista_imprime(Lista* lista){
  Lista *p;
  for(p=lista; p!=NULL; p = p->prox){
    printf("Nome do aluno......: %s\n", p->aluno.nome);
    printf("Matricula..........: %d\n", p->aluno.matricula);
    printf("Curso..............: %s\n", p->aluno.curso);
    printf("Valor da parcela...: %f\n", p->aluno.valor_parcela);
    printf("\n");
  }

}

void lista_busca(Lista* lista, int matricula){
  Lista *p;
  for(p=lista; p!=NULL; p = p->prox){
    if(p->aluno.matricula == matricula){
        printf("Aluno encontrado!\nExibindo dados:\n=====================\n");
        printf("Nome do aluno......: %s\n", p->aluno.nome);
        printf("Matricula..........: %d\n", p->aluno.matricula);
        printf("Curso..............: %s\n", p->aluno.curso);
        printf("Valor da parcela...: %f\n", p->aluno.valor_parcela);
        printf("\n");
        return;
      }
  }
    printf("ALUNO NÃO ENCONTRADO\n=====================\n");
    return;    
}

Lista* lista_retira(Lista* lista, int matricula){
  Lista* ant = NULL; //ponbteiro para elemento anterior
  Lista* p = lista; //ponteiro para percorrer a lista

  //procurar o elemento na lista, guardando o anterior
  while(p!=NULL && p->aluno.matricula != matricula){
    ant = p;
    p = p->prox;
  }
  //verificar se achou o elemento
  if(p == NULL) return lista;  //não achou. Retorna a lista original
  if(ant == NULL){ //elemento é o primeiro
    lista = p->prox;    
  }
  else{
    //retira elemento no meio
    ant->prox = p->prox;
  }
  free(p);
  return lista;
}

//prototipos
Aluno le_aluno();
Lista* lista_cria();
Lista* lista_insere(Lista* lista, Aluno temp);
Lista* lista_retira(Lista* lista, int matricula);
void lista_busca(Lista* lista, int matricula);

int main() {
  Lista* banco_alunos;
  Aluno temp;
  int opcao, quant,i, matricula;
  banco_alunos = lista_cria();
  do {    
    printf("MENU: \n\t1 - Inserir\n\t2 - Buscar\n\t3 - Retirar.\n\t4 - Listar\n\t5 - SAIR\n=============\nDigite a opção: ");
    scanf(" %d", &opcao);
    switch(opcao){
      case 1:   //Inserir
      printf("Inserir Alunos\n=========================\n");
      printf("Quantos alunos você quer inserir?"); scanf(" %d", &quant);
      for(i=0;i<quant;i++){
        temp = le_aluno();
        banco_alunos = lista_insere(banco_alunos,  temp);
      }
      break;

      case 2: //Buscar
        printf("Buscar Alunos\n=========================\n");    
        printf("Digite a matricula do aluno que quer buscar?"); scanf(" %d", &matricula);
        lista_busca(banco_alunos,  matricula);        
      break;

      case 3: //Retirar
        printf("Retirar Alunos\n=========================\n");      
        printf("Digite a matricula do aluno que quer retirar?"); scanf(" %d", &matricula);
        lista_retira(banco_alunos, matricula);
      break;

      case 4: //Listar todos
        printf("Listar todos Alunos\n=========================\n");
        lista_imprime(banco_alunos);
        
      break;

      case 5:    
      break;

      default:
      printf("Digite uma opção válida!");
      exit(1);
      break;

    }
  }while(opcao!=5);
  return 0;
}

