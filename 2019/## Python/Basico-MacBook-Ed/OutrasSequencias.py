# Conjuntos de dados
s1 = set(range(3))
s2 = set(range(10, 7, -1))
s3 = set(range(2, 10, 2))

# Exibe os dados
print ('s1:', s1, '\ns2:', s2, '\ns3:', s3)

# União
s1s2 = s1.union(s2)
print ('União de s1 e s2:', s1s2)

# Diferença
print ('Diferença com s3:', s1s2.difference(s3))

# Interseção
print ('Interseção com s3:', s1s2.intersection(s3))

# Testa se um set inclui outro
if s1.issuperset([1, 2]):
    print ('s1 inclui 1 e 2')

# Testa se não existe elementos em comum
if s1.isdisjoint(s2):
    print ('s1 e s2 não tem elementos em comum')
