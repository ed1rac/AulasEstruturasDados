package paradigmas.complexidade;

public class ContagemInstrucoes9 {

    public static void main(String[] args) {
        // exemplo 9 - if dentro de um for
        // ============================================
        // inicialização do i -> 1 instrução
        // comparações com o n -> 1 + n instruções
        // incremento do i --> n instruções
        // impressão --> n instruções
        // >>-- 3nˆ2 + 3n + 3 instruções no total --<<
        // ============================================

        int[] numeros = {1, 2, 3, 4, 5, 6, 7, 8}; // --> 1

        for (int i = 0; i < numeros.length; i++) { // --> 2 + numeros.length
            if (numeros[i] % 2 == 0) {             // O if conta dependendo da condição
                System.out.println(numeros[i]);    // --> 4 (executado para n/2, ou seja, os pares)
            }
        }

        // O if só vai executar (e contar) dependendo dos valores testados.
    }
}
