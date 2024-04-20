#include "parser.h"

int GetG(const char *expression) {
    size_t index = 0;
    pass_space(expression, &index);

    int val = GetE(expression, &index);

    pass_space(expression, &index);
    assert(*(expression + index) == '\0');

    return val;
}

int GetE(const char *expression, size_t *index) {
    pass_space(expression, index);
    int val = GetT(expression, index);

    while (!(strncmp(expression + (*index), "or", 2))) {
        (*index) += 2;

        int val2 = GetT(expression, index);

        val = val || val2;
    }

    pass_space(expression, index);
    return val;
}

int GetT(const char *expression, size_t *index) {
    pass_space(expression, index);
    int val = GetP(expression, index);

    while (!(strncmp(expression + (*index), "and", 3))) {
        (*index) += 3;

        int val2 = GetP(expression, index);

        val = val && val2;
    }

    pass_space(expression, index);
    return val;
}

int GetP(const char *expression, size_t *index) {
    pass_space(expression, index);
    int val = 0;

    if (*(expression + (*index)) == '(') {
        (*index)++;
        val = GetE(expression, index);

        assert(*(expression + (*index)) == ')');
        (*index)++;
    } else {
        val = GetN(expression, index);
    }

    pass_space(expression, index);
    return val;
}

int GetN(const char *expression, size_t *index) {
    pass_space(expression, index);
    int val = 0;

    int unary_sign = 1;
    if (*(expression + (*index)) == '+') {
        (*index)++;
        pass_space(expression, index);
    } else if (*(expression + (*index)) == '-') {
        unary_sign = 0;

        (*index)++;
        pass_space(expression, index);
    }

    const char *exp_old = expression + (*index);
    while (('0' <= *(expression + (*index))) &&
           (*(expression + (*index)) <= '9')) {
        val = val * 10 + *(expression + (*index)) - '0';
        (*index)++;
    }

    if (unary_sign == 0) {
        val = (-1) * val;
    }

    assert((expression + (*index)) != exp_old);

    pass_space(expression, index);
    return val;
}

//====================================================
void pass_space(const char *expression, size_t *index) {
    while (isspace(*(expression + (*index))) != 0) {
        (*index)++;
    }
}

void strn_tolower(char *str, const size_t N) {
    size_t i = 0;
    while ((i < N) && (*(str + i) != '\0')) {
        *(str + i) = tolower(*(str + i));
        i++;
    }
}