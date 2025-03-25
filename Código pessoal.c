#include <stdio.h>
int main ()
{
	int num;
	printf("Digite um numero: ");
	scanf("%d",&num);
	if(num==20)
	{
		printf("\n\nVoce acertou!\n");
		printf("\n\n\O numero e igual a 20.\n");
	}
	else
	{
		printf("\n\nVoce errou!\n");
		printf("O numero é difrente de 20.\n");
	}
	return(0);
}
