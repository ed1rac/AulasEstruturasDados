package paradigmas.complexidade;

public class ContagemInstrucoes5 {

    public static void main(String[] args) {
        // exemplo 5 - for loop
        int max = 10; // --> 1

        for (int i = 0; i <= max; i++) { // --> 1 + 1 (inicializa��o e compara��o inicial) + 10 (compara��es) + 10 (incrementos)
            System.out.println(i);       // --> 10 (impress�es)
        }

        // 33 instru��es no total
    }
}
