#include "merge_sort.h"

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void* merge_sort(void* params) {
    struct Sort_params* p = (struct Sort_params*)params;
    int left = p->left;
    int right = p->right;
    int* arr = p->arr;

    if (left < right) {
        int mid = left + (right - left) / 2;

        struct Sort_params left_params = {arr, left, mid};
        struct Sort_params right_params = {arr, mid + 1, right};

        pthread_t left_thread, right_thread;
        pthread_create(&left_thread, NULL, merge_sort, &left_params);
        pthread_create(&right_thread, NULL, merge_sort, &right_params);

        pthread_join(left_thread, NULL);
        pthread_join(right_thread, NULL);

        merge(arr, left, mid, right);
    }

    pthread_exit(0);
}