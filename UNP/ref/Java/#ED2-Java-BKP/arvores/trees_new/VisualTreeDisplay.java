package arvores;

import javax.swing.*;
import java.awt.*;
import java.util.Queue;
import java.util.LinkedList;

class TreeNode {
  Object data;
  TreeNode left;
  TreeNode right;

  public TreeNode(Object data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }

  public void insert(Object newData) {
    if (compare(newData, this.data) < 0) {
      if (left == null) {
        left = new TreeNode(newData);
      } else {
        left.insert(newData);
      }
    } else if (compare(newData, this.data) > 0) {
      if (right == null) {
        right = new TreeNode(newData);
      } else {
        right.insert(newData);
      }
    }
  }

  private int compare(Object obj1, Object obj2) {
    if (obj1 instanceof Comparable && obj2 instanceof Comparable) {
      Comparable<Object> compObj1 = (Comparable<Object>) obj1;
      return compObj1.compareTo(obj2);
    }
    throw new IllegalArgumentException("Os objetos não são comparáveis.");
  }

  public void inOrder() {
    inOrder(this);
  }

  private void inOrder(TreeNode node) {
    if (node != null) {
      inOrder(node.left);
      System.out.print(node.data + " ");
      inOrder(node.right);
    }
  }

  public void preOrder() {
    preOrder(this);
  }

  private void preOrder(TreeNode node) {
    if (node != null) {
      System.out.print(node.data + " ");
      preOrder(node.left);
      preOrder(node.right);
    }
  }

  public void postOrder() {
    postOrder(this);
  }

  private void postOrder(TreeNode node) {
    if (node != null) {
      postOrder(node.left);
      postOrder(node.right);
      System.out.print(node.data + " ");
    }
  }

  public void levelOrder() {
    if (this.data == null) {
      return;
    }

    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(this);

    while (!queue.isEmpty()) {
      TreeNode node = queue.poll();
      System.out.print(node.data + " ");

      if (node.left != null) {
        queue.offer(node.left);
      }

      if (node.right != null) {
        queue.offer(node.right);
      }
    }
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

  private void drawTree(Graphics g, int x, int y, TreeNode treeNode, int xOffset) {
    if (treeNode == null) {
      return;
    }

    int ovalWidth = 30; //aumentar ou diminuir essa vari�vel, altera o tamanho dos ovais. Valor padr�o � 30
    int ovalHeight = 30;
    int ovalTop = y - ovalHeight / 2; // Coordenada Y do topo do oval
    final int distAresta = 80;

    // Crie um objeto Font com o tamanho desejado
    Font font = new Font("Arial", Font.PLAIN, 14); // Substitua "Arial" pelo nome da fonte que voc� deseja e ajuste o tamanho (12)

    // Configure a fonte
    g.setFont(font);

    if (treeNode.left != null) {
      int childX = x - xOffset;
      int childY = y + distAresta;

      g.drawLine(x, ovalTop + ovalHeight, childX, childY - ovalHeight / 2);
      drawTree(g, childX, childY, treeNode.left, xOffset / 2);
    }

    if (treeNode.right != null) {
      int childX = x + xOffset;
      int childY = y + distAresta;

      g.drawLine(x, ovalTop + ovalHeight, childX, childY - ovalHeight / 2);
      drawTree(g, childX, childY, treeNode.right, xOffset / 2);
    }

    g.drawOval(x - ovalWidth / 2, ovalTop, ovalWidth, ovalHeight);
    g.drawString(String.valueOf(treeNode.data), x - 5, ovalTop + ovalHeight / 2 + 5);
  }


  public static void main(String[] args) {
    TreeNode root = new TreeNode('D');
    /*root.left = new TreeNode('B');
    root.right = new TreeNode('C');
    root.left.left = new TreeNode('D');
    root.left.right = new TreeNode('E');
    root.right.right = new TreeNode('F');
    root.left.left.left = new TreeNode('G');*/
    root.insert('B');
    root.insert('C');
    root.insert('F');
    root.insert('H');
    root.insert('I');
    root.insert('E');
    root.insert('G');
    root.insert('A');

    System.out.println("In Order:");
    root.inOrder();
    System.out.println();

    System.out.println("Pre Order:");
    root.preOrder();
    System.out.println();

    System.out.println("Post Order :");
    root.postOrder();
    System.out.println();

    System.out.println("Level Order :");
    root.levelOrder();
    System.out.println();

    JFrame frame = new JFrame("Visualiza��o da �rvore");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(800, 600);
    frame.add(new VisualTreeDisplay(root));
    frame.setVisible(true);
  }
}
