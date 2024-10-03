package paradigmas.complexidade;

public class ContagemInstrucoes7 {

    public static void main(String[] args) {
        // exemplo 6 - for
        // ============================================
        // inicialização do i -> 1 instrução
        // comparações com o n -> 1 + (n - 1) instruções
        // incremento do i --> n - 1 instruções
        // impressão --> n - 1 instruções
        // >>>>---- 4n - 1 instruções no total ----<<<<
        // ============================================

        int a = 0;           // --> 1
        int n = 10;          // --> 1

        for (int i = 1; i <= n; i++) {  // --> 1 (inicialização) + 1 (comparação inicial) + (n - 1) (comparações) + (n - 1) (incrementos)
            a = a + 1;                  // --> (n - 1)
            System.out.println(i);       // --> (n - 1)
        }

        System.out.println("a = " + a);  // --> 1

        // 4n - 1 instruções no total
    }
}
