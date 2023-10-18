package recursividade;

public class SomaQuadrados{


        public static int somaQuadrados(int n) {

// Caso base: quando n chega a 1, o quadrado é 1.

            if (n == 1) {

                return 1;

            }


// Caso geral: recursivamente, soma o quadrado de n com a chamada de somaQuadrados para n-1.

            return n * n + somaQuadrados(n - 1);

        }

        public static void main(String[] args) {

            int resultado = somaQuadrados(5); // Calcula a soma dos quadrados dos primeiros 5 inteiros positivos.

            System.out.println("Resultado: " + resultado); // Isso imprimirá 55 (5^2 + 4^2 + 3^2 + 2^2 + 1^2).

        }

}
