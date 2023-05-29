# Lista usando arrays tanto em C como em Java

Em C e Java, é possível implementar uma lista usando vetores (arrays).Exemplos de implementações simples em cada linguagem:

Implementação de lista usando vetor em C:

```c
#include <stdio.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int size = 0;

void insert(int value, int index) {
    if (index < 0 || index > size) {
        printf("Error: Index out of bounds\n");
        return;
    }
    if (size == MAX_SIZE) {
        printf("Error: List is full\n");
        return;
    }
    for (int i = size; i > index; i--) {
        list[i] = list[i-1];
    }
    list[index] = value;
    size++;
}

void remove_at(int index) {
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds\n");
        return;
    }
    for (int i = index; i < size-1; i++) {
        list[i] = list[i+1];
    }
    size--;
}

int get(int index) {
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds\n");
        return -1;
    }
    return list[index];
}

int main() {
    insert(10, 0);
    insert(20, 1);
    insert(30, 2);
    printf("%d\n", get(1));
    remove_at(1);
    printf("%d\n", get(1));
    return 0;
}
```

Neste exemplo, a lista é representada por um vetor `list` de tamanho fixo `MAX_SIZE` e uma variável `size` que rastreia o número de elementos na lista.

As funções `insert()`, `remove_at()` e `get()` são usadas para inserir, remover e acessar elementos da lista em um índice específico.

O método `main()` é usado para criar a lista, inserir elementos, acessar elementos e remover elementos da lista.

Implementação de lista usando vetor em Java:

```java
public class List {
    int[] list;
    int size;

    public List(int maxSize) {
        list = new int[maxSize];
        size = 0;
    }

    public void insert(int value, int index) {
        if (index < 0 || index > size) {
            System.out.println("Error: Index out of bounds");
            return;
        }
        if (size == list.length) {
            System.out.println("Error: List is full");
            return;
        }
        for (int i = size; i > index; i--) {
            list[i] = list[i-1];
        }
        list[index] = value;
        size++;
    }

    public void removeAt(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Error: Index out of bounds");
            return;
        }
        for (int i = index; i < size-1; i++) {
            list[i] = list[i+1];
        }
        size--;
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Error: Index out of bounds");
            return -1;
        }
        return list[index];
    }

    public static void main(String[] args) {
        List list = new List(100);
        list.insert(10, 0);
        list.insert(20, 1);
        list.insert(30, 2);
        System.out.println(list.get(
```
