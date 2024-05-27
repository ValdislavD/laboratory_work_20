//#include "../thread_io/thread_io.h."
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void outputFileInChunks(const char *fileInputPath, int N) {
    FILE *fileInput = fopen(fileInputPath, "r");
    if (fileInput == NULL) {
        fprintf(stderr, "Cannot open input file: %s\n", fileInputPath);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int lineCount = 0;

    while (fgets(buffer, BUFFER_SIZE, fileInput) != NULL) {
        printf("%s", buffer);
        lineCount++;

        if (lineCount == N) {
            lineCount = 0;
            printf("Press Ctrl+C to continue...\n");
            while (1) {
                if (getchar() == 3) {  // Check for Ctrl+C
                    printf("\n");
                    break;
                }
            }
        }
    }

    fclose(fileInput);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <N>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *fileInputPath = argv[1];
    int N = atoi(argv[2]);

    outputFileInChunks(fileInputPath, N);

    return EXIT_SUCCESS;
}