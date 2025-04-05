#include<stdio.h>

int main (){
	int numero, pares = 0 , impares = 0 ;
	
	printf("Informe o número de 0 a 10:\n");
	 int i;
	 for ( i = i; i<= 10;i++ ){
	 	printf ("%d:",i);
	 	scanf("%d:",&numero);
	 	
	 	if (numero % 2 == 0){
	 		pares++;
		 }  else {
		 	impares++;
		 }
	 }
	printf("\nResultado:\n");
	printf("Numeros pares :%d\n",pares);
	printf("Numeros impares:%d\n",impares);
	
	return 0;
}


