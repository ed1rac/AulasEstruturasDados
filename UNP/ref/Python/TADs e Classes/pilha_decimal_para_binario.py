class Stack:

  def __init__(self):
    self.items = []

  def push(self, item):
    self.items.append(item)

  def pop(self):
    return self.items.pop()

  def pilha_vazia(self):
    return (self.items == [])

#programa
p = Stack()
p.push(45)
p.push(54)
p.push('+')
p.push(66)
while not p.pilha_vazia():
  print(p.pop())

pilha = Stack()
valor = int(input('Digite um valor inteiro: '))
final = valor
while valor != 0:
  x = valor
  resto = x % 2
  valor = x // 2
  pilha.push(resto)

print(f"{final} em binário é: ", end= ' ')
while not pilha.pilha_vazia():
  print(pilha.pop(), end='')

print('')
