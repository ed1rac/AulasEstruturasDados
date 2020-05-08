# -*- encoding: utf-8 -*-
"""
Busca Sequencial em Python 
by Ed
"""
import random
def gera_lista():
    lista = random.sample(range(1,100), 20)
    return lista
        
def busca_linear(lista, elemento):
    for i in range(0,len(lista)):
        if elemento == lista[i]:
            return i


    return None

while True:
    lista = gera_lista()
    print(lista)    
    valor_busca = int(input('Qual o valor que você quer buscar no vetor:'))
    encontrou=busca_linear(lista, valor_busca)
    if(encontrou!=None):
        print('Elemento encontrado na posição ', encontrou)
    else:
        print('Elemento não encontrado')
    
    
