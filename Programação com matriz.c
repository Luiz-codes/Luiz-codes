#include<stdio.h>

#define HORAS 10 

int main(){
    float tensao[HORAS], corrente[HORAS], potencia[HORAS];
    float somaTensao = 0, somaCorrente = 0, somaPotencia = 0;
    int i, horaMaiorPotencia = 0;
    
    printf("Resgistro de medidas de um circuito de corrente contínua\n");
    // leitura das medidas
    for(i = 0; i < HORAS; i++){
       printf("\nHora %d:\n",i + 1);
        printf("Digite a tensão (V): ");
        scanf("%f",&tensao[i]);
        
        printf("Digite a corrente (A): ");
        scanf("%f", &corrente[i]);
        
        //Cálculo da potência
        potencia[i] = tensao[i] * corrente[i];
        //Acumula para média 
        somaTensao += tensao[i];
        somaCorrente += corrente[i];
        somaPotencia += potencia[i];
        //Verificar maior potência 
        if (potencia[i] > potencia[horaMaiorPotencia] ){
            horaMaiorPotencia = i;
        }
    }
    //Resultado 
    printf("\n---- RESULTADO ----\n");
    printf("1) Hora com maior potência: %dª hora(potência = %.2F W)\n", horaMaiorPotencia + 1, potencia[horaMaiorPotencia]);
    printf("2) Médias no dia:\n");
    printf(" Tensão médias: %.2f V\n", somaTensao / HORAS);
    printf(" Corente média: %.2f A\n",  somaCorrente /  HORAS);
    printf(" Potência média: %.2f W\n", somaPotencia / HORAS);
    
    return 0;
}	
