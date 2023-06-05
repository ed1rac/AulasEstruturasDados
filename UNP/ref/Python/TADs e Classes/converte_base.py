from pilha_dinamica import Stack

def ler_numero():
    return int(input('Digite um número inteiro: '))

def ler_base():
    return int(input('Digite a base para conversão: '))

def converter(num, base):
    pilha = Stack()
    numero = num
    while numero != 0:
        x = numero
        resto = x % base
        numero = x // base
        pilha.push(resto)
    print(f'{num:5} em base {base} é: ', end='')
    while not pilha.is_empty():
        print(pilha.pop(), end='')
    print('')

def main():
    numero = ler_numero()
    base = ler_base()
    for i in range(1, numero):
        converter(i, base)

if __name__ == '__main__':
    main()
    