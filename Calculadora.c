#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double num1, num2,resultado;
	int opcao;
	
	printf("=== Calculadora ====\n");
	printf("Escolha alguma das opcoes a abaixo:\n");
	printf("1 - Adicao:\n");
	printf("2 - Subtracao:\n");
	printf("3 - Multiplicação:\n");
	printf("4 - Divisão:\n");
	printf("5 - Exponencial:\n");
	printf("6 - Sair:\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	
	if(opcao == 6){
	printf("Saindo....\n");
	return 0;
   }
	
	if (opcao >= 1 && opcao <= 5)  {
		printf("Digite o primeiro numero: ");
		scanf("%f",&num1);
		printf("Digite o segundo numero: ");
		scanf("%f",&num2);
	}
	switch(opcao){
    case 1:
	resultado = num1 + num2;
		printf("Resultado: %.2lf",resultado);
		break;
	case 2:
		resultado = num1 - num2;
		printf("Resultado: %.2lf",resultado);
		break;
	case 3:
	    resultado =	num1 * num2;
	    printf("Resultado: %2.lf",resultado);
	    break;
	case 4:
	     if(num2 != 0){
	     	resultado = num1 / num2;
	     	printf("Resultado: %2lf",resultado);
		 } else {
		 	printf("ERRO: divisao por zero!");
		 } 
		 break;
	case 5: 
	   resultado = pow(num1, num2);
	   printf("Resultado: %2lf",resultado);
	   break;
	default:
	   printf("Opcao invalida!\n");
	   break;   	    
	}
	
	return 0;
}
