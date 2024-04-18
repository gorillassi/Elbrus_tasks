#include "algorithm.hpp"

int main(){
    int a[] = {4, -7, 5, -1, 8};
    int size = sizeof(a)/sizeof(a[0]);
    maxSumRange(a, size);
    return 0;
}