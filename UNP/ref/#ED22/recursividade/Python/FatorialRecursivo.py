# coding=utf-8
# Fatorial implementado de forma recursiva

def fatorial(num):

    if num <= 1:
        return 1
    else:
        return(num * fatorial(num - 1))

#Testando fatorial()
#print (fatorial(5))
for i in range(0,15+1):
    print("O fatorial de ", i, "é ", fatorial(i))


