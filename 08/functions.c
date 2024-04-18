#include "functions.h"

volatile sig_atomic_t inters = 0;

int cur_row = -1;
int cur_col = -1;

void sign_handl(int sign){
    if(inters < 1){
        if (cur_row != -1 && cur_col != -1)
        {
            printf("Текущая строка: %d, столбец: %d\n", cur_row, cur_col);
            signal(SIGINT, SIG_DFL);
        }
    }
    else{
        exit(0);
    }

    inters++;
}

void matrixMul(int **f_matrix, int **s_matrix, int **r_matrix){
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            cur_row = i;
            cur_col = j;

            int sum = 0;
            for (int k = 0; k < matrixSize; k++){
                sum += f_matrix[i][k] * s_matrix[k][j];
            }
            r_matrix[i][j] = sum;

            sleep(1);
        }   
    }
}