from math import hypot

class Vetor:

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return 'Vetor(%r, %r)' % (self.x, self.y)

    def __abs__(self):
        return hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vetor(x,y)

    def __mul__(self, escalar):
        return Vetor(self.x * escalar, self.y * escalar)


v1 = Vetor(2,4)
v2 = Vetor(2,1)
print(v1, ' + ', v2,' = ', v1 + v2 )
print(v1, '*', '4 = ', v1.__mul__(4))
print(abs(v1))
