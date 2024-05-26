#ifndef UNTITLED28_VECTOR_H
#define UNTITLED28_VECTOR_H

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
    void *data; // указатель на элементы вектора произвольного типа
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа данных
} vectorVoid;

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize);
void reserveV(vectorVoid *v, size_t newCapacity);
void clearV(vectorVoid *v);
void shrinkToFitV(vectorVoid *v);
void deleteVectorV(vectorVoid *v);
bool isEmptyV(vectorVoid *v);
bool isFullV(vectorVoid *v);
void pushBackV(vectorVoid *v, void *value);
void popBackV(vectorVoid *v);
void* atVectorV(vectorVoid *v, size_t index);
void* backV(vectorVoid *v);
void* frontV(vectorVoid *v);
vectorVoid createVectorV(size_t n, size_t baseTypeSize);
void copy(char *sourceBegin, char *destBegin, size_t count);
void getVectorValueV(vectorVoid *vector, size_t index, void *value);
matrix getMemMatrix(int nRows, int nCols);
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

#endif //UNTITLED28_VECTOR_H