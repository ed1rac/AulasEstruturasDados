class Pilha(object):
    def __init__(self, max):
        self.dados = [None] * max
        self.topo = -1

    def empilha(self, elemento):
        if self.topo < len(self.dados) - 1:
            self.topo += 1
            self.dados[self.topo] = elemento

    def desempilha(self):
        if self.topo >= 0:
            elemento = self.dados[self.topo]
            self.topo -= 1
            return elemento

    def vazia(self):
        return self.topo == -1
    
    def peek(self):
        if not self.vazia():
            return self.dados[self.topo]
    
    def exibe_pilha_completa(self):
        print('Pilha completa: ', self.dados)

    def exibe_topo(self):
        print('Topo: ', self.peek())


pilha = Pilha(5)
pilha.empilha(1)
pilha.empilha(2)
pilha.exibe_topo()
pilha.empilha(3)
pilha.empilha(4)
pilha.exibe_topo()
pilha.empilha(5)
pilha.exibe_topo()
pilha.exibe_pilha_completa()

