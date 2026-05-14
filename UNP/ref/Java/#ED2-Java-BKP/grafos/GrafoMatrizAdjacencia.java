package grafos;

public class GrafoMatrizAdjacencia {
    private int numVertices;
    private int[][] matrizAdjacencia;

    public GrafoMatrizAdjacencia(int numVertices) {
        this.numVertices = numVertices;
        this.matrizAdjacencia = new int[numVertices][numVertices];
    }

    public void adicionarAresta(int vertice1, int vertice2) {
        matrizAdjacencia[vertice1][vertice2] = 1;
        matrizAdjacencia[vertice2][vertice1] = 1;
    }

    public void mostrarGrafo() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                System.out.print(matrizAdjacencia[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void mostrarGrafoComLegendas() {
        // 1. Imprime o cabeçalho das colunas (Vértices)
        System.out.print("  "); // Espaço para alinhar com a coluna de legendas da linha
        for (int j = 0; j < numVertices; j++) {
            System.out.print("V" + j + " ");
        }
        System.out.println();

        // 2. Imprime o Separador
        System.out.print("  ");
        for (int j = 0; j < numVertices; j++) {
            System.out.print("--");
        }
        System.out.println();

        // 3. Imprime cada linha (Vértice de origem)
        for (int i = 0; i < numVertices; i++) {
            // Imprime a legenda da linha (Vértice de origem)
            System.out.print("V" + i + "|");

            // Imprime os valores da matriz
            for (int j = 0; j < numVertices; j++) {
                System.out.print(matrizAdjacencia[i][j] + "  "); // Adiciona um espaço extra para alinhamento
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int numVertices = 4;
        GrafoMatrizAdjacencia grafo = new GrafoMatrizAdjacencia(numVertices);

        grafo.adicionarAresta(0, 1);
        grafo.adicionarAresta(0, 2);
        grafo.adicionarAresta(1, 2);
        grafo.adicionarAresta(2, 3);

        grafo.mostrarGrafo();
        System.out.println("Mostrar grafo com legendas");
        grafo.mostrarGrafoComLegendas();
    }
}
