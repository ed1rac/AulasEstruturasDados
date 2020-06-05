def exibe_lista(lista):
  print(lista)

lista = [1,2,3,4,5,6,7,8,9,10,2,3,4,5,8,7,9,3]
exibe_lista(lista)
lista_1 = set(lista)
lista = list(lista_1)
exibe_lista(lista)

import random
def matriz(n_linhas, n_colunas):
    matriz = [] # Matriz
    linha = [] # Linha

    while len(matriz) != n_linhas: 
        n = random.randint(0,99) 
        linha.append(n) 

        if len(linha) == n_colunas: 
            matriz.append(linha) 
            linha = [] 
    return matriz # Retorno a mesma




print(matriz(3,3))