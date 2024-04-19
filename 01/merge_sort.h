#ifndef MERGESORT_H
#define MERGESORT_H

#include <pthread.h>
#include <stdio.h>

struct Sort_params {
    int* arr;
    int left;
    int right;
};

void merge(int arr[], int l, int mid, int r);

void* merge_sort(void* params);

#endif