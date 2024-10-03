package ordenacao_busca;

public class SelectionSort {

    public static void main(String[] args) {
        int[] array_desordenado1 = {9,8,7,6,5,4,3,2,1};
        int[] array_desordenado2 = {1,5,9,7,8,8,10,20,2,-1};

        int[] array_ordenado = selectionsort(array_desordenado1);
        int[] array_ordenado2 = selectionsort(array_desordenado2);

        System.out.println("Exibindo o array 1 ordenado: ");
        for (int i: array_ordenado) {
            System.out.print(i + " ");
        }

        System.out.println("\n\nExibindo o array 2 ordenado: ");
        for (int i: array_ordenado2) {
            System.out.print(i + " ");
        }
    }

    private static int[] selectionsort(int[] vetor) {
        int n = vetor.length;
        for (int i = 0; i < n; i++) {
            int menor = i;
            for (int j = i+1; j < n; j++) {
                if(vetor[j]<vetor[menor])
                    menor=j;
            }
            //menor encontrado, basta trocar
            troca(vetor, i, menor);
        }
        return vetor;
    }

    private static void troca(int[] lista, int i, int j) {
        int aux = lista[i];
        lista[i] = lista[j];
        lista[j] = aux;
    }
}
