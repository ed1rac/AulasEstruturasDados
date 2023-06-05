class No:
    def __init__(self, valor=None, proximo=None):
        self.valor = valor
        self.proximo = proximo

    def __str__(self):
        return str(self.valor)

    def imprime_lista(self, no):
        while no:
            print(no.valor)
            self.imprime_lista(no.proximo)
            print('')


def imprimeDeTrasParaFrente(lista):
    if lista == None:
        return
    cabeca = lista
    rabo = lista.proximo
    imprimeDeTrasParaFrente(rabo)
    print(cabeca,)


def imprimeLista(no):
    while no:
        print(no,)
        no = no.proximo
    print()


print('Calma')
no = No("Teste")
no2 = no.proximo = No('De')
no3 = no2.proximo = No('Lista')
no4 = no3.proximo = No('em Python')

imprimeLista(no)
imprimeDeTrasParaFrente(no)
