# Fatorial implementado de forma recursiva

def fatorial(num):

    if num <= 1:
        return 1
    else:
        return(num * fatorial(num - 1))

# Testando fatorial()
num = (int(input("Digite um número: ")))
for i in range(1,num+1):
    print ("O fatorial de ", i, "é: ", fatorial(i))
