package arvores;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.stage.Stage;


public class ExibeArvoreFX extends Application {

    public static class TreeNode {
        char data;
        TreeNode left;
        TreeNode right;

        public TreeNode(char data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    private Pane pane = new Pane();
    private double verticalGap = 60;
    private double horizontalGap = 40;

    @Override
    public void start(Stage primaryStage) {
        TreeNode root = new TreeNode('A');
        root.left = new TreeNode('B');
        root.right = new TreeNode('C');
        root.left.left = new TreeNode('D');
        root.left.right = new TreeNode('E');
        root.right.right = new TreeNode('F');
        root.left.left.left = new TreeNode('G');

        visualizeTree(root, 400, 40, 300);

        Scene scene = new Scene(pane, 800, 600);
        primaryStage.setTitle("JavaFX Tree Visualization");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void visualizeTree(TreeNode root, double x, double y, double hGap) {
        if (root == null) {
            return;
        }

        pane.getChildren().add(new Label(String.valueOf(root.data)));
        pane.getChildren().get(pane.getChildren().size() - 1).setLayoutX(x);
        pane.getChildren().get(pane.getChildren().size() - 1).setLayoutY(y);

        if (root.left != null) {
            pane.getChildren().add(new Line(x - hGap, y + verticalGap, x, y));
            visualizeTree(root.left, x - hGap, y + verticalGap, hGap / 2);
        }

        if (root.right != null) {
            pane.getChildren().add(new Line(x + hGap, y + verticalGap, x, y));
            visualizeTree(root.right, x + hGap, y + verticalGap, hGap / 2);
        }
    }

    public static void main(String[] args) {
        launch(args);
        //start();
    }
}

