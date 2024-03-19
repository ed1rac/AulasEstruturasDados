# Definição do TAD Fila
class Fila(object):
    'uma classe de fila clássica'

    def __init__(self):
        'instancia uma lista vazia'
        self.items = []

    def esta_vazia(self):
        'retorna True se a lista está vazia, False caso contrário'
        return (len(self.items) == 0)  # se o tamanho for zero

    def enfileira(self, item):  # enqueue
        'insere item no final da fila'
        return self.items.append(item)

    def desenfileira(self):  # dequeue
        'remove e retorna o item na frente da fila'
        if not (self.esta_vazia()):
            return self.items.pop(0)
        print('Impossível desenfileirar. Fila está vazia')

    def imprime(self):
        'imprime a fila'
        print(self.items)

    def size(self):
        'retorna o número de itens na fila'
        return len(self.items)


fila = Fila()
if fila.esta_vazia:
    print('Fila está vazia!')
x = fila.desenfileira()
fila.enfileira('Edkallenn')
fila.enfileira('Vanessa')
fila.enfileira(1)
fila.enfileira(2)
fila.enfileira(3)
fila.enfileira('João')
fila.imprime()
print(fila.desenfileira())
print(fila.desenfileira())
print(fila.desenfileira())
fila.imprime()
print(f'Tamanho da fila: {fila.size()}')
