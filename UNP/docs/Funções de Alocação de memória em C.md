# Funções de Alocação de memória em C:

1. malloc()
   A função malloc() é usada para alocar um bloco de memória de tamanho especificado em bytes. Por exemplo, o seguinte código aloca um bloco de memória de 100 bytes:

```c
int *p; p = (int*) malloc(100);
```

2. calloc()
   A função calloc() é usada para alocar um bloco de memória de tamanho especificado em bytes, e inicializar todos os bytes do bloco para zero. Por exemplo, o seguinte código aloca um bloco de memória de 100 bytes e inicializa todos os bytes para zero:

```c
int *p; 
p = (int*) calloc(100, sizeof(int));
```

3. realloc()
   A função realloc() é usada para realocar um bloco de memória já alocado anteriormente. Isso pode ser necessário quando se precisa alterar o tamanho do bloco de memória alocado. Por exemplo, o seguinte código aumenta o tamanho do bloco de memória alocado para 200 bytes:

```c
int *p; 
p = (int*) malloc(100); 
p = (int*) realloc(p, 200);
```

4. free()
   A função free() é usada para liberar um bloco de memória previamente alocado. Isso é importante para evitar vazamentos de memória. Por exemplo, o seguinte código libera o bloco de memória alocado anteriormente:

```c
int *p; 
p = (int*) malloc(100); 
free(p);
```

É importante lembrar que todas essas funções lidam com alocar, realocar e liberar memória em tempo de execução, o que significa que a memória alocada será liberada somente quando o programa terminar sua execução ou quando a função free() for explicitamente chamada.
