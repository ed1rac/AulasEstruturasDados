def bubble_sort(vetor):
    for i in range(len(vetor)-1, 0, -1):
        for j in range(0,len(vetor)-1):
            if vetor[j]>vetor[j+1]:
                print('Troca ', vetor[j], 'com ', vetor[j+1])
                aux = vetor[j]
                vetor[j] = vetor[j+1]
                vetor[j+1] = aux

vetor = [10,9,8,7,6,5,4,3,2,1]
print(vetor)
bubble_sort(vetor)
print(vetor)
bandas = ['Led Zeppelin', 'Beatles', 'Guns and Roses', 'Pink Floyd', 'ABBA']
print(bandas)
bubble_sort(bandas)
print(bandas)