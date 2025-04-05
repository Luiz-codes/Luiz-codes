#include <stdio.h>
#include <math.h>

int main (){
	int num, i ;
	int primo = 1 ;
	
	printf ("Digite um numero: ");
	scanf("%d",&num);
	
	if (num<= 1 ){
		primo = 0;
	}
	for (i = 2 ;i<= sqrt(num);i++){
		if(num % i == 0){
			primo = 0;
			break;
			
		}
	}
	
	if (primo){
		printf("O numero %d e primo.\n",num);	
	} else {
		printf("O numero %d nao e primo",num);
	}
	return 0;
}
