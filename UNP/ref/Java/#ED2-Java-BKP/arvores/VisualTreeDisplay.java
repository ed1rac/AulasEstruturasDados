package arvores;

import javax.swing.*;
import java.awt.*;

class TreeNode {
  char data;
  TreeNode left;
  TreeNode right;

  public TreeNode(char data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

public class VisualTreeDisplay extends JPanel {
  private TreeNode root;

  public VisualTreeDisplay(TreeNode root) {
    this.root = root;
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    //drawTree(g, getWidth() / 2, 30, root, getWidth() / 4);
    drawTree(g, getWidth() / 2, 30, root, getWidth() / 8);
  }

  private void drawTree(Graphics g, int x, int y, TreeNode node, int xOffset) {
    if (node == null) {
      return;
    }

    int ovalWidth = 30; //aumentar ou diminuir essa variável, altera o tamanho dos ovais. Valor padrão é 30
    int ovalHeight = 30;
    int ovalTop = y - ovalHeight / 2; // Coordenada Y do topo do oval
    final int distAresta = 80;

    // Crie um objeto Font com o tamanho desejado
    Font font = new Font("Arial", Font.PLAIN, 14); // Substitua "Arial" pelo nome da fonte que você deseja e ajuste o tamanho (12)

    // Configure a fonte
    g.setFont(font);

    if (node.left != null) {
      int childX = x - xOffset;
      int childY = y + distAresta;

      g.drawLine(x, ovalTop + ovalHeight, childX, childY - ovalHeight / 2);
      drawTree(g, childX, childY, node.left, xOffset / 2);
    }

    if (node.right != null) {
      int childX = x + xOffset;
      int childY = y + distAresta;

      g.drawLine(x, ovalTop + ovalHeight, childX, childY - ovalHeight / 2);
      drawTree(g, childX, childY, node.right, xOffset / 2);
    }

    g.drawOval(x - ovalWidth / 2, ovalTop, ovalWidth, ovalHeight);
    g.drawString(String.valueOf(node.data), x - 5, ovalTop + ovalHeight / 2 + 5);
  }



  /* private void drawTree(Graphics g, int x, int y, TreeNode node, int xOffset) {
    if (node == null) {
      return;
    }

    g.drawOval(x - 15, y - 15, 30, 30);
    g.drawString(String.valueOf(node.data), x - 5, y + 5);

    if (node.left != null) {
      g.drawLine(x, y, x - xOffset, y + 50);
      drawTree(g, x - xOffset, y + 50, node.left, xOffset / 2);
    }

    if (node.right != null) {
      g.drawLine(x, y, x + xOffset, y + 50);
      drawTree(g, x + xOffset, y + 50, node.right, xOffset / 2);
    }
  }
*/
  public static void main(String[] args) {
    TreeNode root = new TreeNode('A');
    root.left = new TreeNode('B');
    root.right = new TreeNode('C');
    root.left.left = new TreeNode('D');
    root.left.right = new TreeNode('E');
    root.right.right = new TreeNode('F');
    root.left.left.left = new TreeNode('G');

    JFrame frame = new JFrame("Visualização da árvore");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(800, 600);
    frame.add(new VisualTreeDisplay(root));
    frame.setVisible(true);
  }
}
