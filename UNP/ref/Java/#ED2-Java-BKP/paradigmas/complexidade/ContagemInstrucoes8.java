package paradigmas.complexidade;

public class ContagemInstrucoes8 {

    public static void main(String[] args) {
        // exemplo 8 - for dentro de outro for
        // ============================================
        // inicialização do i -> 1 instrução
        // comparações com o n -> 1 + n instruções
        // incremento do i --> n instruções
        // impressão --> n instruções
        // >>-- 3nˆ2 + 3n + 3 instruções no total --<<
        // ============================================

        int n = 5;          // --> 1

        for (int i = 0; i < n; i++) {       // --> 2 (inicialização e primeira comparação) + n * (
            for (int j = 0; j < n; j++) {   //     2 (inicialização e primeira comparação) + n + n
                System.out.println(i);      // --> n
            }
        }

        // Fórmula de contagem:
        // 1 + 2 + n * (2 + n + n + n) + n =
        // 3 + n * (2 + 3n) + n =
        // 3nˆ2 + 3n + 3 instruções no total
    }
}
