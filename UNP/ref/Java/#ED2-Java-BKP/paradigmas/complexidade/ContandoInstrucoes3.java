package paradigmas.complexidade;

public class ContandoInstrucoes3 {
    public static void main(String[] args) {
        // exemplo 3 - while
        int max = 0;          // --> 1
        int i = 0;            // --> 1

        while (i < max) {     // --> condi��o, = 1
            i += 1;           // --> n�o conta. condi��o nunca ser� verdadeira.
        }

        // 3 instru��es no total
    }
}
