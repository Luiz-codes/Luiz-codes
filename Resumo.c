#include<stdio.h>

int main (){
	char linha[100];
	
	printf("Digite um linha de texto: ");
	scanf("%[^\n]",linha);
	
	printf("\nVoce digitou: %s\n",linha);
	
	return(0);
}
