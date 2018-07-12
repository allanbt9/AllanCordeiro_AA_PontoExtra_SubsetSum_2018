#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Autor -Allan Cordeiro Rocha de Araújo
Disciplina - Análise de Algoritmo
Instituição - Universidade Federal de Roraima
*/


int subsetSum(int *p,int n,int c){
	if(n == 0){
		if(c == 0)
			return 1;
		else
			return 0;
	}else{
		int s = subsetSum(p,n-1,c);
		if(s == 0 && p[n] <= c)
			s = subsetSum(p,n-1,c - p[n]);
		
		return s;
	}
}


int main(){
	int p[] = {30,40,10,15,10,60,54};

	
	printf("result: %d",subsetSum(p,7,55));
	//achar o valor 55 em algum subconjunto de p[]
	//retorna 1 caso exista, ou 0 caso não exista
	//serve para qualquer valor em qualquer conjunto
	return 0;

}
