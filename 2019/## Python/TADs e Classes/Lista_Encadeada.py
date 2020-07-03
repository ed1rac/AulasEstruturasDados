class No:
    def __init__(self, carga=None, proximo=None):
        self.carga = carga
        self.proximo = proximo

    def __str__(self):
        return str(self.carga)
    
    def imprime_lista(self, no):
        while no:
            print(no.carga)
            self.imprime_lista(no.proximo)
            print('')

def imprimeDeTrasParaFrente(lista):
    if lista == None : return
    cabeca = lista
    rabo = lista.proximo
    imprimeDeTrasParaFrente(rabo)
    print(cabeca,)

def imprimeLista(no):
    while no:
        print (no,)
        no = no.proximo
    print()

print('Calma')
no = No("Teste")
no2 = no.proximo = No('De')
no3 = no2.proximo = No('Lista')
no4 = no3.proximo = No('em Python')

imprimeLista(no)
imprimeDeTrasParaFrente(no)