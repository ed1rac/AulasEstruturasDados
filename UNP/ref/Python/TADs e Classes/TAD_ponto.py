
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

    def get_x(self):
      return self.x

    def get_y(self):
      return self.y

    def distancia_entre(self, q):
        dx = q.x - self.x
        dy = q.y - self.y
        return (dx*dx+dy*dy)**0.5

    def distancia_ate_origem(self):
        return ((self.x ** 2) + (self.y ** 2)) ** 0.5

p = Ponto(2.0,1.0)
q = Ponto(3.4, 2.1)
p.exibe_ponto()
q.exibe_ponto()
print('A distância entre o ponto p e q é: ', p.distancia_entre(q))
print(f'As coordenadas de p: {p.get_x()}, {p.get_y()}')
print(f'As coordenadas de p: {q.get_x()}, {q.get_y()}')
print('Distância de {} até a origem: {}'.format('p',p.distancia_ate_origem()))