# -*- encoding: utf-8 -*-
"""
Insertion Sort em Python
by Ed
""" 
def insertion_sort(lista):
    for i in range(1,len(lista)):
        eleito = lista[i]
        j = i-1
        while j >= 0 and eleito < lista[j]:
            lista[j+1] = lista[j]
            j=j-1
        lista[j+1] = eleito
        print(lista)

    return lista
     
while True:
    valor_ini = input("Digite os números do seu vetor, como 10,20,30, digite:")
    valores = eval("["+valor_ini+"]") #interpreta a sequencia como uma lista
    print (insertion_sort(valores))
