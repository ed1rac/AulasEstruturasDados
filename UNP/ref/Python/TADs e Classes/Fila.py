class Fila(object):
  'uma classe de fila clássica'

  def __init__(self):
    'instancia uma lista vazia'
    self.f = []

  def esta_vazia(self):
    'retorna True se a lista está vazia, False caso contrário'
    return (len(self.f)==0) #se o tamanho for zero

  def enfileira(self, item):    #enqueue
    'insere item no final da fila'
    return self.f.append(item)

  def desenfileira(self):       #dequeue
    'remove e retorna o item na frente da fila'
    return self.f.pop(0)


fila = Fila()
fila.enfileira('Edkallenn')
fila.enfileira('Vanessa')
x = fila.desenfileira()
y = fila.desenfileira()
print(x)
print(y)