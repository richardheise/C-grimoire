// GRR20191053 Richard Fernando Heise Ferreira 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_lib.h"
#define MAX 100000

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void print_vector (int v[], int size) {
    int i;

    for (i=0; i<size-1; i++)
        printf("%d ",v[i]);
    printf("%d\n",v[size-1]);
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void swap (int *i, int *j) {
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void generate_sorted_vector (int v[], int size) {
    int i;

    for (i=0; i<size; i++)
        v[i] = i;
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void generate_random_vector (int v[], int size) {
    int i;

    srand(time(0));
    for (i=0; i<size; i++)
        v[i] = (unsigned int) (rand() % (size*3)); /* pode modificar se quiser */
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void shuffle_vector (int v[], int size) {
    int k, i, j, max_swaps;

    max_swaps = (unsigned int) (rand() % size) + size; /* pode modificar */
    for (k=0; k<max_swaps; k++) {
        i = (unsigned int) (rand() % size);
        j = (unsigned int) (rand() % size);
        swap (&v[i],&v[j]);
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void merge_normal (int v[], int start, int middle, int end) {
    int i;
    int j;
    int k = 0;
    int Vaux[MAX];
    for (i = start; i <= end; i++) {
        Vaux[i] = v[i];
    }
    i = start;
	j = (middle + 1);
	k = start;
    while (i <= middle && j <= end) {
        if (Vaux[i] <= Vaux[j]) {
            v[k] = Vaux[i];
            i++;
        } 
        else {
            v[k] = Vaux[j];
            j++;
        }   
        k++;
    }
    while (i <= middle) {
        v[k] = Vaux[i];
        k++;
        i++;
    }  
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void merge(int v[], int start, int middle, int end) {
    if (v[middle] < v[middle+1])
        return;
    int i;
    int j;
    int k = 0;
    int Vaux[MAX];
    for (i = start; i <= end; i++) {
        Vaux[i] = v[i];
    }

    i = start;
    j = (middle + 1);
    k = start;
    while (i <= middle && j <= end) {
        if (Vaux[i] <= Vaux[j]) {
            v[k] = Vaux[i];
            i++;
        }
        else {
            v[k] = Vaux[j];
            j++;
        }
        k++;
    }
    while (i <= middle) {
        v[k] = Vaux[i];
        k++;
        i++;
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

int partition (int v[], int start, int end) {
    int pivot = v[start];
    int i = start+1;
    int j;
    for (j = start + 1; j <= end; ++j) {
        if (v[j] <= pivot) {
            swap(&v[j],&v[i]);
            ++i;
        }
    }
    swap(&v[i-1], &v[start]);
    return (i-1);
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void insertion_sort (int v[], int start, int end) {
    int i;
    int key;
    int j;
    for (i = start+1; i <= end; ++i) {
        j = i - 1;
        key = v[i];
        while ((key < v[j]) && (j >= 0)) {
            v[j+1] = v[j];
            --j;
        }
    v[j+1] = key;
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void quick_sort (int v[], int start, int end) {
    if (start < end) {
        int p = (partition(v, start, end));
        quick_sort(v, start, p-1);
        quick_sort(v, p+1, end);
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void merge_sort (int v[], int start, int end) {
    if (start < end) {
        int middle;
        middle = ((end + start) / 2);
        merge_sort(v, start, middle);
        merge_sort(v, middle+1, end);
        merge(v, start, middle, end);
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void merge_sort_normal (int v[], int start, int end) {
    if (start < end) {
        int middle;
        middle = ((end + start) / 2);
        merge_sort_normal(v, start, middle);
        merge_sort_normal(v, middle+1, end);
        merge_normal(v, start, middle, end);
    }
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

int partition_median3(int v[], int start, int end) {
    int pivot;
    int j;
    int i = start -1;
    int median;
    int middle = (end + start) / 2;
    if ((v[start] < v[middle]) && (v[middle] < v[end])) {
        median = middle;
    }
    if ((v[middle] < v[start]) && (v[start] < v[end])) {
        median = start;
    }
    if ((v[start] < v[end]) && (v[end] < v[middle])) {
        median = end;
    }
    swap(&v[end], &v[median]);
    pivot = v[end];

    for (j = start; j < end; ++j) {
        if (v[j] <= pivot) {
            swap(&v[j],&v[i+1]);
            ++i;
        }
    }
    swap(&v[end], &v[i+1]);
    return i+1;
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void quick_sort_median3_insertion (int v[], int start, int end) {
    if (start < end) {
        if ((end - start + 1) <= 30) {
            insertion_sort(v, start, end);
        } 
        int p = partition_median3(v, start, end);
        quick_sort_median3_insertion(v, start, p - 1);
        quick_sort_median3_insertion(v, p + 1, end);
    }
}    

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void quick_sort_median3 (int v[], int start, int end) {
    if (start < end) {
        int p = partition_median3(v, start, end);
        quick_sort_median3(v, start, p - 1);
        quick_sort_median3(v, p + 1, end);
    }

}
