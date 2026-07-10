#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Find Consumer ===\n");
    int intArr[] = {1, 3, 5, 8, 9};

    int result = 0;
    bool found = FindConsumer(
        NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
        sizeof(int),
        isEven,
        &result);

    if (found)
        printf("found even element: %d\n", result);
    else
        printf("no even element found\n");

    int intArrNoEvens[] = {1, 3, 5, 7, 9};
    bool foundNone = FindConsumer(
        NewArrayIterator(sizeof(int), intArrNoEvens, sizeof intArrNoEvens / sizeof *intArrNoEvens),
        sizeof(int),
        isEven,
        &result);

    printf("found: %s\n", foundNone ? "true" : "false");

    return 0;
}