class Celula:
    def __init__(self, valor, prox=None):
        self.__valor = valor
        self.prox = prox

    @property
    def valor(self):
        return self.__valor

    def mostra(self):
      print(self.valor)

    def __str__(self):
        return str(self.__valor)

def imprime_tudo(celula):
    while celula:
        print (" {} ".format(celula.valor), end="-->")
        celula = celula.prox
    print(" None")


e1 = Celula(4)
e2 = Celula(5)
e3 = Celula(6)

e1.prox = e2
e2.prox = e3
e3.prox = None

imprime_tudo(e1)