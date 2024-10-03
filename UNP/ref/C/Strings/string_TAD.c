#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura string
typedef struct
{
    char *str; // Ponteiro para o conteúdo da string
} string;

// Protótipos das funções
string get_string();
int len_string(const string *s);
void copy_string(string *dest, const string *src);
void concat_string(string *dest, const string *src);
int compare_string(const string *str1, const string *str2);
int compare_string_custom(const string *str1, const string *str2); // Nova função
void free_string(string *s);

// Função para ler a string do usuário
string get_string()
{
    string s;
    s.str = NULL; // Inicializa o ponteiro como NULL

    char buffer[1000]; // Buffer temporário
    printf("Digite uma string: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove o caractere de nova linha
    buffer[strcspn(buffer, "\n")] = '\0';

    // Aloca memória para a string e copia do buffer
    s.str = malloc(strlen(buffer) + 1);
    if (s.str == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1); // Encerra o programa se houver falha na alocação
    }
    strcpy(s.str, buffer);

    return s;
}

// Função para calcular o tamanho da string (sem \0 e ENTER)
int len_string(const string *s)
{
    return strlen(s->str); // Não conta o '\0' automaticamente
}

// Função para copiar uma string para outra
void copy_string(string *dest, const string *src)
{
    if (dest->str != NULL)
    {
        free(dest->str); // Libera a memória antiga, se houver
    }
    dest->str = malloc(strlen(src->str) + 1); // Aloca memória para a nova string
    if (dest->str == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1); // Encerra o programa se houver falha na alocação
    }
    strcpy(dest->str, src->str); // Copia o conteúdo
}

// Função para concatenar strings
void concat_string(string *dest, const string *src)
{
    // Realoca para caber a string concatenada
    dest->str = realloc(dest->str, strlen(dest->str) + strlen(src->str) + 1);
    if (dest->str == NULL)
    {
        printf("Erro de realocação de memória!\n");
        exit(1); // Encerra o programa se houver falha na realocação
    }
    strcat(dest->str, src->str); // Concatena as strings
}

// Função para comparar duas strings de forma padrão
int compare_string(const string *str1, const string *str2)
{
    int result = strcmp(str1->str, str2->str);
    if (result < 0)
    {
        return -1;
    }
    else if (result > 0)
    {
        return 1;
    }
    return 0; // Iguais
}

// Função personalizada para comparar strings ignorando espaços
int compare_string_custom(const string *str1, const string *str2)
{
    const char *s1 = str1->str;
    const char *s2 = str2->str;

    while (*s1 != '\0' && *s2 != '\0')
    {
        // Ignora espaços em branco
        if (*s1 == ' ')
        {
            s1++;
            continue;
        }
        if (*s2 == ' ')
        {
            s2++;
            continue;
        }

        // Compara os caracteres (sensível a maiúsculas/minúsculas)
        if (*s1 < *s2)
        {
            return -1;
        }
        else if (*s1 > *s2)
        {
            return 1;
        }
        s1++;
        s2++;
    }

    // Verifica o final das strings (ignora espaços em branco)
    while (*s1 == ' ')
        s1++;
    while (*s2 == ' ')
        s2++;

    if (*s1 == '\0' && *s2 == '\0')
    {
        return 0; // Iguais
    }
    else if (*s1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// Função para liberar memória da string
void free_string(string *s)
{
    if (s->str != NULL)
    {
        free(s->str);
        s->str = NULL;
    }
}

// Exemplo de uso das funções
int main()
{
    string s1 = get_string();
    string s2 = get_string();

    printf("Tamanho de s1: %d\n", len_string(&s1));
    printf("Tamanho de s2: %d\n", len_string(&s2));

    string s3;
    s3.str = NULL; // Inicializa s3 com NULL para evitar problemas de realocação
    copy_string(&s3, &s1);
    printf("s3 (cópia de s1): %s\n", s3.str);

    concat_string(&s3, &s2);
    printf("s3 após concatenação: %s\n", s3.str);

    // Comparação personalizada ignorando espaços
    int cmp = compare_string_custom(&s1, &s2);
    if (cmp == 0)
    {
        printf("s1 e s2 são iguais\n");
    }
    else if (cmp < 0)
    {
        printf("s1 é menor que s2\n");
    }
    else
    {
        printf("s1 é maior que s2\n");
    }

    // Libera memória das strings
    free_string(&s1);
    free_string(&s2);
    free_string(&s3);

    return 0;
}
