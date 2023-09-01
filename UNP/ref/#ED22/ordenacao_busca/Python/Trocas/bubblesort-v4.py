def bubble_sort(vetor):
    troca = False
    ultimo = len(vetor)-1

    while True:
        for i in range(0,ultimo):
            troca = False
            if vetor[i]>vetor[i+1]:
                print('Troca ', vetor[i], 'com ', vetor[i+1])
                aux = vetor[i]
                vetor[i] = vetor[i+1]
                vetor[i+1] = aux
                troca = True
            ultimo = ultimo - 1
            if troca == False:
                break





"""
    for i in range(0,len(vetor)):
        print(i)
        for j in range(0,(len(vetor)-1)-i):
            if vetor[j]>vetor[j+1]:
                print('Troca ', vetor[j], 'com ', vetor[j+1])
                aux = vetor[j]
                vetor[j] = vetor[j+1]
                vetor[j+1] = aux
"""
vetor = [10,9,8,7,6,5,4,3,2,1]
print(vetor)
bubble_sort(vetor)
print(vetor)
bandas = ['Led Zeppelin', 'Beatles', 'Guns and Roses', 'Pink Floyd', 'ABBA']
print(bandas)
bubble_sort(bandas)
print(bandas)