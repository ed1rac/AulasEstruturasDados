package paradigmas.complexidade;

import java.util.Arrays;
import java.util.Random;

public class ComparacaoOrdenacao {

    // Gera uma lista aleatória de inteiros
    public static int[] geraLista(int tamanho) {
        Random random = new Random();
        int[] lista = new int[tamanho];
        for (int i = 0; i < tamanho; i++) {
            lista[i] = random.nextInt(tamanho);
        }
        return lista;
    }

    // Função de comparação de ordenações
    public static void comparaOrdenacao(int[] lista, int tamanho) {
        int[] copiaLista1 = Arrays.copyOf(lista, tamanho);
        int[] copiaLista2 = Arrays.copyOf(lista, tamanho);

        long inicio = System.currentTimeMillis();
        bubbleSort(copiaLista1);
        long tempoBubbleSort = System.currentTimeMillis() - inicio;

        inicio = System.currentTimeMillis();
        quickSort(copiaLista2, 0, tamanho - 1);
        long tempoQuickSort = System.currentTimeMillis() - inicio;

        System.out.println("Bubble Sort demorou: " + tempoBubbleSort + " milissegundos");
        System.out.println("Quick Sort demorou: " + tempoQuickSort + " milissegundos");
    }

    // Função Bubble Sort
    public static void bubbleSort(int[] lista) {
        int n = lista.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (lista[j] > lista[j + 1]) {
                    // Troca os elementos
                    int temp = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = temp;
                }
            }
        }
    }

    // Função Quick Sort
    public static void quickSort(int[] lista, int inicio, int fim) {
        if (inicio < fim) {
            int indicePivo = particionar(lista, inicio, fim);
            quickSort(lista, inicio, indicePivo - 1);
            quickSort(lista, indicePivo + 1, fim);
        }
    }

    // Particiona a lista no Quick Sort
    public static int particionar(int[] lista, int inicio, int fim) {
        int pivo = lista[fim];
        int i = (inicio - 1);
        for (int j = inicio; j < fim; j++) {
            if (lista[j] <= pivo) {
                i++;
                int temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
        int temp = lista[i + 1];
        lista[i + 1] = lista[fim];
        lista[fim] = temp;
        return i + 1;
    }

    public static void main(String[] args) {
        int tamanhoLista = 100000;
        int[] lista = geraLista(tamanhoLista);
        comparaOrdenacao(lista, tamanhoLista);
    }
}
