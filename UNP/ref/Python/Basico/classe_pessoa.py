class Pessoa():

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def get_nome(self):
        return self.nome

    def get_idade(self):
        return self.idade

    def set_nome(self, nome):
        self.nome = nome

    def set_idade(self, idade):
        self.idade = idade

    def __str__(self):
        return 'Nome : ' + self.nome + ' - Idade: ' + str(self.idade)


#testando a classe pessoa
pessoa = Pessoa('Maria Clara Lau', 20)
print(pessoa)
print(pessoa.get_nome())
print(pessoa.get_idade())
pessoa.set_nome('Rebecca Nery')
pessoa.set_idade(23)
print(pessoa)

    
        
