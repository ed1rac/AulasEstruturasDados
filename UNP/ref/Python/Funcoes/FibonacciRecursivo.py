def fib(n):
    """
    Fibonacci:
    fib(n) = fib(n - 1) + fib(n - 2) se n > 1
    fib(n) = 1 se n <= 1
    """
    if n > 1:
        return fib(n - 1) + fib(n - 2)
    else:
        return 1

# Mostrar Fibonacci de 1 a 5
#for i in [1, 2, 3, 4, 5]:
for i in range(10+1):
    print ('Fib(',i,') => ', fib(i))
