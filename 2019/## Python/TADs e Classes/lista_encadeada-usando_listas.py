class Lista:
    def __init__(self):
        self.items = []

    def __str__(self):          #toString do Java
        return str(self.items)

    def insere(self, item):
        self.items.insert(0,item)

    def remove(self, elemento):
        self.items.remove(elemento)

    def estaVazia(self):
        return (self.items == [])

    def exibe_lista(self):
        print(lista)


lista = Lista()
print(lista.estaVazia())
lista.insere(4)
lista.insere(666)
lista.insere(742)
lista.exibe_lista()
lista.remove(742)
lista.exibe_lista()
print(lista.estaVazia())
