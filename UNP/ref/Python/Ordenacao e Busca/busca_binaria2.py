# -*- encoding: utf-8 -*-
"""
Busca binária em Python (procedural)
Autor: Ed.
Data: 07/05/2020
"""
import random
random.seed()
def gera_lista():
  lista = random.sample(range(1,100),20)
  return lista

def exibe_lista(lista):
  print(lista)

def busca_binaria(lista, item):
  primeiro = 0
  ultimo = len(lista)-1
  while primeiro<= ultimo:
    meio = int((primeiro + ultimo)/2)
    chute = lista[meio]
    if chute == item:
      return meio
    if chute > item:
      ultimo = meio - 1
    else:
      primeiro = meio + 1
  return None

while True:
  lista = gera_lista()
  print('\nLista gerada pelo computador:')
  print('Desordenada: ')
  exibe_lista(lista)
  print('\nOrdenada: ')
  lista.sort()
  exibe_lista(lista)
  elemento = int(input('Digite um número:'))
  resultado = busca_binaria(lista, elemento)
  if resultado!=None:
    print(f'Elemento {elemento} encontrado na posição {resultado}')
  else:
    print('Elemento não encontrado!')  