#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include "vector.h"

static void badAllocV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize) {
    void *v = malloc(n * baseTypeSize);
    if (v == NULL) {
        badAllocV();
    }
    return (vectorVoid) {v, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }
    void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
    if (newData == NULL) {
        badAllocV();
    }
    v->data = newData;
    v->capacity = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->baseTypeSize = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void pushBackV(vectorVoid *v, void *value) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);
    char* dest = (char*)v->data + v->size * v->baseTypeSize;
    memcpy(dest, value, v->baseTypeSize);
    v->size++;
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        badAllocV();
    }
    v->size--;
}

void* atVectorV(vectorVoid *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    return (char*)v->data + index * v->baseTypeSize;
}

void* backV(vectorVoid *v) {
    return atVectorV(v, v->size - 1);
}

void* frontV(vectorVoid *v) {
    return atVectorV(v, 0);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *v = malloc(n * baseTypeSize);
    if (v == NULL) {
        badAllocV();
    }
    return (vectorVoid) {v, 0, n, baseTypeSize};
}

void copy(char *sourceBegin, char *destBegin, size_t count) {
    // Копируем count элементов из sourceBegin в destBegin
    for (size_t i = 0; i < count; ++i) {
        destBegin[i] = sourceBegin[i];
    }
}

void getVectorValueV(vectorVoid *vector, size_t index, void *value) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of range\n");
        exit(1);
    }
    char *ptr = (char *)vector->data + index * vector->baseTypeSize;
    memcpy(value, ptr, vector->baseTypeSize);
}