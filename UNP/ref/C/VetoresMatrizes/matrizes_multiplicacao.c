#include <stdio.h>
#include <stdlib.h>
/*  Função : multiplicacao entre duas matrizes
 *  utilizando alocacao dinaminca
 *  Autor : Edkallenn  - Data : 10/04/2012
 *  Obs: O Numero de linhas e coluna sao fornecidos pela entrada padrao,
 *       alem dos campos das matrizes.
 */

/* aloca memoria para as matrizes  */
float **Alocar_matriz_real(int m, int n)
{
   float **v;  /* ponteiro para a matriz */
   int   i;    /* variavel auxiliar      */

   if (m < 1 || n < 1) { /* verifica parametros recebidos */
      printf ("** Erro: Parametro invalido **\n");
      return (NULL);
   }

   /* aloca as linhas da matriz */
   v = calloc (m, sizeof(float *));   /* Um vetor de m ponteiros para float */
   if (v == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return (NULL);
   }

   /* aloca as colunas da matriz */
   for ( i = 0; i < m; i++ ) {
      v[i] =  calloc (n, sizeof(float));   /* m vetores de n floats */
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
      }
   }

   return (v); /* retorna o ponteiro para a matriz */
}

/* Libera memoria ocupada pelas matrizes */
float **Liberar_matriz_real (int m, int n, float **v)
{
   int  i;  /* variavel auxiliar */

   if (v == NULL)
         return (NULL);

   if (m < 1 || n < 1) {  /* verifica parametros recebidos */
      printf ("** Erro: Parametro invalido **\n");
      return (v);
   }

   for (i = 0; i < m; i++)
         free (v[i]); /* libera as linhas da matriz */

   free (v);      /* libera a matriz (vetor de ponteiros) */

   return (NULL); /* retorna um ponteiro nulo */
}

/* Funcao para receber os dados que preencherao as matrizes */
float **ler_mat(int m, int n, float **v)
{
   int i, j;

   printf("Preencha a Matrix: \n");
   for (i = 0 ; i < m; i++ )
      for (j = 0; j < n; j++) {
         printf("Posicao a%d%d \n", i+1, j+1);
         scanf("%f", &v[i][j]);
      }
   printf("\n");

   return(v);
}

/* Essa funcao faz a multiplicacao entre as matrize.
 * Retorna um matriz com resultado da multplicao
 * */
float **mult(int ma, int mb , int na, int nb, float **a, float **b, float **mr)
{
   int i, j , v;

   for (i = 0 ; i < ma; i++ )
      for (j = 0; j < nb; j++)
         for (v = 0; v < na; v++)
            mr[i][j] = mr[i][j] + a[i][v] * b[v][j];

   return(mr);
}

/* funcao pra imprimir na tela as matrizes  */
void imprime(int ma, int mb , int na, int nb , float **a, float **b, float **mr)
{
   int i, j;

   /* Impressao das Matrizes */
   printf("MATRIX A:\n");
   for (i = 0; i < ma; i++) {
      for ( j = 0; j < na; j++)
         printf("%.f ", a[i][j]);
      printf("\n");
   }
   printf("MATRIX B:\n");
   for (i = 0; i < mb; i++) {
      for ( j = 0; j < nb; j++)
         printf("%.f ", b[i][j]);
   printf("\n");
   }

   printf("MATRIX C:\n");
   for (i = 0; i < ma ; i++) {
      for ( j = 0; j < nb ; j++)
         printf("%4.f", mr[i][j]);
      printf("\n");
   }
}

/* funcao pra validar se e possivel fazer a multiplicao entre
 * as matrizes dadas
 */
int invalido(int na, int mb)
{
   if (na != mb)
      return -1;

   return 0;
}

/*
 * Essa e a funcao principal
 */
int main(int argc, char **argv)
{
   float **A;  /* matriz a ser alocada */
   float **B;  /* matriz a ser alocada */
   float **MR;  /* matriz a ser alocada */
   int la, lb, ca, cb;   /* numero de linhas e colunas da matriz */

   printf("Informe o Numero de Linhas  A : ");
   scanf("%d", &la);
   printf("Informe o Numero de Colunas A : ");
   scanf("%d", &ca);
   printf("Informe o Numero de Linhas  B : ");
   scanf("%d", &lb);
   printf("Informe o Numero de Colunas C : ");
   scanf("%d", &cb);

   if(invalido(ca, lb)) {
      fprintf(stderr, "Erro:\n");
      fprintf(stderr, "Numero de colunas da Matriz A deve ser igual ao Numero de Linhas da Matrix B\n");
      exit(EXIT_FAILURE);
   }

   /* Chama a funcao para alocar a matriz */
   A = Alocar_matriz_real (la, ca);
   B = Alocar_matriz_real (lb, cb);
   MR = Alocar_matriz_real (la, cb);

   /* Chama funcao pra preencher as matrizes  */
   A = ler_mat(la, ca, A);
   B = ler_mat(lb, cb, B);

   /* chama a funcao pra fazer muultiplicacao das matrizes */
   MR = mult(la, lb, ca, cb, A, B, MR);

   /* chama a funcao pra mostrar na tela o resultado da multiplicacao */
   imprime(la, lb , ca, cb, A, B, MR);

   /* desaloca a memoria, nao mais nescessaria */
   A = Liberar_matriz_real (la, ca, A);
   B = Liberar_matriz_real (lb, cb, B);
   MR = Liberar_matriz_real (la, cb, MR);

   return 0;
} /* fim do programa */
