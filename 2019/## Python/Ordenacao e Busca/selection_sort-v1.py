"""
A estrategia do selection sort é:
1 - iterar usando i de vetor(0) até tamanho do vetor
2 - encontrar o menor elemento
3 - trocar o menor com vetor[i]
"""
def selection_sort(vetor):
    for i in range(0,len(vetor)):
        pos_menor = i
        for j in range(i+1, len(vetor)):
            if vetor[j]<vetor[pos_menor]:
                pos_menor = j
            
        #troca vetor[i] com vetor[pos_menor]
        print('Troca ', vetor[i], ' com ', vetor[pos_menor])
        aux = vetor[i]
        vetor[i] = vetor[pos_menor]
        vetor[pos_menor] = aux

vetor = [10,9,8,7,6,5,4,3,2,1]
print(vetor)
selection_sort(vetor)
print(vetor)
bandas = ['Led Zeppelin', 'Beatles', 'Guns and Roses', 'Pink Floyd', 'ABBA']
print(bandas)
selection_sort(bandas)
print(bandas)