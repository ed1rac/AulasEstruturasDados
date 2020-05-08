# -*- encoding: utf-8 -*-
"""
Merge sem Flag em Python
by Ed
"""
# merge
def merge(a,b):
    """ Função para juntar os dois arrays """
    ordenado = []
    while len(a) != 0 and len(b) != 0:
        if a[0] < b[0]:
            ordenado.append(a[0])
            a.remove(a[0])
        else:
            ordenado.append(b[0])
            b.remove(b[0])
    if len(a) == 0:
        ordenado += b
    else:
        ordenado += a
    return ordenado


# Codigo do mergestort
def mergesort(lista):
    """ Função para ordenar um vetor usando o mergesort """
    if len(lista) == 0 or len(lista) == 1:
        return lista
    else:
        meio = int(len(lista)/2)
        esquerda = mergesort(lista[:meio])        
        direita = mergesort(lista[meio:])      
        return merge(esquerda,direita)
     
while True:
    valor_ini = input("Digite os números do seu vetor, como 10,20,30, digite:")
    valores = list(eval("["+valor_ini+"]")) #interpreta a sequencia como uma lista
    #valores = list(eval(valor_ini))"""
    #valores = [9,8,7,6,5,4,3,2,1]
    print(valores)
    print (mergesort(valores))
