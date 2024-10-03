package paradigmas.complexidade;

public class ContagemInstrucoes {

    // Simula a contagem de instru��es de um algoritmo simples (somar de 1 at� n)
    public static int contarInstrucoes(int n) {
        int contador = 0;
        for (int i = 1; i <= n; i++) {
            contador++;
        }
        return contador;
    }

    public static void main(String[] args) {
        int n = 1000000;

        // Medindo o tempo de execu��o
        long inicio = System.currentTimeMillis();
        int instrucoes = contarInstrucoes(n);
        long fim = System.currentTimeMillis();

        // Exibindo o n�mero de instru��es e o tempo de execu��o
        System.out.println("Instru��es: " + instrucoes);
        System.out.println("Tempo de execu��o: " + (fim - inicio) + " milissegundos");
    }
}
