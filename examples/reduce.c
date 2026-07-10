#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Reduce Consumer ===\n");
    int intArr[] = {1, 2, 3, 4, 5, 6};

    int sum = 0;
    ReduceConsumer(
        NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
        sizeof(int),
        sumCombine,
        &sum);
    printf("sum: %d\n", sum);

    size_t evenCount = 0;
    ReduceConsumer(
        NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
        sizeof(int),
        countEvenCombine,
        &evenCount);
    printf("even count: %zu\n", evenCount);

    return 0;
}