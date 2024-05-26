#include "thread_io/thread_io.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int matrix[3][3] = {
            {10, 20, 30},
            {25, 35, 45},
            {15, 25, 35}
    };
    int filter = 3;
    int n = 3;
    int m = 3;

    medianFilter((int *)matrix, filter, n, m);

    // Вывод результата
    printf("Выходные данные:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}