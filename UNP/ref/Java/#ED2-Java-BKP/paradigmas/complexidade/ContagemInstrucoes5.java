package paradigmas.complexidade;

public class ContagemInstrucoes5 {

    public static void main(String[] args) {
        // exemplo 5 - for loop
        int max = 10; // --> 1

        for (int i = 0; i <= max; i++) { // --> 1 + 1 (inicialização e comparação inicial) + 10 (comparações) + 10 (incrementos)
            System.out.println(i);       // --> 10 (impressões)
        }

        // 33 instruções no total
    }
}
