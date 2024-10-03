class Pilha:
    def __init__(self, capacidade):
        self.capacidade = 50
        self.topo = -1
        self.valores = []
        
    def push(self, valor):
        self.valores.append(valor)
    
    def pop(self):
        return self.valores.pop()
    
    def peek(self):
        print("Topo da pilha: ", self.valores[-1])
        
    def exibe(self):
        print("Exibindo pilha: ", self.valores)
        
        
pilha = Pilha(50)
pilha.push(13)
pilha.push(17)
pilha.push(22)
pilha.exibe()
pilha.peek()
print("valor desempilhado: ", pilha.pop())
pilha.exibe()