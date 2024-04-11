#include <pthread.h>

struct Sort_params {
    int* arr;
    int left;
    int right;
};

void merge(int arr[], int l, int mid, int r);

void* merge_sort(void* params);