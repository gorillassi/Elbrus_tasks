#include "algorithm.hpp"

void testAlgorithm(){
//////////////////TEST1////////////////
    printf("#TEST_1\n");
    printf("Array: ");
    int a[] = {4, -7, 5, -1, 8};
    int size = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    maxSumRange(a, size);
    printf("\n");
////////////////TEST2/////////////////
    printf("#TEST_2\n");
    printf("Array: ");
    int b[] = {6, 0, -18, 20, 1, 15, -228, 1512, 444};
    int size2 = sizeof(b)/sizeof(b[0]);
    printf("\n");
    maxSumRange(b, size2);
    printf("\n");
////////////////TEST3/////////////////
    printf("#TEST_3\n");
    printf("Array: ");
    int c[] = {67, 20, -148, -240, 11, 15, -2280, 15, 10};
    int size3 = sizeof(c)/sizeof(c[0]);
    printf("\n");
    maxSumRange(c, size3);
}

int main(){

    testAlgorithm();

    return 0;
}