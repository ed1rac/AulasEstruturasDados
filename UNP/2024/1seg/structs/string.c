#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do TAD String
typedef struct
{
    char *data;
    int length;
} String;

// Funções do TAD String
String criarString(const char *valor);
String lerString(char *prompt);
void exibirString(String str);
int compararStrings(String str1, String str2);
String concatenarStrings(String str1, String str2);
String copiarString(String str);
int strTamanho(String str);
char obterCaractere(String str, int indice);
void definirCaractere(String *str, int indice, char caractere);
void destruirString(String *str);

// Função auxiliar para alocar memória para uma string char *alocarMemoriaString(int tamanho)
char *alocarMemoriaString(int tamanho)
{
    char *str = (char *)malloc((tamanho + 1) * sizeof(char)); // +1 para o caractere nulo
    if (str == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return str;
}

// Função para criar uma string a partir de uma sequência de caracteres
String criarString(const char *valor)
{
    String str;
    str.length = strlen(valor);
    str.data = alocarMemoriaString(str.length);
    strcpy(str.data, valor);
    return str;
}

// Função para destruir uma string e liberar sua memória
void destruirString(String *str)
{
    free(str->data);
    str->length = 0;
}

// Função para exibir uma string
void exibirString(String str)
{
    printf("%s\n", str.data);
}

// Função para ler uma string do console
// Retorna a string lida após um prompt exibido
String lerString(char *prompt)
{
    char buffer[100]; // Tamanho máximo da string lida
    printf("%s", prompt);
    fgets(buffer, 99, stdin); // Lê até 99 caracteres para evitar estouro do buffer
    return criarString(buffer);
}

// Função para concatenar duas strings
String concatenarStrings(String str1, String str2)
{
    String resultado;
    resultado.length = str1.length + str2.length;
    resultado.data = alocarMemoriaString(resultado.length);
    strcpy(resultado.data, str1.data);
    strcat(resultado.data, str2.data);
    return resultado;
}

// Função para copiar uma string
String copiarString(String str)
{
    String copia;
    copia.length = str.length;
    copia.data = alocarMemoriaString(copia.length);
    strcpy(copia.data, str.data);
    return copia;
}

// Função para comparar duas strings
int compararStrings(String str1, String str2)
{
    return strcmp(str1.data, str2.data);
}

int strTamanho(String str)
{
    return str.length;
}

// Função para obter um caractere em um índice específico da string
char obterCaractere(String str, int indice)
{
    if (indice < 0 || indice >= str.length)
    {
        printf("Índice fora dos limites da string.\n");
        exit(1);
    }
    return str.data[indice];
}

// Função para definir um caractere em um índice específico da string
void definirCaractere(String *str, int indice, char caractere)
{
    if (indice < 0 || indice >= str->length)
    {
        printf("Índice fora dos limites da string.\n");
        exit(EXIT_FAILURE);
    }
    str->data[indice] = caractere;
}

int main()
{
    String str = lerString("Digite alguma string: ");
    printf("String lida: ");
    exibirString(str);
    printf("De tamanho: %d\n", strTamanho(str));
    destruirString(&str);
    return 0;
}