class Node:
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None

class Stack:
    def __init__(self):
        self.tamanho = 0
        self.topo = None

    def is_empty(self):
        return self.topo is None

    def push(self, valor):
        novo_no = Node(valor)
        novo_no.proximo = self.topo
        self.topo = novo_no
        self.tamanho += 1

    def pop(self):
        if self.is_empty():
            return None
        else:
            node_to_remove = self.topo
            self.topo = self.topo.proximo
            node_to_remove.proximo = None
            self.tamanho -= 1
            return node_to_remove.valor

    def peek(self):
        if self.is_empty():
            return None
        else:
            return self.topo.valor
        
    def __len__(self):
        return self.tamanho
    
    def __repr__(self):
        r = ''
        pointer = self.topo
        while pointer:
            r = r + str(pointer.valor) + '\n'
            pointer = pointer.proximo
        return r

pilha = Stack()
pilha.push(1)
pilha.push(2)
pilha.push(3)
pilha.push(4)
print(pilha) # 4 3 2 1
print(pilha.peek()) # 4
print(pilha.pop()) # 4
print(pilha) # 3 2 1
print(pilha.pop()) # 3
print(pilha) # 2 1
print(pilha.pop()) # 2
print(pilha) # 1
print(pilha.pop()) # 1
print(pilha) # None
print(pilha.pop()) # None
