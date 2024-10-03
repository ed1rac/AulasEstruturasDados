print("Calculando fatoriais de 1 a 15")


def calcular_fatorial(valor):
    contador = 1
    resultado = 0
    listaDeFatoriais = []

   # listagem de fatorial

    while contador <= valor:
        listaDeFatoriais.insert(0, contador)
        contador = contador + 1

    # multiplicando os fatoriais
    if len(listaDeFatoriais) > 1:
        for x in range(len(listaDeFatoriais)-1):
            if x == 0:
                resultado = listaDeFatoriais[x] * listaDeFatoriais[x+1]
            else:
                resultado = resultado * listaDeFatoriais[x+1]

    else:
        resultado = listaDeFatoriais[0]

    return resultado


for x in range(16):
    if x != 0:
        print(f"O fatorial de {x} é: ", calcular_fatorial(x))
