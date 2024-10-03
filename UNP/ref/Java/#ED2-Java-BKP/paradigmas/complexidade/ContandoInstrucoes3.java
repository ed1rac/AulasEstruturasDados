package paradigmas.complexidade;

public class ContandoInstrucoes3 {
    public static void main(String[] args) {
        // exemplo 3 - while
        int max = 0;          // --> 1
        int i = 0;            // --> 1

        while (i < max) {     // --> condição, = 1
            i += 1;           // --> não conta. condição nunca será verdadeira.
        }

        // 3 instruções no total
    }
}
