#include "array_iterator.h"
#include "filter_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Count Consumer ===\n");
    int intArr[] = {1, 2, 3, 4, 5, 6};

    size_t total = CountConsumer(
        NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
        sizeof(int));
    printf("total elements: %zu\n", total);

    size_t evens = CountConsumer(
        NewFilterIterator(
            sizeof(int),
            NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
            isEven),
        sizeof(int));
    printf("even elements: %zu\n", evens);

    return 0;
}