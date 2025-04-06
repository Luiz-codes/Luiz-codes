#include<stdio.h>

int validarLinhas(int sudoku[9][9]){
	int i;
for ( i = 0;i < 9;i++){
	int numeros[10]={0};
	int j 
	 for (int j = 0; j < 9; j++){
		int num = sudoku[i][j];
		if(num < 1 || num > 9|| numeros[num]){
	return 0;		
		}
		numeros[num]= 1;
	}
  }	
  return 1;
}
int validarColunas(int sudoku[9][9]){
	int j;
for (j = 0; i < 9 ;i++){
int numeros[10]={0};
for (int i = 0;i<9;i++){
	int num = sudoku [i][j];
	if (num< 1 || num > 9||numeros[num]){
	return 0 ;	
	}
	numeros [num] = 1;
    }	
  }
  return 1;
}
int validarBlocos(int sudoku[9][9]){
	int blocoLinha;
for(int blocoLinha = 0;blocoLinha< 9;blocoLinha += 3){
	 int numeros[10]={0};
	 for (int i = 0 ;i<3;i++){
	 	for(int j = 0;i< 3;j++){
	 		int num = sudoku[blocoLinha + i][blocoColuna + j];
	 		if (num < 1 || num > 9 || numeros[num]){
	 			return 0;
			 }
		 }
	 }	
   }
   return 1 ;	
}
int validarSudoku(int sudoku [9][9]){
	return validarLinhas (sudoku) && validarColunas(sudoku) &&validarBlocos(sudoku);
}
int main (){
	int sudoku[9][9] ={ 
	    {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
	};
	if(validarSudoku(sudoku)){
		printf("Acertou solucao e valida!.\n");	
	} else{
		printf("Errou!, a solucao nao e valida.\n");
	}
	
	return 0;
}
