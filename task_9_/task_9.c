#include <stdio.h>
#include <stdlib.h>

void filterNumbers(const char *inputFileName, const char *outputFileName, int N) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Cannot open input file: %s\n", inputFileName);
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Cannot open output file: %s\n", outputFileName);
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    int number;
    while (fscanf(inputFile, "%d", &number) == 1) {
        if (number < N) {
            fprintf(outputFile, "%d\n", number);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <N>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    int N = atoi(argv[3]);

    filterNumbers(inputFileName, outputFileName, N);

    return EXIT_SUCCESS;
}