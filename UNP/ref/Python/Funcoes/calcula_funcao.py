def soma(num1, num2):
    return num1 + num2

def subtracao(x,y):
    return x-y

def multiplicacao(x,y):
    return x * y

def divisao(x,y):
    if y == 0:
        print('Não posso dividir por zero')
        return
    return x/y

def potencia(x,y):
    return x ** y

def calcula(x,y):
    print('%.3f + %.3f = %.3f' % (x,y,soma(x,y)))
    print('%.3f - %.3f = %.3f' % (x,y,subtracao(x,y)))
    print('%.3f * %.3f = %.3f' % (x,y,multiplicacao(x,y)))
    print('%.3f / %.3f = %.3f' % (x,y,divisao(x,y)))
    print('%.3f ** %.3f = %.3f' % (x,y,potencia(x,y)))

def boas_vindas():
    print('Olá. Este programa realiza alguns cálculos com dois números')
    print('Por favor, digite-os abaixo: ')

def ler_numero():
    x = float(input('Digite um número qualquer: '))
    return x

def principal():
    boas_vindas()
    num1 = ler_numero()
    num2 = ler_numero()
    calcula(num1,num2)


principal()