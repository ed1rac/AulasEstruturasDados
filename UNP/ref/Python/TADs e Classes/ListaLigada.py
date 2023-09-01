# Lista Singularmente encadeada
''' 
         cabeça        segundo              terceiro 
         |                |                  | 
         |                |                  | 
    +----+------+     +----+------+     +----+------+ 
    | 1  |  o-------->| 2  |  o-------->|  3 | null | 
    +----+------+     +----+------+     +----+------+  
'''
# Classe Node para uma lista encadeada
class Node:

    # Construtor para criar um novo nó
    def __init__(self, data):
        self.data = data # Ponteiro para o dado (a informação)
        self.next = None # Inicializar próximo como nulo (None)

# A classe Linked List contém um nó
class LinkedList:

    # Construtor para lista encadeada vazia
    def __init__(self):
        self.head = None

    # Uma referência à cabeça,
    # acrescenta um novo nó
    def append(self, data):

        # Cria um novo nó com os dados fornecidos
        new_node = Node(data)

        # Se a lista está vazia
        # cria o novo nó como a cabeça da lista 
        if self.head == None:
            self.head = new_node
            return
        
        current_node = self.head

        # Agora atravesse até o novo nó
        while current_node.next:
            current_node = current_node.next

        # Alterar o próximo do nó atual  
        current_node.next = new_node
        return
    
    # Retorna o comprimento da lista encadeada.
    def length(self):
        if self.head == None:
            return 0
        current_node = self.head
        total = 0 # Inicia o contador
        # Itera enquanto o fim da lista não é alcançado
        while current_node:
            total += 1
            current_node = current_node.next
        return total

    # Converte a lista encadeada de volta em uma lista Python
    def to_list(self):

        # Inicializa como null
        node_data = []
        current_node = self.head

        while current_node:
            node_data.append(current_node.data)
            current_node = current_node.next
        return node_data
    # Retorna o valor do nó em 'index'. 
    def get(self, index):
        if index >= self.length() or index < 0:
            print("ERROR: 'Get' Index out of range!")
            return None
        current_idx  = 0
        current_node = self.head
        while current_node != None:
            if current_idx == index: 
                return current_node.data
            current_node  = current_node.next
            current_idx += 1
    # inverter a lista encadeada
    def reverse_linkedlist(self):
        previous_node = None
        current_node = self.head
        while current_node != None:
            next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = next
        self.head = previous_node
    
    # Procurar um elemento é muito parecido a contar ou percorrer uma lista encadeada
    def search_item(self, value):
        if self.head == None:
            print("List has no elements")
            return
        current_node = self.head
        while current_node != None:
            if current_node.data == value:
                print("Item found")
                return True
            current_node = current_node.next
        print("Item not found")
        return False


    # Esta função imprime o conteúdo da lista encadeada
    # a partir do início da lista encadeada
    
    def display(self): 
        contents = self.head 
        # Se a lista está vazia
        if contents is None:
            print("Lista não tem elementos")
        while contents: 
            print(contents.data)
            contents = contents.next
        print("----------") # para ver melhor as listas

    # Excluindo um elemento ou item do início
    def remove_at_start(self):
        if self.head == None:
            print("A lista não tem nenhum elemento para apagar")
            return 
        self.head = self.head.next
    
    # Excluindo um elemento ou item no fim
    def remove_at_end(self):
        if self.head is None:
            print("A lista não tem nenhum elemento para apagar")
            return
        current_node = self.head
        while current_node.next.next != None:
            current_node = current_node.next
        current_node.next = None

    # Excluindo um elemento ou item de determinado valor
    def remove_element_by_value(self, value):
        # Store head node  
        current_node = self.head  
  
        # Se o próprio nó principal contém o valor a ser excluído
        if current_node != None:  
            if current_node.data == value:  
                self.head = current_node.next
                current_node = None
                return
  
        # Pesquisa o valor a ser excluído, acompanha o
        # nó anterior, pois precisamos alterar 'prev.next' 
        while current_node != None:  
            if current_node.data == value:  
                break
            prev = current_node  
            current_node = current_node.next
  
        # se o valor não estiver presente na lista encadeada
        if current_node == None:  
            return
  
        # Desvincular o nó da lista
        prev.next = current_node.next
        current_node = None
    
    # Insere um item em uma lista encadeada
    # adiciona um item no início da lista
    def insert_at_start(self, data):
        new_node        = Node(data)
        new_node.next   = self.head
        self.head = new_node

    # Insere um item em uma lista encadeada
    # adiciona um item no final da lista
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next
        current_node.next = new_node

    # Insere um item em uma lista encadeada
    # adiciona um item no índice específico de uma lista
    def insert_at_index (self, index, data):
        if index == 1:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
        i = 1
        current_node = self.head
        while i < index-1 and current_node is not None:
            current_node = current_node.next
            i = i + 1
        if current_node is None:
            print("ERROR: Index out of range!")
        else: 
            new_node = Node(data)
            new_node.next = current_node.next 
            current_node.next  = new_node
	
# Testando  
my_list = LinkedList()
my_list.display()
# Adicionando elementos
my_list.append(3)
my_list.append(2)
my_list.append(7)
my_list.append(1)

my_list.display()

print("O número total de elementos é: " + str(my_list.length()))
print(my_list.to_list()) # Python list
print("---------")
my_list.reverse_linkedlist() # lista encadeada reversa
my_list.display()

my_list.search_item(7)
my_list.search_item(77)

my_list.remove_at_start()
my_list.display()

my_list.remove_at_end()
my_list.display()

my_list.insert_at_start(1)
my_list.display()

my_list.insert_at_end(3)
my_list.display()

my_list.remove_element_by_value(3)
my_list.display()

my_list.insert_at_index(2, 88)
my_list.display()