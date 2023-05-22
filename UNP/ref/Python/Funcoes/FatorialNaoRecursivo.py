def fatorial(n):
    n = n if n > 1 else 1
    j = 1
    for i in range(1, n + 1):
        j = j * i
    return j

def pedir_numero():
    numero = int(input('Digite um numero inteiro nao negativo:'))
    return numero

def tela_boas_vindas():
    print("*********************************")
    print("***   Bem vindo ao programa!  ***")
    print("*********************************")

# Testando...
tela_boas_vindas()
num = pedir_numero()
for i in range(1, num+1):
    print (i, '! ->', fatorial(i))
