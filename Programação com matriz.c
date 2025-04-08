#include<stdio.h>

#define HORAS 10 

int main(){
    float tensao[HORAS], corrente[HORAS], potencia[HORAS];
    float somaTensao = 0, somaCorrente = 0, somaPotencia = 0;
    int i, horaMaiorPotencia = 0;
    
    printf("Resgistro de medidas de um circuito de corrente cont�nua\n");
    // leitura das medidas
    for(i = 0; i < HORAS; i++){
       printf("\nHora %d:\n",i + 1);
        printf("Digite a tens�o (V): ");
        scanf("%f",&tensao[i]);
        
        printf("Digite a corrente (A): ");
        scanf("%f", &corrente[i]);
        
        //C�lculo da pot�ncia
        potencia[i] = tensao[i] * corrente[i];
        //Acumula para m�dia 
        somaTensao += tensao[i];
        somaCorrente += corrente[i];
        somaPotencia += potencia[i];
        //Verificar maior pot�ncia 
        if (potencia[i] > potencia[horaMaiorPotencia] ){
            horaMaiorPotencia = i;
        }
    }
    //Resultado 
    printf("\n---- RESULTADO ----\n");
    printf("1) Hora com maior pot�ncia: %d� hora(pot�ncia = %.2F W)\n", horaMaiorPotencia + 1, potencia[horaMaiorPotencia]);
    printf("2) M�dias no dia:\n");
    printf(" Tens�o m�dias: %.2f V\n", somaTensao / HORAS);
    printf(" Corente m�dia: %.2f A\n",  somaCorrente /  HORAS);
    printf(" Pot�ncia m�dia: %.2f W\n", somaPotencia / HORAS);
    
    return 0;
}	
