# Árvores em C e em Java

## C

A programação de árvores em C pode ser realizada de várias maneiras, mas uma das abordagens mais comuns é a implementação de árvores binárias usando estruturas e ponteiros em C.

Aqui está um exemplo de implementação de uma árvore binária simples em C:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void print_tree(node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    node *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    print_tree(root);
    return 0;
}
```

Neste exemplo, a estrutura `node` representa um nó na árvore, com um valor inteiro `data` e dois ponteiros para os nós filho esquerdo e direito, respectivamente. A função `create_node()` é usada para criar um novo nó com um valor dado, e a função `insert_node()` é usada para inserir um novo nó na árvore.

A função `print_tree()` é usada para imprimir os valores da árvore em ordem crescente.

Essa é uma implementação simples, mas eficiente e flexível, que pode ser usada como ponto de partida para desenvolver árvores mais complexas em C.

## Java

A programação de árvores em Java pode ser realizada de várias maneiras, mas uma das abordagens mais comuns é a implementação de árvores binárias usando classes e objetos em Java.

Aqui está um exemplo de implementação de uma árvore binária simples em Java:

```java
public class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BinaryTree {
    Node root;

    public BinaryTree() {
        root = null;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    Node insertNode(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertNode(root.left, data);
        } else if (data > root.data) {
            root.right = insertNode(root.right, data);
        }

        return root;
    }

    void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.data + " ");
            inorderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);
        tree.inorderTraversal(tree.root);
    }
}
```

Neste exemplo, a classe `Node` representa um nó na árvore, com um valor inteiro `data` e dois objetos de nó filho esquerdo e direito. A classe `BinaryTree` é usada para criar a árvore binária, com um objeto `root` que representa a raiz da árvore.

O método `insert()` é usado para inserir um novo nó na árvore. O método `insertNode()` é uma função auxiliar recursiva que insere o nó na posição correta na árvore.

O método `inorderTraversal()` é usado para percorrer a árvore em ordem crescente e imprimir os valores da árvore.

O método `main()` é usado para criar uma instância da classe `BinaryTree` e inserir os valores na árvore. Em seguida, o método `inorderTraversal()` é chamado para imprimir os valores em ordem crescente.

Essa é uma implementação simples, mas eficiente e flexível, que pode ser usada como ponto de partida para desenvolver árvores mais complexas em Java.
