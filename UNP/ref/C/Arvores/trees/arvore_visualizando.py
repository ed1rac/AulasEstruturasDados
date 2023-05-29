class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def print_tree(node, level=0):
    if node is not None:
        print_tree(node.right, level+1)
        print(' ' * 4 * level + '->', node.value)
        print_tree(node.left, level+1)

def insere_direita(node, value):
    if node.right is None:
        node.right = Node(value)
    else:
        insere_direita(node.right, value)

def insere_esquerda(node, value):
    if node.left is None:
        node.left = Node(value)
    else:
        insere_esquerda(node.left, value)



root = Node(6)
root.left = Node(2)
root.right = Node(8)
root.left.left = Node(1)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)

print_tree(root)
