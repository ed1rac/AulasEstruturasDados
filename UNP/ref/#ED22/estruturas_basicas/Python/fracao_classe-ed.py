class fracao(object):

    def __init__(self, num, den):
        self.num = num
        self.den = den                

    def somar_fracao(self, b):
        f = fracao(self.num*b.den + b.num*self.den, self.den*b.den)
        #f.num = 
        #f.den = 
        fracao.simplificar_fracao(f)
        return f

    def subtrair_fracao(self, b):
        pass

    def multiplicar_fracao(self, b):
        pass

    def dividir_fracao(self, b):
        pass

    def simplifica_fracao(self):
        m = fracao.mdc(self.num, self.den)
        self.num=self.num/m
        self.den=self.den/m
        print('Resultado: ', self.num, ' / ' , self.den)
        #input()
        return

    @staticmethod
    def simplificar_fracao(self):
        m = fracao.mdc(self.num, self.den)
        self.num=self.num/m
        self.den=self.den/m
        print('Resultado: ', self.num, ' / ' , self.den)
        input()
        return

    def exibir_fracao(self):
        print(self.num, ' / ' , self.den)
        return

    @staticmethod
    def mdc(a,b):
        if a<b:
            return fracao.mdc(b,a)
        else:
            if b==0:
                return a
            else:
                return fracao.mdc(b, a % b)



a = fracao(2,3)
b = fracao(3,4)
c = fracao(12,24)
c.simplifica_fracao()
a.exibir_fracao()
b.exibir_fracao()
c.exibir_fracao()
c = a.somar_fracao(b)
c.exibir_fracao()
d = a.somar_fracao(fracao(1,3))
