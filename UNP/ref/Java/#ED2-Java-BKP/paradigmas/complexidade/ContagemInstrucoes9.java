package paradigmas.complexidade;

public class ContagemInstrucoes9 {

    public static void main(String[] args) {
        // exemplo 9 - if dentro de um for
        // ============================================
        // inicializa��o do i -> 1 instru��o
        // compara��es com o n -> 1 + n instru��es
        // incremento do i --> n instru��es
        // impress�o --> n instru��es
        // >>-- 3n�2 + 3n + 3 instru��es no total --<<
        // ============================================

        int[] numeros = {1, 2, 3, 4, 5, 6, 7, 8}; // --> 1

        for (int i = 0; i < numeros.length; i++) { // --> 2 + numeros.length
            if (numeros[i] % 2 == 0) {             // O if conta dependendo da condi��o
                System.out.println(numeros[i]);    // --> 4 (executado para n/2, ou seja, os pares)
            }
        }

        // O if s� vai executar (e contar) dependendo dos valores testados.
    }
}
