#include <stdio.h>

int main(){
	int numero;
	
	printf("Digite um numero para ver sua tabuada:\n");
	scanf("%d",&numero);
	
	printf ("\nTabuada de %d:\n",numero);
	
	int i;
	for (i=1; i<=10;i++){
		printf ("%d x %d =%d\n",numero,i,numero*i);
	}
	
	return 0;
}
