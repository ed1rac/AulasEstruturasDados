package ordenacao_busca;

public class QuickSort {

    // M�todo de ordena��o Quicksort
    public static void quicksort(int[] array, int inicio, int fim) {
        if (inicio < fim) {
            // Particiona o array e obt�m o �ndice do pivo
            int indicePivo = particionar(array, inicio, fim);

            // Recursivamente ordena as sub-listas � esquerda e � direita do pivo
            quicksort(array, inicio, indicePivo - 1);
            quicksort(array, indicePivo + 1, fim);
        }
    }

    // M�todo auxiliar para particionar o array
    private static int particionar(int[] array, int inicio, int fim) {
        int pivo = array[fim];
        int i = inicio - 1;

        for (int j = inicio; j < fim; j++) {
            if (array[j] < pivo) {
                i++;
                trocar(array, i, j);
            }
        }

        trocar(array, i + 1, fim);
        return i + 1;
    }

    // M�todo auxiliar para trocar elementos no array
    private static void trocar(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // M�todo main para testar o Quicksort
    public static void main(String[] args) {
        int[] array = {12, 4, 5, 6, 7, 3, 1, 15};

        System.out.println("Array original:");
        exibirArray(array);

        // Chama o m�todo de ordena��o Quicksort
        quicksort(array, 0, array.length - 1);

        System.out.println("\nArray ordenado:");
        exibirArray(array);
    }

    // M�todo auxiliar para exibir o conte�do do array
    private static void exibirArray(int[] array) {
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
