#include "sort.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr,
                "Usage: %s <input_file> <output_file> <sorting_method>\n",
                argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *sortingMethod = argv[3];

    sort(inputFile, outputFile, sortingMethod);

    return 0;
}
