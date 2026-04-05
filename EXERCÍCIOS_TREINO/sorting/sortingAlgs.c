#include "sortingAlgs.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void BubbleSort(int * Vetor, int N){	
	if(N>1){
		for(int i=0; i<N-1; i++){
			if (Vetor[i]>Vetor[i+1]){
				int troca;
				troca = Vetor[i];
				Vetor[i] = Vetor[i+1];
				Vetor[i+1] = troca;
			}
		}
		BubbleSort(Vetor, N-1);
	}
}



void InserctionSort(int * Vetor, int N){
	if (N>1){
		InserctionSort(Vetor, N-1);
		InsereUltimo(Vetor, N);
	}
}

void InsereUltimo(int * Vetor, int N){
	int i=N;
	while(Vetor[i] < Vetor[i-1]  &&  i>0){
		int troca;
		troca = Vetor[i];
		Vetor[i] = Vetor[i-1];
		Vetor[i-1] = troca;
		i--;
	}
}



void SelectionSort(int * Vetor, int N){
	if (N>1){
		int maior = INT_MIN, maiorI;
		for (int i=0; i<N; i++){
			if (Vetor[i] > maior){
				maiorI = i;
				maior = Vetor[i];
			}
		}
		Vetor[maiorI] = Vetor[N-1];
		Vetor[N-1] = maior;
		SelectionSort(Vetor, N-1);
	}
}



void MergeSort(int * Vetor, int N){
	if (N>1){
		int meio = N/2; 
		
		MergeSort(Vetor, meio);
		MergeSort(Vetor+meio, N-meio);
		
		int * primeiraMetade = malloc(meio*sizeof(int));
		int * segundaMetade = malloc((N-meio)*sizeof(int));
		
		for (int i=0; i<meio; i++)
			primeiraMetade[i] = Vetor[i];
		
		for (int i=meio; i<N; i++)
			segundaMetade[i-meio] = Vetor[i];
		
		Merge(primeiraMetade, meio, segundaMetade, N-meio, Vetor);
		
		free(primeiraMetade);
		free(segundaMetade);
		
	}
}

void Merge(int * Vetor1, int N, int * Vetor2, int M, int * Nova){
	int i=0, j=0, k=0;
	while(i<N  && j<M){
		if (Vetor1[i] < Vetor2[j]){
			Nova[k] = Vetor1[i];
			i++;
		}else{
			Nova[k] = Vetor2[j];
			j++;
		}
		k++;
	}
	
	while(i<N){
		Nova[k] = Vetor1[i];
		i++;	
		k++;
	}
	
	while(j<M){
		Nova[k] = Vetor2[j];
		j++;	
		k++;
	}
}



void QuickSort(int * Vetor, int N){
	
	if (N>1){
		int PivPos;
		
		PivotSeparate(Vetor, N, &PivPos);
		
		QuickSort(Vetor, PivPos);
		QuickSort((Vetor+PivPos+1), (N-PivPos-1));
	}
}

void PivotSeparate(int * Vetor, int N, int * pivotPos){
	int i=0, j=N-1, troca;
	srand(time(0));
	*pivotPos = (rand() % N);
	int pivot = Vetor[*pivotPos];
	
	
	while(j>i){
		while(i < N  &&  Vetor[i] < pivot){
			i++;
		}
		while(j > 0  &&  Vetor[j] >= pivot){
			j--;
		}
		if (j>i){
			if (i==*pivotPos){
				*pivotPos = j;
			}else if (j==*pivotPos){
				*pivotPos = i;
			}
			troca = Vetor[i];
			Vetor[i] = Vetor[j];
			Vetor[j] = troca;
		}
	}
	Vetor[*pivotPos] = Vetor[j];
	Vetor[j] = pivot;
	*pivotPos = j;
}


