def fib(n):
    """Fibonacci:
    fib(n) = fib(n - 1) + fib(n - 2) se n > 1
    fib(n) = 1 se n <= 1
    Usa programação dinâmica: 
    
    """
    
    # Dois primeiros valores
    l = [1, 1]
    
    # Calculando os outros
    for i in range(2, n + 1):
        l.append(l[i -1] + l[i - 2])
        
    return l[n]

# Mostrar Fibonacci de 1 a 5
#for i in [1, 2, 3, 4, 5,6,7,8,9,10]:
for i in range(20):
    print (i, '=>', fib(i))
