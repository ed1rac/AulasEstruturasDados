def fib(n):
  """
  Fibonacci usando programação dinâmica:
  A programação dinâmica é uma técnica de projeto de algoritmos onde
  a solução ótima pode ser computada a partir de soluções ótimas previamente calculadas e memorizadas - de forma a evitar recálculo - de outros subproblemas que, sobrepostos, compõem o problema original
  fib(n) = fib(n-1) + fib(n-2), se n> 1
  fib(n) = 1, se n >= 1
  """
  #dois primeiros valores
  lista = [1,1]

  #calcular os outros valores
  for i in range(2,n+1):
    lista.append(lista[i-1]+lista[i-2])

  return lista[n]
 
def pedir_numero():
  numero = int(input('Digite um numero inteiro: '))
  return numero

def tela_boas_vindas(nome_programa):
  print("*****************************************************")
  print("     Bem vindo ao programa:", nome_programa)
  print("*****************************************************")

#testando a função
tela_boas_vindas('Fibonacci não-recursivo')
num = pedir_numero()
for i in range(0, num+1):
  print('Fib(',i, ') => ', fib(i))