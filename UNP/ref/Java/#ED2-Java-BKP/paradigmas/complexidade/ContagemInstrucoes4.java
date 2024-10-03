package paradigmas.complexidade;

public class ContagemInstrucoes4 {
    public static void main(String[] args) {
        // exemplo 3 - while
        int max = 10;        // --> 1
        int i = 0;           // --> 1

        while (i < max) {    // --> 1 + 10 (condição verificada 11 vezes no total)
            System.out.println(i);  // --> 10 (imprime valores de 0 a 9)
            i += 1;                // --> 10 (incrementos)
        }

        // 33 instruções no total
    }
}
