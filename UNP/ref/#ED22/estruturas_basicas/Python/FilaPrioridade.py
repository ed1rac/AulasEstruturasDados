class FilaPrioridades:
    def __init__(self):
        '''Inicializa a fila de prioridade.'''        
        self.items = []

    def is_empty(self):
        '''Verifica se a fila está vazia.'''        
        return len(self.items) == 0
        

    def enqueue(self, item, priority):
        self.items.append((item, priority))
        self.items.sort(key=lambda x: x[1])

    def dequeue(self):
        if self.is_empty():
            return None
        return self.items.pop(0)

    def size(self):
        return len(self.items)
    
    def imprime(self):
        if self.is_empty():
            print('Fila vazia!')
            print('')          
        else:
            print('Imprimindo a fila de prioridades:')
            print(self.items)
            for i in range(self.size()):
                print(f'Item: {self.items[i][0]} - Prioridade: {self.items[i][1]}')
            print('')

            



fila_p = FilaPrioridades()

fila_p.enqueue("Tarefa 1", 3)
fila_p.enqueue("Tarefa 2", 1)
fila_p.enqueue("Tarefa 3", 2)
fila_p.enqueue("Tarefa 4", 1)

fila_p.imprime()
print(fila_p.size())  # Output: 4

print(fila_p.dequeue())  # Output: ("Tarefa 2", 1)
print(fila_p.dequeue())  # Output: ("Tarefa 3", 2)

print(fila_p.size())  # Output: 2
