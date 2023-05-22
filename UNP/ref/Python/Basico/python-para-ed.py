# mostrar os tipos de dados básicos do python
# int, float, str, bool, list, tuple, dict, set, complex
# type() mostra o tipo de dado
# type(1) -> int
# type(1.0) -> float
# type('1') -> str
# type(True) -> bool
# type([]) -> list
# type(()) -> tuple
# type({}) -> dict

# Exemplo de uso de listas
lista = [1, 2, 3, 4, 5]
print(lista)
print(type(lista))
print(lista[0])
print(lista[1])
print(lista[4])
print(lista[-1])
print(lista[-2])
print(lista[0:3])
print(lista[1:4])
print(lista[4:7])
print(lista[0:])
print(lista[1:])
print(lista[3:])
# mais exemplos de listas
lista2 = [1, 2.0, '3', True, [1, 2, 3],
          (1, 2, 3), {'a': 1, 'b': 2}, {1, 2, 3}, 1+2j]
print(lista2)
print(type(lista2))
print(type(lista2[0]))

dicionario = {'a': 1, 'b': 2, 'c': 3}
print(dicionario)
print(type(dicionario))
print(dicionario['a'])
print(dicionario['b'])
print(dicionario['c'])
print(dicionario.keys())
print(dicionario.values())
print(dicionario.items())

# exemplo de tuplas
tupla = (1, 2, 3, 4, 5)
print(tupla)
print(type(tupla))
print(tupla[0])
print(tupla[1])
print(tupla[4])
print(tupla[-1])
print(tupla[-2])
print(tupla[0:3])
# métodos de tuplas
print(tupla.count(1))
print(tupla.index(1))
