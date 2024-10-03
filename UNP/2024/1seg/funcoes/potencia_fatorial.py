def potencia_fatorial_crescente(x, n):
    # Implemente o cálculo da potência fatorial crescente aqui
    resultado = 1
    for i in range(1, n + 1):
        resultado *= (x + i - 1)
    return resultado

def potencia_fatorial_decrescente(x, n):
    # Implemente o cálculo da potência fatorial decrescente aqui
    resultado = 1
    for i in range(n, 0, -1):
        resultado *= (x - i + 1)
    return resultado

# Teste suas funções
x = 5
n = 3

resultado_crescente = potencia_fatorial_crescente(x, n)
resultado_decrescente = potencia_fatorial_decrescente(x, n)

print(f"A potência fatorial crescente de {x}^{n} é {resultado_crescente}")
print(f"A potência fatorial decrescente de {x}_{n} é {resultado_decrescente}")
