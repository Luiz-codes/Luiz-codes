#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

// Função para verificar se a string é um palíndromo
int eh_palindromo(char str[]) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        // Ignora caracteres não alfanuméricos
        if (!isalnum(str[i])) {
            i++;
        } else if (!isalnum(str[j])) {
            j--;
        } else {
            // Compara os caracteres, ignorando maiúsculas e minúsculas
            if (tolower(str[i]) != tolower(str[j])) {
                return 0; // Não é palíndromo
            }
            i++;
            j--;
        }
    }
    return 1; // É palíndromo
}

// Função para contar a frequência dos caracteres
void contar_frequencia(char str[]) {
    int freq[26] = {0};  // Array para armazenar a frequência de cada letra (a-z)

    // Contagem da frequência dos caracteres
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;  // Conta as letras, ignorando maiúsculas
        }
    }

    // Imprime a frequência dos caracteres
    printf("\nFrequência dos caracteres:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
}

int main() {
    char str[MAX];

    // Lê a string
    printf("Digite uma palavra ou frase: ");
    fgets(str, sizeof(str), stdin);

    // Verifica se a string é um palíndromo
    if (eh_palindromo(str)) {
        printf("\nA string é um palíndromo.\n");
    } else {
        printf("\nA string não é um palíndromo.\n");  // Corrigido: ponto e vírgula
    }

    // Conta a frequência dos caracteres
    contar_frequencia(str);

    return 0;
}

