"""
A estrategia do insertion sort é:
1 - iterar usando i de vetor[1] até tamanho do vetor (laço externo) - vetor[i] é o atual
2 - fazer um laço (usando j) de i-1 até 0 e: (laço interno)
3 - se o valor de atual < vetor[j], afasta vetor[j] para direita
4 - quando vetor[j] encontrar um valor menor ou 0, então insere o atual em vetor[j+1]
"""
def insertion_sort(vetor):
    for i in range(1,len(vetor)):
        atual = vetor[i]
        j = i-1
        while j>=0 and atual < vetor[j]:
            vetor[j+1] = vetor[j]
            j = j - 1
            #print(vetor)
        vetor[j+1] = atual

vetor = [10,9,8,7,6,5,4,3,2,1]
print(vetor)
insertion_sort(vetor)
print(vetor)
bandas = ['Led Zeppelin', 'Beatles', 'Guns and Roses', 'Pink Floyd', 'ABBA']
print(bandas)
insertion_sort(bandas)
print(bandas)