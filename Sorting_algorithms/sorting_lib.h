// GRR20191053 Richard Fernando Heise Ferreira 
// Definição e operações em uma lista genérica.

#ifndef __SORTING_LIB__
#define __SORTING_LIB__

#define MAX 100000

//------------------------------------------------------------------------------
// Gera um vetor com números aleatórios.
void generate_random_vector(int v[], int size);

//------------------------------------------------------------------------------
// Gera um vetor ordenado.
void generate_sorted_vector(int v[], int size);

//------------------------------------------------------------------------------
// Embaralha um vetor.
void shuffle_vector(int v[], int size);

//------------------------------------------------------------------------------
// Imprime o conteúdo de um vetor.
void print_vector(int v[], int size);

//------------------------------------------------------------------------------
// Troca dois elementos de posição.
void swap(int *i, int *j);

//------------------------------------------------------------------------------
// Combina dois subvetores ordenados em um único vetor ordenado.
void merge(int v[], int start, int middle, int end);

//------------------------------------------------------------------------------
// Versão normal do merge.
void merge_normal(int v[], int start, int middle, int end);

//------------------------------------------------------------------------------
// Particiona o vetor para o Quick Sort.
// Retorno: a posição do pivô.
int partition(int v[], int start, int end);

//------------------------------------------------------------------------------
// Particiona o vetor usando a mediana de três.
// Retorno: a posição do pivô.
int partition_median3(int v[], int start, int end);

//------------------------------------------------------------------------------
// Ordena um vetor usando o método de Inserção.
void insertion_sort(int v[], int start, int end);

//------------------------------------------------------------------------------
// Ordena um vetor usando o método Quick Sort.
void quick_sort(int v[], int start, int end);

//------------------------------------------------------------------------------
// Ordena um vetor usando o método Quick Sort com mediana de três.
void quick_sort_median3(int v[], int start, int end);

//------------------------------------------------------------------------------
// Ordena um vetor usando o método Merge Sort.
void merge_sort(int v[], int start, int end);

//------------------------------------------------------------------------------
// Versão normal do Merge Sort.
void merge_sort_normal(int v[], int start, int end);

//------------------------------------------------------------------------------
// Ordena um vetor usando Quick Sort com mediana de três e Inserção para partições pequenas.
void quick_sort_median3_insertion(int v[], int start, int end);

#endif
