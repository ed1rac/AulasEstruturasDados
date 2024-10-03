package grafos;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Map;
import java.util.List;

/**
 * @apiNote  Grafo representado como lista de adjacências
 * - Nesta representação, você usa uma lista de adjacência para cada vértice no grafo.
 * - Cada vértice possui uma lista de outros vértices aos quais ele está diretamente conectado por uma aresta.
 * - Essa representação é eficiente em termos de espaço para grafos esparsos e é usada com frequência em algoritmos de grafos, como busca em largura e busca em profundidade.
 * @author: Edkallenn
 *
 */

class Grafo {
    private Map<Object, List<String>> adjacencia;

    public Grafo() {
        adjacencia = new HashMap<>();
    }

    public void adicionarVertice(String vertice) {
        if (!adjacencia.containsKey(vertice)) {
            adjacencia.put(vertice, new ArrayList<>());
        }
    }

    public void adicionarAresta(String vertice1, String vertice2) {
        adicionarVertice(vertice1);
        adicionarVertice(vertice2);

        adjacencia.get(vertice1).add(vertice2);
        adjacencia.get(vertice2).add(vertice1);
    }

    public void mostrarGrafo() {
        for (Object vertice : adjacencia.keySet()) {
            List<String> vizinhos = adjacencia.get(vertice);
            System.out.print(vertice + ": ");
            for (String vizinho : vizinhos) {
                System.out.print(vizinho + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Grafo grafo = new Grafo();
        grafo.adicionarAresta("A", "B");
        grafo.adicionarAresta("A", "C");
        grafo.adicionarAresta("B", "C");
        grafo.adicionarAresta("C", "D");

        grafo.mostrarGrafo();
    }
}
