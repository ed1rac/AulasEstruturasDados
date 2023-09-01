# -*- encoding: utf-8 -*-
"""
Busca sequencial em Python (procedural)
Autor: Ed.
Data: 07/05/2020
"""
import random
def gera_lista():
  lista = random.sample(range(1,100),20)
  return lista

def busca_linear(lista, elemento):
  for i in range(0,len(lista)):
    if elemento == lista[i]:
      return i

  
  return None

def busca_linear_rec(lista, elemento, tamanho):
  if tamanho==0:
    return -1
  if(elemento==lista[tamanho-1]):
    return tamanho-1
  return busca_linear_rec(lista, elemento, tamanho-1)

while True:
  lista = gera_lista()
  print(lista)
  valor_busca = int(input('Qual valor você quer buscar no vetor: '))
  #encontrou = busca_linear(lista, valor_busca)
  encontrou = busca_linear_rec(lista, valor_busca, len(lista))
  if(encontrou!=None):
    print(f'Elemento encontrado na posição: {encontrou}')
  else:
    print('Elemento não encontrado no vetor')


    
