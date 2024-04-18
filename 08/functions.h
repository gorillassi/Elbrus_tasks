#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define matrixSize 1000

void sign_handl(int sign);

void matrixMul(int **f_matrix, int **s_matrix, int **r_matrix);

#endif //FUNCTIONS_H