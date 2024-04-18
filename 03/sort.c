#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Объявление compare_length
int compare_length(const void *a, const void *b);

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(char *inputFile, char *outputFile, char *sortingMethod) {
    FILE *inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    char buffer[MAX_LENGTH];
    char **lines = calloc(MAX_LENGTH, sizeof(char *));
    if (lines == NULL) {
        perror("Memory allocation error");
        fclose(inFile);
        fclose(outFile);
        return;
    }

    int numLines = 0;

    while (fgets(buffer, MAX_LENGTH, inFile) != NULL) {
        if (strcspn(buffer, "\n\t ") != strlen(buffer)) {
            lines[numLines] = strdup(buffer);
            numLines++;
        }
    }

    if (strcmp(sortingMethod, "length") == 0) {
        qsort(lines, numLines, sizeof(char *), compare_length);
    } else if (strcmp(sortingMethod, "alphabet") == 0) {
        qsort(lines, numLines, sizeof(char *), compare);
    } else {
        printf("Invalid sorting method. Please use 'length' or 'alphabet'.\n");
        free(lines);
        fclose(inFile);
        fclose(outFile);
        return;
    }

    for (int i = 0; i < numLines; i++) {
        fprintf(outFile, "%s", lines[i]);
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);
    fclose(inFile);
    fclose(outFile);
}

int compare_length(const void *a, const void *b) {
    size_t len_a = strlen(*(const char **)a);
    size_t len_b = strlen(*(const char **)b);

    if (len_a < len_b) {
        return -1;
    } else if (len_a > len_b) {
        return 1;
    } else {
        return 0;
    }
}
