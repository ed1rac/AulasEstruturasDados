# encoding: utf-8
"""
Entrada de dados: outra forma
Por: Ed
"""
resposta = input('Entre com os valores de a e b, separado por espaços: ')
pecas = resposta.split()
x = float(pecas[0])
y = float(pecas[1])
print ('x = ', x, ' y = ', y)
