package recursividade;

public class SomaArray {

    public static int soma(int[] array, int n) {
        if (n <= 0) {
            return 0; // Caso base: soma de zero elementos é 0
        } else {
            return soma(array, n - 1) + array[n - 1]; // Caso recursivo
        }
    }

    public static void main(String[] args) {
        int[] array = {0, 1,2, 3, 4, 5,6,7,8,9,10};
        System.out.println(array.length);
        System.out.println("Soma dos elementos do array: " + soma(array, array.length));
    }
}