#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Reduce Consumer ===\n");
    int intArr[] = {1, 2, 3, 4, 5, 6};

    int sum = 0;
    REDUCE_ARR(intArr, sumCombine, &sum);
    printf("sum: %d\n", sum);

    size_t evenCount = 0;
    REDUCE_ARR(intArr, countEvenCombine, &evenCount);
    printf("even count: %zu\n", evenCount);

    return 0;
}