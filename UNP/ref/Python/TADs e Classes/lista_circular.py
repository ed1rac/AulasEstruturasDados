class Node:
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None

class DequeCircular:
    def __init__(self):
        self.head = None
        self.cauda = None

    def mostra(self):
        atual = self.head
        while atual:
            print(atual.valor)
            atual = atual.proximo
            if atual == self.head:
                break
    
    def mostra_cabeca(self):
        print(f'Cabeça: {self.head.valor}')

    def mostra_cauda(self):
        print(f'Cauda: {self.cauda.valor}')

    def insere_no_inicio(self, valor):
        node = Node(valor)
        if not self.head:
            self.head = node
            self.cauda = node
            self.cauda.proximo = self.head
        else:
            node.proximo = self.head
            self.head = node
            self.cauda.proximo = self.head

    def insere_no_fim(self, valor):
        node = Node(valor)
        if not self.head:
            self.head = node
            self.cauda = node
            self.cauda.proximo = self.head
        else:
            self.cauda.proximo = node
            self.cauda = node
            self.cauda.proximo = self.head

    def __len__(self):
        atual = self.head
        cont = 0
        while atual:
            cont += 1
            atual = atual.proximo
            if atual == self.head:
                break
        return cont
    
    def remove_do_inicio(self):
        if self.head == self.cauda:
            self.head = None
            self.cauda = None
        else:
            self.head = self.head.proximo
            self.cauda.proximo = self.head

    def remove_do_fim(self):
        if self.head == self.cauda:
            self.head = None
            self.cauda = None
        else:
            atual = self.head
            while atual.proximo != self.cauda:
                atual = atual.proximo
            atual.proximo = self.head
            self.cauda = atual

 

meu_deque_circular = DequeCircular()
meu_deque_circular.insere_no_fim(1)
meu_deque_circular.insere_no_fim(2)
meu_deque_circular.insere_no_fim(3)
meu_deque_circular.insere_no_fim(4)
meu_deque_circular.mostra() # 1 2 3 4
meu_deque_circular.mostra_cabeca()
meu_deque_circular.mostra_cauda()
meu_deque_circular.insere_no_inicio(5)
meu_deque_circular.mostra() # 1 2 3 4
meu_deque_circular.mostra_cabeca()
meu_deque_circular.mostra_cauda()
print('Tamanho da lista: ', len(meu_deque_circular))
meu_deque_circular.remove_do_inicio()
meu_deque_circular.mostra() # 2 3 4
meu_deque_circular.mostra_cabeca()
meu_deque_circular.mostra_cauda()
