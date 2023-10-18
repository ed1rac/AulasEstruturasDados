package grafos;

import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.graph.Graph;
import edu.uci.ics.jung.graph.SparseGraph;
import edu.uci.ics.jung.visualization.VisualizationImageServer;

import javax.swing.*;
import java.awt.*;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;

public class VisualizeGraph {
    public static void main(String[] args) {
        // Crie um grafo com JUNG
        Graph<Integer, String> graph = new SparseGraph<>();
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addEdge("Edge 1", 1, 2);

        // Visualize o grafo com JUNG (apenas para fins de visualização)
        VisualizationImageServer<Integer, String> vs =
                new VisualizationImageServer<>(new CircleLayout<>(graph), new Dimension(300, 200));

        // Defina um transformador personalizado para exibir rótulos de vértices
        vs.getRenderContext().setVertexLabelTransformer(vertex -> vertex.toString());

        // Defina um transformador personalizado para ajustar o tamanho dos rótulos
        vs.getRenderContext().setVertexShapeTransformer(vertex -> {
            Rectangle2D shape = new Rectangle2D.Double(-20, -10, 40, 20); // Tamanho personalizado
            return AffineTransform.getScaleInstance(1, 1).createTransformedShape(shape);
        });

        // Crie um JFrame para exibir o grafo visualizado
        JFrame frame = new JFrame("Visualização de Grafo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(vs);
        frame.pack();
        frame.setVisible(true);
    }
}
