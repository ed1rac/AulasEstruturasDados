def mostra_idade(idade):
    if idade == 18:
        print('Você tem exatamente 18 anos')
    elif 20 < idade < 30:
        print('Você está entre 20 e 30 anos')
    elif idade > 30:
        print('Você tem mais de 30 anos')
    else:
        print('Sua idade é menor que 18')


def ler_idade():
    idade = int(input('Digite sua idade: '))
    return idade


for i in range(4):
    idade = ler_idade()
    mostra_idade(idade)
