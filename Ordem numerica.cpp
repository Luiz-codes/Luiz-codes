#include <stdio.h>

void ordenar(int vetor[], int tamanho){
    int i, j, temp;
    
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
        if (vetor[j] > vetor[j + 1]){
            
            temp = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = temp;
        }
     }
   }
 }

int main(){
    int numeros[10];
    int soma = 0, maior, menor;
    
    for(int i = 0;i < 10; i++){
        printf("Digite o %d� n�mero: ", i + 1);
        scanf("%d",&numeros[i]);
    }
    
    printf("\nN�meros inseridos: ");
    for(int i = 0; i < 10; i++){
        printf("%d", numeros[i]);
    }
    
    maior = numeros[0];
    menor = numeros[0];
    
    for(int i = 0; i < 10; i++){
        soma += numeros[i];
        if (numeros[i] > maior){
            maior = numeros[i];
        }
        if(numeros [i] < menor){
            menor = numeros[i];
        }
    }
    printf("\nSoma dos n�meros: %d",soma);
    printf("\nMaior n�meros: %d",maior);
    printf("\nMenor n�meros: %d",menor);
    
    
    ordenar(numeros, 10);
    printf("\nN�meros em ordem cresente: ");
    for(int i = 0; i < 10; i++){
        printf("%d",numeros[i]);
    }
    return 0;
}
