nota1 = float(input('Entre com a primeira nota: '))
nota2 = float(input('Entre com a segunda nota: '))
media = (nota1 + nota2)/2
if media > 7:
    print('Sua media é: ', media, ' e vc foi aprovado!!')
elif 4 < media < 7:
    print('Sua media é: ', media, ' e vc vai fazer FINAL. Estude mais!')
else:
    print('Você foi reprovado. Sua media, ', media, ' foi insuficiente!!')

