
class Ponto(object):    

    def __init__(self, x, y):   #método construtor (cria ponto)
        self.x = x
        self.y = y


    def exibe_ponto(self):
        print('Coordenadas -> x: ', self.x, ', y: ', self.y)


    def set_x(self, x):
        self.x = x

    def set_y(self, y):
        self.y = y

    def distancia_entre(self, q):
        dx = q.x - self.x
        dy = q.y - self.y
        return (dx*dx+dy*dy)**0.5

class ponto_n(Ponto):
    def __init__(self, x, y, nome):
        super().__init__(x, y)
        self.nome = nome
    
    def exibe_ponto(self):
        print('Ponto: ', self.nome)
        super().exibe_ponto()


p = Ponto(2.0,1.0)
q = Ponto(3.4, 2.1)
p1 = ponto_n(2, 1, 'P')
q1 = ponto_n(3.4, 2.1, 'Q')
p.exibe_ponto()
q.exibe_ponto()
p1.exibe_ponto()
q1.exibe_ponto()
print('A distância entre o ponto p e q é: ', p.distancia_entre(q))