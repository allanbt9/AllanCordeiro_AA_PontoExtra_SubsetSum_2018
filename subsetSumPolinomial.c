#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Autor -Allan Cordeiro Rocha de Araújo
Disciplina - Análise de Algoritmo
Instituição - Universidade Federal de Roraima
*/

/*
Este algoritmo é para resolver o problema a soma de subconjuntos (Subset sum)
em tempo polinomial

Usa-se a técnica de programação dinâmica
*/


int subsetSum(int *p,int n,int c){
	int i,b;
	int t[n][c]; // matriz para armazenar os resultados

	for(i=0;i<n;i++)
		t[i][0] = 1;

	for(b=1;b<c;b++){
		t[0][b] = 0;

		for(i=1;i<n;i++){
			int s = t[i-1][b];
			if(s == 0 && p[i] <= b)
				s = t[i-1][b-p[i]];

			t[i][b] = s;
		}
	}

	return t[n-1][c-1];//o resultado ficará na ultima linha e ultima coluna da matriz
}



int main(){
	int p[] = {30,40,10,15,10,60,54};

	
	printf("result: %d",subsetSum(p,7,55));
	//achar o valor 55 em algum subconjunto de p[]
	//retorna 1 caso exista, ou 0 caso não exista
	//serve para qualquer valor em qualquer conjunto

	return 0;

}
