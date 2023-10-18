package grafos;

import java.util.ArrayList;
import java.util.List;

public class GrafoListaAdjacencia {
    private int numVertices;
    private List<List<Integer>> listaAdjacencia;

    public GrafoListaAdjacencia(int numVertices) {
        this.numVertices = numVertices;
        listaAdjacencia = new ArrayList<>(numVertices);
        for (int i = 0; i < numVertices; i++) {
            listaAdjacencia.add(new ArrayList<>());
        }
    }

    public void adicionarAresta(int vertice1, int vertice2) {
        listaAdjacencia.get(vertice1).add(vertice2);
        listaAdjacencia.get(vertice2).add(vertice1);
    }

    public void mostrarGrafo() {
        for (int i = 0; i < numVertices; i++) {
            System.out.print("Vértice " + i + ": ");
            for (Integer vizinho : listaAdjacencia.get(i)) {
                System.out.print(vizinho + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int numVertices = 4;
        GrafoListaAdjacencia grafo = new GrafoListaAdjacencia(numVertices);

        grafo.adicionarAresta(0, 1);
        grafo.adicionarAresta(0, 2);
        grafo.adicionarAresta(1, 2);
        grafo.adicionarAresta(2, 3);

        grafo.mostrarGrafo();
    }
}
