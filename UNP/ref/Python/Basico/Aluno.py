# classo aluno em python
class Aluno:

    def __init__(self, nome, idade, matricula):
        self.nome = nome
        self.idade = idade
        self.matricula = matricula

    def get_nome(self):
        return self.nome

    def get_idade(self):
        return self.idade

    def get_matricula(self):
        return self.matricula

    def set_nome(self, nome):
        self.nome = nome

    def set_idade(self, idade):
        self.idade = idade

    def set_matricula(self, matricula):
        self.matricula = matricula

    def __str__(self):
        return 'Nome: ' + self.nome + ' Idade: ' + str(self.idade) + ' Matricula: ' + str(self.matricula)


# uso da classe aluno
aluno = Aluno('João', 20, 123)
print(aluno)
print(aluno.get_nome())
print(aluno.get_idade())
print(aluno.get_matricula())
aluno.set_nome('Maria')
aluno.set_idade(30)
aluno.set_matricula(456)
print(aluno)
