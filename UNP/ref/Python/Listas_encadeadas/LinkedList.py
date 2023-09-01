from Node import Node
#sequencial = []

class ListaEncadeada:
    def __init__(self):
        self.head = None
        #self.tail = None
        self._size = 0

    #adiciona no final da lista
    def append(self, elemento):
        if self.head:
            # inserção quando a lista já possui elemento
            ponteiro = self.head
            while(ponteiro.prox):
                ponteiro = ponteiro.prox
            ponteiro.prox = Node(elemento)
        else:
            # primeira inserção
            self.head = Node(elemento)
        self._size = self._size + 1

    def __repr__(self):
        r = ""
        pointer = self.head
        while(pointer):
            r = r + str(pointer.dado) + "->"
            pointer = pointer.prox
        r = r + "None"
        return r

    def __str__(self):
        return self.__repr__()



#testa a classe ListaEncadeada
if __name__ == '__main__':
    # sequencial = []
    # sequencial.append(7)
    lista = ListaEncadeada()
    lista.append(7)
    lista.append(80)
    lista.append(56)
    lista.append(32)
    lista.append(17)
    print(lista)

        