package paradigmas.complexidade;

public class ContagemInstrucoes8 {

    public static void main(String[] args) {
        // exemplo 8 - for dentro de outro for
        // ============================================
        // inicializa��o do i -> 1 instru��o
        // compara��es com o n -> 1 + n instru��es
        // incremento do i --> n instru��es
        // impress�o --> n instru��es
        // >>-- 3n�2 + 3n + 3 instru��es no total --<<
        // ============================================

        int n = 5;          // --> 1

        for (int i = 0; i < n; i++) {       // --> 2 (inicializa��o e primeira compara��o) + n * (
            for (int j = 0; j < n; j++) {   //     2 (inicializa��o e primeira compara��o) + n + n
                System.out.println(i);      // --> n
            }
        }

        // F�rmula de contagem:
        // 1 + 2 + n * (2 + n + n + n) + n =
        // 3 + n * (2 + 3n) + n =
        // 3n�2 + 3n + 3 instru��es no total
    }
}
