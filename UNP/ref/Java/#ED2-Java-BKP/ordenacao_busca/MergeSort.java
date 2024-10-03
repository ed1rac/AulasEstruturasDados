package ordenacao_busca;
import java.util.Random;

public class MergeSort
{
   private int[] data; // array de valores
   private static final Random generator = new Random();

   // cria um array de determinado tamanho e preenche com inteiros aleatórios
   public MergeSort( int size )
   {
      data = new int[ size ];

      //preenche o array com inteiros aleatórios no intervalo 10-99
      for ( int i = 0; i < size; i++ )
         data[ i ] = 10 + generator.nextInt( 90 );
   }

   // chama o método split recursivo para iniciar a classificação por mesclagem
   public void sort()
   {
      sortArray( 0, data.length - 1 ); //divide o array inteiro
   }

   // divide array, classifica subarrays e mescla subarrays em um array ordenado
   private void sortArray( int low, int high ) 
   {
      //teste o caso base; tamanho da matriz é igual a 1
      if ( ( high - low ) >= 1 )
      {
         int middle1 = ( low + high ) / 2;
         int middle2 = middle1 + 1;

         // Saída do passo de dividir
         System.out.println( "Divide:   " + subarray( low, high ) );
         System.out.println( "          " + subarray( low, middle1 ) );
         System.out.println( "          " + subarray( middle2, high ) );
         System.out.println();

         //divide o array ao meio; classificar cada metade (chamadas recursivas)
         sortArray( low, middle1 ); // primeira metade
         sortArray( middle2, high ); // segunda metade

         // mescla dois arrays classificados após o retorno das chamadas divididas
         merge ( low, middle1, middle2, high );
      }
   }

   // mescla dois subarrays classificados em um subarray classificado
   private void merge( int left, int middle1, int middle2, int right ) 
   {
      int leftIndex = left;
      int rightIndex = middle2;
      int combinedIndex = left;
      int[] combined = new int[ data.length ];

      // gera dois subarrays antes de mesclar
      System.out.println( "Combina:   " + subarray( left, middle1 ) );
      System.out.println( "          " + subarray( middle2, right ) );

      // mescla arrays até chegar ao final de qualquer um
      while ( leftIndex <= middle1 && rightIndex <= right )
      {
         //coloca o menor dos dois elementos atuais no resultado
         // e passa para o próximo espaço nos arrays
         if ( data[ leftIndex ] <= data[ rightIndex ] )
            combined[ combinedIndex++ ] = data[ leftIndex++ ]; 
         else 
            combined[ combinedIndex++ ] = data[ rightIndex++ ];
      }

      // se o array esquerdo estiver vazio
      if (leftIndex == middle2)
         // copia o restante do array direito
         while (rightIndex <= right)
            combined[combinedIndex++] = data[rightIndex++];
      else // array direito está vazio
         // copia o restante do array esquerdo
         while (leftIndex <= middle1)
            combined[combinedIndex++] = data[leftIndex++];

      // copia os valores de volta para o array original
      for (int i = left; i <= right; i++)
         data[i] = combined[i];

      // exibe o array mesclado
      System.out.println("         " + subarray(left, right));
      System.out.println();
   } // fim do método merge

   // método para exibir determinados valores no array
   public String subarray(int baixo, int alto)
   {
      StringBuilder temporario = new StringBuilder();

      // exibe espaços para alinhamento
      for (int i = 0; i < baixo; i++)
         temporario.append("   ");

      // exibe os elementos restantes no array
      for (int i = baixo; i <= alto; i++)
         temporario.append(" " + data[i]);

      return temporario.toString();
   } // fim do método subarray

   // método para exibir valores no array
   public String toString()
   {
      return subarray(0, data.length - 1);
   } // fim do método toString

}