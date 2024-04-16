#include "algorithm.h"

void maxSumRange(int arr[]){
    int maxSum, maxSum_temp, start, end, start_temp = 0;
    int size = sizeof(arr)/sizeof(arr[0]);

    for (size_t i = 0; i < size ; i++)
    {
        maxSum_temp = arr[i];

        if (maxSum < maxSum_temp)
        {
            maxSum = maxSum_temp;
            start = start_temp;
            end = i;
        }
        
        if(maxSum_temp < 0){
            maxSum_temp = 0;
            start = i + 1;
        }

        std::cout << "Максимальная сумма:" << maxSum <<std::endl;
        std::cout << "Начало:" << start << std::endl;
        std::cout << "Конец:" << end << std::endl;
    }
    
}  