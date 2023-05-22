s = 'Camelo'

# Concatenação
print ('O ' + s + ' foi embora correndo!')

# Interpolação
print ('tamanho de %s => %d' % (s, len(s)))

# String tratada como sequência
for ch in s: print (ch)

# Strings são objetos
if s.startswith('C'): print (s.upper())

# o que acontecerá?
print (3 * s)
# 3 * s é consistente com s + s + s
