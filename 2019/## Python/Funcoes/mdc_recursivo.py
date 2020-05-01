def mdc(a,b):
        if a<b:
            return mdc(b,a)
        else:
            if b==0:
                return a
            else:
                return mdc(b, a % b)



print(mdc(12,8))
print(mdc(12,10))
