#include "parser.h"

int main() {
    printf("Введите ваше логическое выражение: ");

    const size_t MAX_LEN = 100;

    char expression[MAX_LEN];
    fgets(expression, MAX_LEN, stdin);
    strn_tolower(expression, MAX_LEN);

    printf("Результат: %d", GetG(expression));

    return 0;
}