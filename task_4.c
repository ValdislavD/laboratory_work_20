/*#include <stdio.h>
#include "thread_io/thread_io.h"

int main() {
    char stats[] = "cpdomains = [\"900 google.mail.com\", \"50 yahoo.com\", \"1 intel.mail.com\", \"5 wiki.org\"]";
    vectorVoid result = showVisitStats(stats);

    // Вывод результата
    for (size_t i = 0; i < result.size; i++) {
        DomainCounter domainCounter;
        getVectorValueV(&result, i, &domainCounter);
        printf("%ld %s\n", domainCounter.counter, domainCounter.domain);
    }

    // Очистка памяти
    deleteVectorV(&result);

    return 0;
}*/