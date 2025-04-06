#include<stdio.h>

#define LINHAS 5 
#define COLUNAS 5

void afundarIlha(int mapa[LINHAS][COLUNAS],int i,int j){
	 if (i< 0 || i>= LINHAS|| J >=COLUNAS||mapa[i][j] == 0){
	 	return;
	 }
	 
	 mapa[i][j] = 0;
	 
	 afundarIlha(mapa, i + 1, j);
	 afundarIlha(mapa, i- 1, j);
	 afundarIlha(mapa, i,j + 1);
	 afundarIlha(mapa,i j - 1);
}

int contarIlhas(int mapa [LINHAS][COLUNAS])
   int i ,j;
   int contador = 0;
   
   for(i=0; i< LINHAS; i++){
   	for(j = 0; j < COLUNAS;j++){
   		for(j= 0; j < COLUNAS;j++){
   			if (mapa[i][j] == 1 ){
   				contador++;
   				afundarIlha(mapa,i ,j);
			   }
		   }
	   }
	   
	   return contador;
   }
   int main(){
   	int mapa[LINHAS][COLUNAS] = {
	    {1, 1, 0, 0, 0},
	    {1, 1, 0, 0, 1},
		{0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}
		};
		int total = contraIlhas(mapa);
		printf("Numeros de ilhas: %d\n",total);
		
		return 0;
}
   
