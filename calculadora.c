#include <stdio.h>
#include <math.h> // Para usar pow()

int main() {
    double num1, num2, resultado;
    int opcao;

    printf("=== Calculadora Simples ===\n");
    printf("Escolha a operacao:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Exponenciacao\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("Digite o primeiro numero: ");
    scanf("%lf", &num1);
    printf("Digite o segundo numero: ");
    scanf("%lf", &num2);

    switch(opcao) {
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 4:
            if(num2 != 0)
                resultado = num1 / num2;
            else {
                printf("Erro: divisao por zero!\n");
                return 1;
            }
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 5:
            resultado = pow(num1, num2);
            printf("Resultado: %.2lf\n", resultado);
            break;
        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
