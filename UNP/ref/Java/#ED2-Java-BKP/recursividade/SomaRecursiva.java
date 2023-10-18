package recursividade;

public class SomaRecursiva {

    public static int soma(int n) {
        if (n <= 0) {
            return 0;
        } else {
            return n + soma(n - 1);
        }
    }

    public static void main(String[] args) {
        int resultado = soma(100);
        System.out.println("A soma dos números de 1 a 100 é: " + resultado);
    }
}
