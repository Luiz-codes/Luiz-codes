#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 5
#define TAMANHO_PALAVRA 20

int main() {
    char palavra_secreta[TAMANHO_PALAVRA] = "computador";
    char letras_chutadas[26];
    int tentativas = 0;
    int letras_corretas = 0;
    int i;
    char chute;
    int tamanho = strlen(palavra_secreta);
    int acertou;

    for (i = 0; i < 26; i++)
        letras_chutadas[i] = 0;

    while (tentativas < MAX_TENTATIVAS && letras_corretas < tamanho) {
        acertou = 0;

        printf("\nPalavra: ");
        for (i = 0; i < tamanho; i++) {
            if (letras_chutadas[tolower(palavra_secreta[i]) - 'a'])
                printf("%c ", palavra_secreta[i]);
            else
                printf("_ ");
        }

        printf("\nChute uma letra: ");
        scanf(" %c", &chute);
        chute = tolower(chute);

        if (letras_chutadas[chute - 'a']) {
            printf("Você ja tentou essa letra.\n");
            continue;
        }

        letras_chutadas[chute - 'a'] = 1;

        for (i = 0; i < tamanho; i++) {
            if (palavra_secreta[i] == chute) {
                acertou = 1;
                letras_corretas++;
            }
        }

        if (!acertou) {
            tentativas++;
            printf("Letra incorreta! Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        } else {
            printf("Boa! Voce acertou uma letra!\n");
        }
    }

    if (letras_corretas == tamanho)
        printf("\nParabens! Você acertou a palavra: %s\n", palavra_secreta);
    else
        printf("\nVocê perdeu! A palavra era: %s\n", palavra_secreta);

    return 0;
}

