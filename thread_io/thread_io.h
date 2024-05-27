#ifndef UNTITLED28_THREAD_IO_H
#define UNTITLED28_THREAD_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct {
    long counter;
    WordDescriptor domain;
} DomainRecord;

typedef struct {
    long counter;
    char domain[255];
} DomainCounter;

typedef struct TreeItem {
    int level;
    int value;
    int type;
    int idx;
} TreeItem;

#define BUFFER_SIZE 256

int compareDomainCounterNames(const void *domainCounterPtr1, const void *domainCounterPtr2);

int compareInts1(const void *intPtr1, const void *intPtr2);

void printMatrix(int *matrix, int n, int m);

void fill_matrix(int *matrix, int sizeOfMatrix, int *query, int queryCount);

int countNeighbors(int *matrix, int n, int m, int col, int row);

void liveGame(int *matrix, size_t n, size_t m);

void MedianFilter(int *matrix, int n, int m, int filterSize);

int calculateMedianVector(int *matrix, int max_col, int row, int col, int *arrayOfNums, int filter_size);

void medianFilter(int *matrix, int filter, int n, int m);

void parsedDomainStat(vectorVoid *data, char *start, char *end);

vectorVoid showVisitStats(char *stats);

int submatricesNum(matrix *m);

DomainCounter *subdomainVisits(char **cpdomains, int cpdomainsSize, int *returnSize);

char* minStringNum(char *pattern);

vectorVoid maxThree(int *nums, int len);

char* strShuffle(char *symbols, int *indices, int len);

void filterNumbers(const char *inputFileName, const char *outputFileName, int N);

void outputFileInChunks(const char *fileInputPath, int N);

#endif //UNTITLED28_THREAD_IO_H
