#include <stdio.h>

#include "merge_sort.h"

int main() { 
    int SIZE = 0;

    printf("Введите размер массива:\n");
    scanf("%d", &SIZE);

    int arr[SIZE];
    printf("Введите элементы массива:\n");

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    struct Sort_params params = {arr, 0, SIZE - 1};

    pthread_t sort_thread;
    pthread_create(&sort_thread, NULL, merge_sort, &params);
    pthread_join(sort_thread, NULL);

    printf("Отсортированный массив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}