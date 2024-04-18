#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Ошибка: не переданы аргументы командной строки\n");
        return 1;
    }

    char options[100] = "";
    char non_options[100] = "";

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') {
                if (strchr(argv[i], '=') == NULL) {
                    fprintf(stderr, "Ошибка: неправильный формат для длинных аргументов[%s]\n", argv[i]);
                    return 1;
                } else {
                    if (strlen(options) + strlen(argv[i] + 2) + 1 + strlen(strchr(argv[i], '=') + 1) + 2 > sizeof(options)) {
                        fprintf(stderr, "Ошибка: переполнение буфера\n");
                        return 1;
                    }
                    strncat(options, argv[i] + 2, strchr(argv[i], '=') - (argv[i] + 2));
                    strncat(options, "=", sizeof(options) - 1);
                    strncat(options, strchr(argv[i], '=') + 1, sizeof(options) - 1);
                    strncat(options, ", ", sizeof(options) - 1);
                }
            } else {
                int j = 1;
                while (argv[i][j] != '\0') {
                    if (strlen(options) + 3 > sizeof(options)) {
                        fprintf(stderr, "Ошибка: переполнение буфера\n");
                        return 1;
                    }
                    char current_option[4] = {'-', argv[i][j], '\0'};
                    strncat(options, current_option, sizeof(options) - 1);
                    strncat(options, ", ", sizeof(options) - 1);
                    j++;
                }
            }
        } else {
            if (strlen(non_options) + strlen(argv[i]) + 2 > sizeof(non_options)) {
                fprintf(stderr, "Ошибка: переполнение буфера\n");
                return 1;
            }
            strncat(non_options, argv[i], sizeof(non_options) - 1);
            strncat(non_options, ", ", sizeof(non_options) - 1);
        }
    }

    if (options[0] != '\0') {
        printf("Options are correct: %s", options);
        if (non_options[0] != '\0') {
            printf("non-options: %s", non_options);
        }
        printf("\n");
    } else {
        printf("Options are incorrect.\n");
    }

    return 0;
}
