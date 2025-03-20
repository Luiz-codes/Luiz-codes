#include<stdio.h>
void square(int x ) /*Calcula o quadrado de x*/
{
  printf("O quadrado e %d",(x*x));
}
void main()
{
	int num; 
	printf("Entre com um numero: ");
	scanf("%d",&num);
	printf("\n\n");
	square(num);
	}	
