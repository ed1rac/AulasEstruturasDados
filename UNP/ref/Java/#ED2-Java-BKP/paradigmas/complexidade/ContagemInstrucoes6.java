package paradigmas.complexidade;

public class ContagemInstrucoes6 {

    public static void main(String[] args) {
        // exemplo 6 - for
        // ============================================
        // inicializa��o do i -> 1 instru��o
        // compara��es com o n -> 1 + n instru��es
        // incremento do i --> n instru��es
        // impress�o --> n instru��es
        // >>>>---- 3n + 3 instru��es no total ----<<<<
        // ============================================

        int n = 10; // --> 1

        for (int i = 0; i <= n; i++) { // --> 1 (inicializa��o) + 1 (compara��o inicial) + n (compara��es) + n (incrementos)
            System.out.println(i);     // --> n (impress�es)
        }

        // 3n + 3 instru��es no total
    }
}
