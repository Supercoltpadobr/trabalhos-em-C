#ifndef SORTINGALGS_H
#define SORTINGALGS_H

void BubbleSort(int * Vetor, int N);

void InserctionSort(int * Vetor, int N);
void InsereUltimo(int * Vetor, int N);

void SelectionSort(int * Vetor, int N);


void MergeSort(int * Vetor, int N);
void Merge(int * Vetor1, int N, int * Vetor2, int M, int * Nova);

void QuickSort(int * Vetor, int N);
void PivotSeparate(int * Vetor, int N, int * pivotPos);

#endif