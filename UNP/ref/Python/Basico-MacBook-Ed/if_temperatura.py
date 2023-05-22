temp = int(input('Entre com a temperatura: '))
if temp < 0:
    print('Congelando... - Está muito frio igual ao lab 6')
elif 0 <= temp <= 20:
    print('Frio!')
elif 21 <= temp <= 25:
    print('Normal')
elif 26 <= temp <= 35:
    print('Quente!')
else:
    print('VocÊ está no ACRE!!')