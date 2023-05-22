from random import *
print("Programa Raiz quadrada - método de Heron") 
num = float(input("Digite um número para extrair a raiz: "))
#est = num/2
if int(num) == num and (num > 3):
	est = num/2
else:
	est = uniform(0,num/2)
tol = 0.00001
passo = 1
print("======================================")
print(" #  |\test\t       |\t   dif  ")
print("======================================")
print(f"{passo}\t{est}\t\t\t{(est*est)-num}")
while (abs((est*est)-num)>tol):
	est = (est + num/est)/2
	passo+=1
	if passo==2:
		print(f"{passo}\t{est}\t\t\t{(est*est)-num}")
		continue
	print(f"{passo}\t{est}\t{(est*est)-num}")
	
print("")	
print("A raiz 'e: ", est)
print(f"Arredondando, a raiz é: {round(est,4)}")
	
