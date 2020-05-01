print('%d' % 123)
print('%4.2f' % 12.3678)
nome = 'Janaína Souza'
idade = 26
media = 8.92356
print('O seu nome é %s e sua idade é %d' % (nome, idade))
print('O seu nome é {0} e sua idade é {1}'.format(nome, idade))
string = 'Nome = {0}. Idade = {1}. Média = {2:.4f}'
print(string.format(nome, idade, media))