# -*- encoding: utf-8 -*-
"""
Bubble-Sort sem Flag em Python
by Ed
"""

def bubble_sort(lista):
    for i in range(0, len(lista)-1):
        for j in range(0, len(lista)-1-i):
                if lista[ j ] > lista[j + 1]:
                        lista[j], lista[j + 1] = lista[j + 1], lista[j]
                #print(lista)
    return lista


while True:
    valor_ini = input("Digite os números do seu vetor, como 10,20,30, digite:")
    valores = eval("["+valor_ini+"]") #interpreta a sequencia como uma lista
    print (bubble_sort(valores))