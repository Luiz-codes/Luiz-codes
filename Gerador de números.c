#include <stdio.h>

int soma_quadrados_digitos(int n){
	int soma = 0;
	while (n > 0){
		int dig = n % 10;
		soma += dig* dig;
		n /= 10;
	}
	return soma;
}
int eh_feliz(int n ){
	int lento = n;
	int rapido = n;
	
	do{// Usa algoritmo de Floyd (tartaruga e lebre) para detectar ciclos
		lento = soma_quadrados_digitos(lento);
		rapido = soma_quadrados_digitos(soma_quadrados(rapido));	
	} while (lento != rapido);
	
	return lento == 1;
}
int main(){
	int n, contador = 0, atual = 1;
	
	printf("Digite quantos numeros felizes voce quer ver: ");
	scanf("%d",&n);
	
	printf("Primeiros %d numeros felizes:\n",n);
	while(contador < n){
		if(eh_feliz(atual)){
			printf("%d",atual);
			contador++;
		}
		atual++;
	}
	
	printf("\n");
	return 0;
}
