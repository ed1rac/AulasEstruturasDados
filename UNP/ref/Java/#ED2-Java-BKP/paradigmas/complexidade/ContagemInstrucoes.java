package paradigmas.complexidade;

public class ContagemInstrucoes {

    // Simula a contagem de instruções de um algoritmo simples (somar de 1 até n)
    public static int contarInstrucoes(int n) {
        int contador = 0;
        for (int i = 1; i <= n; i++) {
            contador++;
        }
        return contador;
    }

    public static void main(String[] args) {
        int n = 1000000;

        // Medindo o tempo de execução
        long inicio = System.currentTimeMillis();
        int instrucoes = contarInstrucoes(n);
        long fim = System.currentTimeMillis();

        // Exibindo o número de instruções e o tempo de execução
        System.out.println("Instruções: " + instrucoes);
        System.out.println("Tempo de execução: " + (fim - inicio) + " milissegundos");
    }
}
