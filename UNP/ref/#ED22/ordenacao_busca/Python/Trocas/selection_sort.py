# -*- encoding: utf-8 -*-
"""
Selection-Sort sem Flag em Python
by Ed
"""
def selection_sort(uma_lista):
    
   for i in range(len(uma_lista)):
      # Encontra o menor elemento restante
       posicao_menor = i

       for j in range(i+1, len(uma_lista)):
           if uma_lista[posicao_menor] > uma_lista[j]:
               posicao_menor = j
               
       # troca o menor elemento       
       temp = uma_lista[i]
       uma_lista[i] = uma_lista[posicao_menor]
       uma_lista[posicao_menor] = temp
       print(uma_lista)
       
   return uma_lista
     
while True:
    valor_ini = input("Digite os números do seu vetor, como 10,20,30, digite:")
    valores = eval("["+valor_ini+"]") #interpreta a sequencia como uma lista
    print (selection_sort(valores))
