#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения слова и его индекса
typedef struct {
    char word[1005];
    int index;
} WordIndex;

// Сравнение функции для сортировки
int compare_(const void *a, const void *b) {
    WordIndex *wordIndexA = (WordIndex *)a;
    WordIndex *wordIndexB = (WordIndex *)b;
    return strcmp(wordIndexA->word, wordIndexB->word);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    // Чтение слов и их индексов
    WordIndex *dictionary = malloc(N * sizeof(WordIndex));
    for (int i = 0; i < N; i++) {
        scanf("%s", dictionary[i].word);
        dictionary[i].index = i + 1;
    }

    // Сортировка словаря по алфавиту
    qsort(dictionary, N, sizeof(WordIndex), compare_);

    // Обработка запросов
    for (int i = 0; i < Q; i++) {
        int ki;
        char pi[1005];
        scanf("%d %s", &ki, pi);

        int low = -1, high = -1;

        // Бинарный поиск наименьшего слова, начинающегося с префикса pi
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (strncmp(dictionary[mid].word, pi, strlen(pi)) < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
                low = mid;
            }
        }

        // Бинарный поиск наибольшего слова, начинающегося с префикса pi
        left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (strncmp(dictionary[mid].word, pi, strlen(pi)) <= 0) {
                left = mid + 1;
                high = mid;
            } else {
                right = mid - 1;
            }
        }

        // Вывод результата
        if (low != -1 && high != -1) {
            if (low + ki - 1 <= high) {
                printf("%d\n", dictionary[low + ki - 1].index);
            } else {
                printf("-1\n");
            }
        } else {
            printf("-1\n");
        }
    }

    // Освобождение памяти
    free(dictionary);

    return 0;
}
