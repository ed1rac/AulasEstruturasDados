package ordenacao_busca;

public class MergeSortTest
{
   public static void main( String[] args )
   {
      // cria um objeto para executar a classifica��o por mesclagem
      MergeSort sortArray = new MergeSort( 10 );

      // imprime array n�o classificado
      System.out.println( "N�o-ordenado:" + sortArray + "\n" );

      sortArray.sort(); // classifica

      // imprime
      System.out.println( "Ordenado:  " + sortArray );
   }
}

