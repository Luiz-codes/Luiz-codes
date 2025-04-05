#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

// Fun��o para verificar se a string � um pal�ndromo
int eh_palindromo(char str[]) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        // Ignora caracteres n�o alfanum�ricos
        if (!isalnum(str[i])) {
            i++;
        } else if (!isalnum(str[j])) {
            j--;
        } else {
            // Compara os caracteres, ignorando mai�sculas e min�sculas
            if (tolower(str[i]) != tolower(str[j])) {
                return 0; // N�o � pal�ndromo
            }
            i++;
            j--;
        }
    }
    return 1; // � pal�ndromo
}

// Fun��o para contar a frequ�ncia dos caracteres
void contar_frequencia(char str[]) {
    int freq[26] = {0};  // Array para armazenar a frequ�ncia de cada letra (a-z)

    // Contagem da frequ�ncia dos caracteres
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;  // Conta as letras, ignorando mai�sculas
        }
    }

    // Imprime a frequ�ncia dos caracteres
    printf("\nFrequ�ncia dos caracteres:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
}

int main() {
    char str[MAX];

    // L� a string
    printf("Digite uma palavra ou frase: ");
    fgets(str, sizeof(str), stdin);

    // Verifica se a string � um pal�ndromo
    if (eh_palindromo(str)) {
        printf("\nA string � um pal�ndromo.\n");
    } else {
        printf("\nA string n�o � um pal�ndromo.\n");  // Corrigido: ponto e v�rgula
    }

    // Conta a frequ�ncia dos caracteres
    contar_frequencia(str);

    return 0;
}

