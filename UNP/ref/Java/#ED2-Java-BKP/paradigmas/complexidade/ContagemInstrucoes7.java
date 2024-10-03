package paradigmas.complexidade;

public class ContagemInstrucoes7 {

    public static void main(String[] args) {
        // exemplo 6 - for
        // ============================================
        // inicializa��o do i -> 1 instru��o
        // compara��es com o n -> 1 + (n - 1) instru��es
        // incremento do i --> n - 1 instru��es
        // impress�o --> n - 1 instru��es
        // >>>>---- 4n - 1 instru��es no total ----<<<<
        // ============================================

        int a = 0;           // --> 1
        int n = 10;          // --> 1

        for (int i = 1; i <= n; i++) {  // --> 1 (inicializa��o) + 1 (compara��o inicial) + (n - 1) (compara��es) + (n - 1) (incrementos)
            a = a + 1;                  // --> (n - 1)
            System.out.println(i);       // --> (n - 1)
        }

        System.out.println("a = " + a);  // --> 1

        // 4n - 1 instru��es no total
    }
}
