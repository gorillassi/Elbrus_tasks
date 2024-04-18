#include "functions.h"

int main() {
    int **f_matrix = (int **)calloc(matrixSize, sizeof(int *));
    int **s_matrix = (int **)calloc(matrixSize, sizeof(int *));
    int **r_matrix = (int **)calloc(matrixSize, sizeof(int *));
    
    for (int i = 0; i < matrixSize; i++) {
        f_matrix[i] = (int *)calloc(matrixSize, sizeof(int));
        s_matrix[i] = (int *)calloc(matrixSize, sizeof(int));
        r_matrix[i] = (int *)calloc(matrixSize, sizeof(int));
        for (int j = 0; j < matrixSize; j++) {
            f_matrix[i][j] = i % 10;
            s_matrix[i][j] = j % 7;
        }
    }

    signal(SIGINT, sign_handl);

    matrixMul(f_matrix, s_matrix, r_matrix);

    for (int i = 0; i < matrixSize; i++) {
        free(f_matrix[i]);
        free(s_matrix[i]);
        free(r_matrix[i]);
    }

    free(f_matrix);
    free(s_matrix);
    free(r_matrix);

    return 0;
}