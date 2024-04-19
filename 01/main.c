#include "merge_sort.h"

void testMergeSortFunction() {

    //////TEST1////////////////////////////////

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("#TEST_1\n");
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    struct Sort_params params = {arr, 0, size - 1};

    pthread_t sort_thread;
    pthread_create(&sort_thread, NULL, merge_sort, &params);
    pthread_join(sort_thread, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //////TEST2////////////////////////////////

    int arr1[] = {3, 7, 43, 15, 28, 31, 10, 128, 100};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("#TEST_2\n");
    printf("Array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    struct Sort_params params1 = {arr1, 0, size1 - 1};

    pthread_t sort_thread1;
    pthread_create(&sort_thread1, NULL, merge_sort, &params1);
    pthread_join(sort_thread1, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

int main() {
    printf("Running unit tests...\n");

    printf("\nRunning test for the merge sort function:\n");
    testMergeSortFunction();

    printf("\nUnit tests completed.\n");

    return 0;
}
