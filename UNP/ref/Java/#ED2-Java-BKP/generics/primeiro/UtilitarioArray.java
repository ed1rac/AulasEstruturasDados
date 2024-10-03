package generics.primeiro;

/**
 * Aqui, <T> define um método genérico.
 * Note que o tipo T é inferido pelo compilador com base nos argumentos
 * passados.
 */

public class UtilitarioArray {

    public static <T> void trocar(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String[] args) {
        String[] nomes = {"Alice", "Bob", "Charlie"};
        UtilitarioArray.trocar(nomes, 0, 2);
        for (String nome : nomes) {
            System.out.println(nome);
        }

        Integer[] numeros = {1, 2, 3};
        UtilitarioArray.trocar(numeros, 1, 2);
        for (Integer numero : numeros) {
            System.out.println(numero);
        }
    }
}
