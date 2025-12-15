#define MAX 100000

void generate_random_vector (int v[], int size);
void generate_sorted_vector (int v[], int size);
void shuffle_vector (int v[], int size);
void print_vector (int v[], int size);
void swap (int *i, int *j);
void merge (int v[], int start, int middle, int end);
void merge_normal (int v[], int start, int middle, int end);
int partition (int v[], int start, int end);
int partition_median3 (int v[], int start, int end);
void insertion_sort (int v[], int start, int end);
void quick_sort (int v[], int start, int end);
void quick_sort_median3 (int v[], int start, int end);
void merge_sort (int v[], int start, int end);
void merge_sort_normal (int v[], int start, int end);
void quick_sort_median3_insertion (int v[], int start, int end);
