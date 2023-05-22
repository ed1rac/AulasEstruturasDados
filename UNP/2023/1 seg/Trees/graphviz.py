import graphviz as gv


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    # Função para adicionar um novo nó à árvore
    def add_node(self, root, value):
        if root is None:
            return Node(value)
        else:
            if value < root.value:
                root.left = self.add_node(root.left, value)
            else:
                root.right = self.add_node(root.right, value)
            return root

# Função para criar uma representação em Graphviz da árvore


def build_graph(root, graph):
    if root is not None:
        graph.node(str(root.value))
        if root.left is not None:
            graph.edge(str(root.value), str(root.left.value))
            build_graph(root.left, graph)
        if root.right is not None:
            graph.edge(str(root.value), str(root.right.value))
            build_graph(root.right, graph)


# Cria uma árvore binária de busca com os valores 5, 3, 7, 1, 9, 4, e 6
root = Node(10)
root.add_node(root, 5)
root.add_node(root, 3)
root.add_node(root, 7)
root.add_node(root, 1)
root.add_node(root, 9)
root.add_node(root, 4)
root.add_node(root, 6)

# Cria um objeto Graphviz para representar a árvore
graph = gv.Digraph(format='png')
build_graph(root, graph)

# Renderiza a árvore e salva em um arquivo PNG
graph.render('arvore_binaria')
