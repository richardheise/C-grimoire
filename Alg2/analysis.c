#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sorting_lib.h"

#define MAX 100000
#define MAX_IT 10 /* isto pode ser ajustado */

/* Returns time in milliseconds */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int *v;
    v = malloc(MAX * sizeof(int)); 
    int i, size;
    double start, end, time_sum;

    /* tests with randomly generated vectors */

    /* set size as you see fit */
    size = 10000;
    time_sum = 0;
    for (i=0; i<MAX_IT; i++) {
        generate_random_vector (v,size);
        shuffle_vector(v, size);
        start = timestamp();
        quick_sort_median3_insertion(v,0,size-1);  /* measures time only of quicksort */
        end = timestamp();
        time_sum += (end-start);
        /* does not count the shuffling time */
    }
    printf("average time of quicksort median of 3 with insertion: %f\n", time_sum/MAX_IT);
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_random_vector (v,size);
        start = timestamp();
        merge_sort(v,0,size-1);  /* measures time only of quicksort */
        end = timestamp();
        time_sum += (end-start);    /* does not count the shuffling time */
    }
    printf("average time of mergesort that doesn't call merge() if vector is already sorted: %f\n", time_sum/MAX_IT);
        time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_random_vector (v,size);
        shuffle_vector(v, size);
        start = timestamp();
        insertion_sort(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of insertionsort: %f\n", time_sum/MAX_IT); 
        time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_random_vector (v,size);
        shuffle_vector(v, size);
        start = timestamp();
        quick_sort(v,0,size-1);
        end = timestamp();
        time_sum += (end-start);
    }
    printf("average time of quicksort: %f\n", time_sum/MAX_IT);
        time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_random_vector (v,size);
        shuffle_vector(v, size);
        start = timestamp();
        merge_sort_normal(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of normal mergesort: %f\n", time_sum/MAX_IT);
    printf("Now for sorted vectors\n");
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        insertion_sort(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of insertionsort: %f\n", time_sum/MAX_IT); 
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        quick_sort(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of quicksort: %f\n", time_sum/MAX_IT); 
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        quick_sort_median3_insertion(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of quicksort median3 with insertionsort: %f\n", time_sum/MAX_IT); 
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        quick_sort_median3(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of quicksort median of 3 without insertion: %f\n", time_sum/MAX_IT); 
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        merge_sort(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of mergesort: %f\n", time_sum/MAX_IT); 
    return 0;
    time_sum = 0;
        for (i=0; i<MAX_IT; i++) {
        generate_sorted_vector (v,size);
        start = timestamp();
        merge_sort_normal(v,0,size-1);  
        end = timestamp();
        time_sum += (end-start);    
    }
    printf("average time of mergesort that doesn't call merge() if the comparison vectors are already sorted: %f\n", time_sum/MAX_IT); 
    return 0;

}
