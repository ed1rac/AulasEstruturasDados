class Stack :
  def __init__(self) :
    self.items = []

  def push(self, item) :
    self.items.append(item)

  def pop(self) :
    return self.items.pop()

  def isEmpty(self) :
    return (self.items == [])



s = Stack()
s.push(45)
s.push(54)
s.push('+')
while not s.isEmpty() :
    print(s.pop())