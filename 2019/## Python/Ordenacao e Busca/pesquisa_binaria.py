# coding=utf-8
def exibe_lista(lista):
    print(lista)

def pesquisa_binaria(lista, item):
    primeiro = 0
    ultimo = len(lista) - 1
    while primeiro <= ultimo:
        meio = int((primeiro + ultimo) / 2)
        chute = lista[meio]
        if chute == item:
            return meio
        if chute > item:
            ultimo = meio - 1
        else:
            primeiro = meio + 1
    return None

import random
random.seed()
def gera_lista():
    lista = random.sample(range(1,100), 20)
    return lista

while True:
    outra_lista = gera_lista()
    print ('\nlista gerada pelo computador:')
    print ('Desordenada: ')
    exibe_lista(outra_lista)
    print ('')
    print ('ordenada: ')
    outra_lista.sort()
    exibe_lista(outra_lista)
    print ('Posicao: ', pesquisa_binaria(outra_lista, int(input("Digite um numero: "))))
