#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificar_palindromo(char palavra []){
    int inicio = 0, fim = strlen(palavra) - 1;
    
    while(inicio < fim){
        while(inicio < fim && !isalnum(palavra[inicio])){
            inicio++;
        }
        while(inicio < fim && isalnum(palavra[fim])){
            fim--;
        }
        
        if(tolower(palavra[inicio]) != tolower(palavra[fim])){
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
           
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra: ");
    fgets(palavra, 100, stdin);
    
    palavra[strcspn(palavra, "\n")] = '\0';
    
    if (verificar_palindromo(palavra)){
        printf("A palavra '%s' é um palíndromo!\n",palavra);
    } else{
        printf("A palvra '%s'não é um palindormo.\n",palavra);
    }
    return 0;
}
