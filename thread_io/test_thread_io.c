#include <assert.h>
#include "thread_io.h"
#include "test_thread_io.h"

void testAll_fill_matrix() {
    int n = 3;
    int count_query = 2;
    int matrix[n][n];

    int query[2][4] = {{1,1,2,2}, {0,0,1,1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    fill_matrix(*matrix, n, *query, count_query);
    int resMatrix[3][3] = {{1,1,0}, {1,2,1}, {0,1,1}};

    for (int z = 0; z < n; z++) {
        for (int x = 0; x < n; x++) {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}

void testAll_liveGame() {
    int n = 4;
    int m = 3;
    int matrix[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

    liveGame(*matrix, n, m);

    int resMatrix[4][3] = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    for (int z = 0; z < n; z++) {
        for (int x = 0; x < m; x++) {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}

void testAll_MedianFilter() {
    int n = 3;
    int m = 3;
    int filterSize = 3;
    int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    MedianFilter((int *)matrix, n, m, filterSize);

    int resMatrix[3][3] = {
            {4, 4, 5},
            {5, 5, 6},
            {7, 7, 8}
    };

    for (int z = 0; z < n; z++) {
        for (int x = 0; x < m; x++) {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}

void assertString(const char *expected, const char *got, const char *file, const char *function, int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "Assertion failed at %s:%d (%s): Expected '%s' but got '%s'\n", file, line, function, expected, got);
        // Дополнительные действия, если требуется
    }
}

// Функция для сравнения элементов DomainCounter по счетчику
int compareDomainCountersByCounter(const void *a, const void *b) {
    return ((DomainCounter *)a)->counter - ((DomainCounter *)b)->counter;
}

// Функция для сравнения элементов DomainCounter по домену
int compareDomainCountersByDomain(const void *a, const void *b) {
    return strcmp(((DomainCounter *)a)->domain, ((DomainCounter *)b)->domain);
}

// Функция для вывода содержимого массива DomainCounter
void printDomainCounters(DomainCounter *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("[%ld] %s\n", array[i].counter, array[i].domain);
    }
}

void testAll_showVisitStats() {
    char stats[] = "cpdomains = [\"900 google.mail.com\", \"50 yahoo.com\", \"1 intel.mail.com\", \"5 wiki.org\"]\0";
    vectorVoid res = showVisitStats(stats);

    DomainCounter expDomains[] = {
            {900, "google.mail.com"},
            {50, "yahoo.com"},
            {1, "intel.mail.com"},
            {5, "wiki.org"},
            {900, "mail.com"},
            {50, "com"},
            {5, "org"},
            {50, "google.mail.com"},
            {5, "mail.com"},
            {5, "intel.mail.com"},
            {5, "yahoo.com"},
            {5, "wiki.org"}
    };

    // Сортировка массивов для сравнения
    qsort(expDomains, sizeof(expDomains) / sizeof(expDomains[0]), sizeof(expDomains[0]), compareDomainCountersByCounter);
    qsort(res.data, res.size, sizeof(DomainCounter), compareDomainCountersByCounter);

    // Вывод содержимого массивов для анализа
    printf("Expected:\n");
    printDomainCounters(expDomains, sizeof(expDomains) / sizeof(expDomains[0]));
    printf("\nResult:\n");
    for (size_t i = 0; i < res.size; i++) {
        DomainCounter domain;
        getVectorValueV(&res, i, &domain);
        printf("[%ld] %s\n", domain.counter, domain.domain);
    }

    // Проверка размера результата
    assert(sizeof(expDomains) / sizeof(DomainCounter) >= res.size);

    // Проверка каждого элемента
    for (int i = 0; i < res.size; i++) {
        DomainCounter domain;
        getVectorValueV(&res, i, &domain);
        assert(expDomains[i].counter == domain.counter);
        assert(strcmp(expDomains[i].domain, domain.domain) == 0);
    }
}

void testAll_submatricesNum() {
    int n = 3;
    int m = 3;

    int matrix[3][3] = {{1,0,1},{1,1,0},{1,1,0}};

    submatricesNum(*matrix, n, m);
}

void testThreadAll() {
    testAll_fill_matrix();
    testAll_liveGame();
    testAll_MedianFilter();
    testAll_showVisitStats();
    //testAll_submatricesNum();
}