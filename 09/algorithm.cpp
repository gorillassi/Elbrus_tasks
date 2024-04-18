#include "algorithm.hpp"

void maxSumRange(int arr[], int size){
    int maxSum = INT_MIN, maxSum_temp = 0, start = 0, end = 0, start_temp = 0;

    for (size_t i = 0; i < size ; i++){
        maxSum_temp += arr[i];

        if (maxSum < maxSum_temp){
            maxSum = maxSum_temp;
            start = start_temp;
            end = i;
        }
        
        if(maxSum_temp < 0){
            maxSum_temp = 0;
            start_temp = i + 1;
        }
    }

    std::cout << "Максимальная сумма:" << maxSum <<std::endl;
    std::cout << "Начало:" << start << std::endl;
    std::cout << "Конец:" << end << std::endl;
    
}  