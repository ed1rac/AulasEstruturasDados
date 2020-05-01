# encoding: utf-8
"""
Entrada de dados: outra forma
Por: Ed
"""
idade = int(input('Entre com sua idade em anos: '))
freq_card_max = 206.9- (0.67 * idade)
alvo = 0.65 * freq_card_max
print('Sua frequência cardíaca máxima é: ', freq_card_max)
print('Seu alvo defrequencia cardíaca de queima de gordura é: ', alvo)
