"""
A estrategia do insertion sort é:
1 - dividir o vetor em dois menores até sobrar somente um elemento
2 - combinar as solucoes intercalando em outro vetor agora ordenando 
    elemento por elemento dos subvetores
"""
import math

def merge_sort(vetor):
    #fim = fim-1
    if len(vetor) == 0 or len(vetor) == 1:
        return vetor
    else:
        meio = int(len(vetor)/2)
        esquerda = merge_sort(vetor[:meio])
        direita = merge_sort(vetor[meio:])
        return intercala(esquerda, direita)

def intercala(a, b):
    ordenado = []
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

vetor = [10,9,8,7,6,5,4,3,2,1]
print(vetor)
#print(len(vetor))
print(merge_sort(vetor))
bandas = ['Led Zeppelin', 'Beatles', 'Guns and Roses', 'Pink Floyd', 'ABBA']
print(bandas)
print(merge_sort(bandas))