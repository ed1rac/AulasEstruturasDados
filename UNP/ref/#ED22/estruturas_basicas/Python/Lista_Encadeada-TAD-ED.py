class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head == None

    def add_node(self, value):
        new_node = Node(value)
        if self.is_empty():
            self.head = new_node
        else:
            current_node = self.head
            while current_node.next != None:
                current_node = current_node.next
            current_node.next = new_node

    def remove_node(self, value):
        if self.is_empty():
            return
        if self.head.value == value:
            self.head = self.head.next
            return
        current_node = self.head
        while current_node.next != None:
            if current_node.next.value == value:
                current_node.next = current_node.next.next
                return
            current_node = current_node.next

    def print_list(self):
        print('\nImprimindo a lista', end='\n')
        current_node = self.head
        while current_node != None:
            print(current_node.value)
            current_node = current_node.next


# Criando a lista encadeada
ll = LinkedList()

# Adicionando valores à lista
ll.add_node(10)
ll.add_node(20)
ll.add_node(30)
ll.print_list()

# Removendo um valor da lista
ll.remove_node(20)

# Imprimindo os valores da lista
ll.print_list()  # Output: 10, 30
