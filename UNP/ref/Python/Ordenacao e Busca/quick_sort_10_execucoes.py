import random
import time

def quicksort(array):
  if len(array) <= 1:
    return array
  pivo = array[len(array)//2]  #o elemento "central"
  menores = [x for x in array if x < pivo] 
  meio = [x for x in array if x == pivo]
  maiores = [x for x in array if x > pivo]
  return quicksort(menores) + meio + quicksort(maiores)

def gera_ordena():
  lista = []
  lista = random.sample(range(100000),10000)
  #print(quicksort(lista))
  quicksort(lista)

tempos = []
for _ in range(11):  
  inicio = time.time()
  gera_ordena()
  fim = time.time()
  tempo_gasto = fim - inicio
  tempos.append(tempo_gasto)

soma_tempos = 0  
for i in range(len(tempos)):
  soma_tempos = soma_tempos + tempos[i]
  print('Tempo gasto: %f milissegundos' % tempos[i])

print('')
print('A média dos tempos foi ', soma_tempos/10)

#print('Lista gerada pelo computador - desordenada')
#print(lista)
#print('Lista gerada pelo computador - ordenada')
