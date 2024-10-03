package paradigmas.complexidade;

public class ContagemInstrucoes6 {

    public static void main(String[] args) {
        // exemplo 6 - for
        // ============================================
        // inicialização do i -> 1 instrução
        // comparações com o n -> 1 + n instruções
        // incremento do i --> n instruções
        // impressão --> n instruções
        // >>>>---- 3n + 3 instruções no total ----<<<<
        // ============================================

        int n = 10; // --> 1

        for (int i = 0; i <= n; i++) { // --> 1 (inicialização) + 1 (comparação inicial) + n (comparações) + n (incrementos)
            System.out.println(i);     // --> n (impressões)
        }

        // 3n + 3 instruções no total
    }
}
