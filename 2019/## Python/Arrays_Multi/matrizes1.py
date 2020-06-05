def crie_matriz(n_linhas, n_colunas, valor):	
	    matriz = [] # lista vazia
	    for i in range(n_linhas):
	        # cria a linha i
	        linha = [] # lista vazia
	        for j in range(n_colunas):
	            linha.append(valor)
	
	        # coloque linha na matriz
	        matriz.append(linha)
	
	    return matriz

def exibe_matriz(matriz, linhas, colunas):
  for i in range(linhas):
    for j in range(colunas):
      print(matriz[i][j], end="\t")
    print('')


#primeira forma
matriz = []
for i in range(5):
  matriz.append([0]*5)
matriz[1][1] = 2

exibe_matriz(matriz,5,5)
print('')

#segunda forma
matriz2 = crie_matriz(3,4,1)
exibe_matriz(matriz2,3,4)

print('')

#terceira forma
matriz3 = [
  [1,2,3],
  [4,5,6],
  [7,8,9],
  [10,11,12]
]

exibe_matriz(matriz3, 4,3)