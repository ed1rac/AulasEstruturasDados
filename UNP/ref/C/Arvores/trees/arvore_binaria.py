class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left_child = None
        self.right_child = None

    def insert_left(self, value):
        if not self.left_child:
            self.left_child = BinaryTree(value)
        else:
            new_node = BinaryTree(value)
            new_node.left_child = self.left_child
            self.left_child = new_node

    def insert_right(self, value):
        if not self.right_child:
            self.right_child = BinaryTree(value)
        else:
            new_node = BinaryTree(value)
            new_node.right_child = self.right_child
            self.right_child = new_node

    def pre_order(self):
        print(self.value)
        if self.left_child:
            self.left_child.pre_order()
        if self.right_child:
            self.right_child.pre_order()

    def in_order(self):
        if self.left_child:
            self.left_child.in_order()
        print(self.value)
        if self.right_child:
            self.right_child.in_order()

    def post_order(self):
        if self.left_child:
            self.left_child.post_order()
        if self.right_child:
            self.right_child.post_order()
        print(self.value)

    def print_tree(self,  level=0):
        if self is not BinaryTree:
            self.print_tree(self.right_child, level+1)
            print(' ' * 4 * level + '->', self.value)
            self.print_tree(self.left_child, level+1)


tree = BinaryTree(1)
tree.insert_left(2)
tree.insert_right(3)
tree.right_child.insert_left(4)
tree.right_child.insert_right(5)

tree.pre_order() # imprime 1 2 3 4 5
print('Imprimindo com o bynarytree')



tree_values = [6, 2, 8, 1, 4, 7, 9]
from binarytree import build
root = build(tree_values)
print(root)


print('Imprimindo com o graphviz')
import graphviz

def print_tree(root):
    def add_nodes_edges(dot, node):
        if node.left:
            dot.node(str(node.left.data), str(node.left.data))
            dot.edge(str(node.data), str(node.left.data))
            add_nodes_edges(dot, node.left)
        if node.right:
            dot.node(str(node.right.data), str(node.right.data))
            dot.edge(str(node.data), str(node.right.data))
            add_nodes_edges(dot, node.right)
    dot = graphviz.Digraph()
    dot.node(str(root.data), str(root.data))
    add_nodes_edges(dot, root)
    return dot

root = Node(6)
root.left = Node(2)
root.right = Node(8)
root.left.left = Node(1)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)

print_tree(root)





"""
class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(data, node.left)
        elif data > node.data:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(data, node.right)
        else:
            print("O valor já existe na árvore!")

    def search(self, data):
        if self.root is None:
            return False
        else:
            return self._search(data, self.root)

    def _search(self, data, node):
        if node is None:
            return False
        elif node.data == data:
            return True
        elif data < node.data:
            return self._search(data, node.left)
        else:
            return self._search(data, node.right)



tree = BinaryTree()

# Inserindo valores na árvore
tree.insert(5)
tree.insert(3)
tree.insert(7)
tree.insert(1)
tree.insert(9)

# Buscando valores na árvore
print(tree.search(5)) # True
print(tree.search(8)) # False

# Visualizando a árvore
tree.print_tree()



Nessa implementação, a classe Node representa um nó da árvore, com um dado (data), e dois ponteiros (left e right) que apontam para os nós filhos esquerdo e direito, respectivamente. A classe BinaryTree representa a árvore binária propriamente dita, e possui um único atributo root que aponta para a raiz da árvore.

O método insert permite inserir um novo valor na árvore. Se a árvore estiver vazia, o valor é inserido como raiz. Caso contrário, o método _insert é chamado recursivamente, comparando o valor a ser inserido com o valor do nó atual, e seguindo pelo caminho apropriado até encontrar uma posição vazia para inserir o novo valor.

O método search permite buscar um valor na árvore. Se a árvore estiver vazia, a busca retorna False. Caso contrário, o método _search é chamado recursivamente, comparando o valor procurado com o valor do nó atual, e seguindo pelo caminho apropriado até encontrar o valor desejado ou chegar a um nó nulo.

Essa é apenas uma implementação básica de uma árvore binária em Python. É possível adicionar outros métodos, como remoção de nós, percorrimento da árvore em ordem, pré-ordem ou pós-ordem, entre outros.

Por que tem dois métodos de inserção e busca?Claro, vou explicar.

O método `insert` é o método público que deve ser utilizado para inserir um novo valor na árvore. Esse método recebe como parâmetro o valor a ser inserido e utiliza o método `_insert` para realizar a inserção de fato. 

Já o método `_insert` é um método privado que é chamado recursivamente pelo método `insert`. O objetivo desse método é percorrer a árvore a partir do nó atual e encontrar a posição onde o novo valor deve ser inserido.

A razão de ter um método público (`insert`) e um método privado (`_insert`) é para evitar que o usuário da classe `BinaryTree` precise lidar com a lógica de percorrer a árvore e encontrar a posição correta para a inserção. Essa lógica é encapsulada no método `_insert`, que é chamado pelo método `insert`.

O mesmo vale para os métodos `search` e `_search`. O método `search` é o método público que deve ser utilizado para buscar um valor na árvore. Esse método recebe como parâmetro o valor a ser buscado e utiliza o método `_search` para realizar a busca de fato.

Já o método `_search` é um método privado que é chamado recursivamente pelo método `search`. O objetivo desse método é percorrer a árvore a partir do nó atual e encontrar o valor desejado.

Em resumo, os métodos públicos (`insert` e `search`) são utilizados pelos usuários da classe `BinaryTree` para inserir e buscar valores na árvore, enquanto os métodos privados (`_insert` e `_search`) realizam as operações de fato, percorrendo a árvore e encontrando a posição correta para inserir ou buscar valores.

"""