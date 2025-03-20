#include <stdio.h>
int main ()
{
	char str[10]="Joao";
	printf("\n\nString: %s",str);
	printf("Segunda letra:%c", str[1]);
	str[1] ='O';
	printf("\nAgora a segunda letra eh: ");
	printf("\n\String:%s",str);
	return(0);
	
}
