package ordenacao_busca;

public class BubbleSort {
    public static void main(String[] args) {
        int[] array_desordenado1 = {9,8,7,6,5,4,3,2,1};
        int[] array_desordenado2 = {1,5,9,7,8,8,10,20,2,-1};
        
        int[] array_ordenado = bubblesort(array_desordenado1);
        int[] array_ordenado2 = bubblesort(array_desordenado2);

        System.out.println("Exibindo o array 1 ordenado: ");
        for (int i: array_ordenado) {
            System.out.print(i + " ");
        }

        System.out.println("\n\nExibindo o array 2 ordenado: ");
        for (int i: array_ordenado2) {
            System.out.print(i + " ");
        }
    }

    private static int[] bubblesort(int[] lista) {
        int tamanho = lista.length;
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho-1; j++) {
                if(lista[j]>lista[j+1]){
                    troca(lista, j, j+1);
                }

            }

        }
        return lista;
    }

    private static void troca(int[] lista, int i, int j) {
        int aux = lista[i];
        lista[i] = lista[j];
        lista[j] = aux;
    }
}
