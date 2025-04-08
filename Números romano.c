#include <stdio.h>

void decimalParaRomano(int numero){
    int valores[]= {1000, 900, 500, 400, 100, 90,  50, 40, 10, 9, 5, 4, 1};
    char *romanos[]= {"M",  "CM","D", "CD","C", "XC","L","XL","X","IX","V","IV","I"};
    
    printf("Número Romano:");
    for(int i = 0; i < 13; i++) {
        while (numero >= valores[i]) {
            printf("%s",romanos[i]);
            numero -= valores[i];
        }
    }
    printf("\n");
}

int main(){
    int numero;
    printf("Digite um número entre 1 e 3999.\n");
    scanf("%d", &numero);
    
    if(numero < 1 || numero > 3999){
        printf("Número inválido! Tente entre 1 e 3999.\n");
    } else {
        decimalParaRomano(numero);
    }
    
    return 0;
}
