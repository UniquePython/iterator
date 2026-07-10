#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== All Consumer ===\n");

    int allEven[] = {2, 4, 6, 8};
    bool result1 = AllConsumer(
        NewArrayIterator(sizeof(int), allEven, sizeof allEven / sizeof *allEven),
        sizeof(int),
        isEven);
    printf("allEven are all even: %s\n", result1 ? "true" : "false");

    int mixed[] = {2, 4, 5, 8};
    bool result2 = AllConsumer(
        NewArrayIterator(sizeof(int), mixed, sizeof mixed / sizeof *mixed),
        sizeof(int),
        isEven);
    printf("mixed are all even: %s\n", result2 ? "true" : "false");

    int empty[1] = {0};
    bool result3 = AllConsumer(
        NewArrayIterator(sizeof(int), empty, 0),
        sizeof(int),
        isEven);
    printf("empty are all even (vacuously true): %s\n", result3 ? "true" : "false");

    return 0;
}