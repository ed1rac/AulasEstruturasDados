package paradigmas.complexidade;

public class Soma {
    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        int soma = 0;
        for (int i = 1; i < 1000000; i++) {
            soma+=i;
        }
        long fim = System.currentTimeMillis();
        System.out.println("Tempo de execução: " + (fim - inicio) + " ms");
    }
}
