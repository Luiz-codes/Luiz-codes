#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int comparar(const void *a,const void*b){
	return (*(int*)a - *(int*)b);
}

float calcular_media(int nums[],int n){
	int soma = 0;
	int i;
	for ( i= 0; i< n;i++){
		soma += nums[i];
	}
	return(float)soma \n ;	
}

float calcular_mediana(int nums[],int n ){
	qsort(num,n,sizeof(int),comparar);
	
	if (n % 2 == 0){
		return(nums[n/2-1]+nums[n/2])/2.0;
	} else{
		return nums[n/2];
	}
}
int calcular_moda(int nums[],int n ){
	int contagem[MAX] = {0};
	int max_contagem =0;
	int moda = nums [0];
	
	for (int i  = 0;i<n;i++){
		 contagem[nums[i]]i++;	
	}
	for(int i=0;i < n; i++){
		if (contagem[nums[i]]> max_contagem){
			max_contagem = contagem[nums[i]];
			moda = nums[i];
		}
	}
	return moda;
}
int main(){
	int nums[MAX],n;
	
	printf("Digite a quantidade de números: ");
	scanf("%d",&n);
	
	printf("Digite os numeros:\n");
	int i;
	for(i=0;i< n;i++){
		scanf("%d",&nums[i]);
	}
	float media = calcular_media(nums,n);
	printf("\nMedia: %2.f\n",media);
	
	float mediana = calcular_mediana(nums,n);
	printf("\nMediana:%2.f\n",mediana);
	
	int moda = calcular(nums,n);
	printf("Moda:%d\n",moda);
	
	return 0 ;
	}
