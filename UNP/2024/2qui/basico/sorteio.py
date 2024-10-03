import random

def sortear_numeros():
    # Lista para armazenar os números sorteados
    numeros_sorteados = []

    # Realizar o sorteio de 8 números
    for _ in range(8):
        # Gerar um número aleatório entre 0 e 999
        numero = random.randint(0, 999)

        # Adicionar o número formatado à lista de números sorteados
        numeros_sorteados.append(f'{numero:03}')  # Formata o número para sempre ter 3 dígitos

    # Retornar a lista de números sorteados
    return numeros_sorteados

# Chamada da função para sortear os números e mostrar na tela
numeros_sorteados = sortear_numeros()
print("Números sorteados:")
for numero in numeros_sorteados:
    print(f'Número sorteado #{numero}')
    print(numero)
    input("Pressione qualquer tecla")
    
