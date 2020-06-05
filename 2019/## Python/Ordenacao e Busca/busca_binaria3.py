def busca_binaria(lista, chave):
  primeiro = 0
  ultimo = len(lista)-1
  while primeiro <= ultimo:
    meio = int((primeiro+ultimo)/2)
    if lista[meio] == chave:
      return meio
    if lista[meio] > chave:
      ultimo = meio - 1
    else:
      primeiro = meio +1
  return None


def exibe_lista(lista):
  print(lista)


import random
random.seed()
def gera_valores():
  lista = random.sample(range(1,100), 20)
  return lista

lista = gera_valores()
print('Lista gerada pelo computador')
print('\Desordenada: ')
exibe_lista(lista)
print('')
print('Ordenada: ')
lista.sort()  #no programa da prova deve-se fazer a função de ordenação
exibe_lista(lista)
print('Encontrado na Posicao: ', busca_binaria(lista, int(input('Digite um número: '))))