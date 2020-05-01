musicos = [('Page', 'guitarrista', 'Led Zeppelin'),
('Fripp', 'guitarrista', 'King Crimson')]

# Parâmetros identificados pela ordem
msg = '{0} é {1} do {2}'

for nome, funcao, banda in musicos:
    print((msg.format(nome, funcao, banda)))

# Parâmetros identificados pelo nome
msg = '{saudacao}, são {hora:02d}:{minuto:02d}'

print (msg.format(saudacao='Bom dia', hora=7, minuto=30))

# Função builtin format()
print ('Pi =', format(3.14159, '.3e'))
