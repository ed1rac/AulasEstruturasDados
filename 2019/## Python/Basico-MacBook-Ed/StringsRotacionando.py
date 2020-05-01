import string
a = string.ascii_letters #a recebe o alfabeto INTEIRO
print (a) #veja
#pede uma mensagem
msg = str(input("Digite um texto qualquer para rotacionar:"))
#pede quantidade de numeros para rotacionar (rot-xx)
quant = int(input("Digite a quantidade de vezes: "))
rot = a[quant:] + a[0]
print("\nAlfabeto Rotacionado:")
print(rot)

#tab=str.maketrans(msg,rot) #rotaciona o texto digitado
#print("\nTexto digitado rotacionado %d vezes para a direita:" % quant)
#print(msg.translate(quant))
