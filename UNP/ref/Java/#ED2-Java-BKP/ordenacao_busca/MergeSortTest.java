package ordenacao_busca;

public class MergeSortTest
{
   public static void main( String[] args )
   {
      // cria um objeto para executar a classificação por mesclagem
      MergeSort sortArray = new MergeSort( 10 );

      // imprime array não classificado
      System.out.println( "Não-ordenado:" + sortArray + "\n" );

      sortArray.sort(); // classifica

      // imprime
      System.out.println( "Ordenado:  " + sortArray );
   }
}

