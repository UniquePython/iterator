#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== All Consumer ===\n");

    int allEven[] = {2, 4, 6, 8};
    bool result1 = AllConsumer(
        NEW_ARRAY_ITERATOR(allEven),
        sizeof(int),
        IntIsEven);
    printf("allEven are all even: %s\n", result1 ? "true" : "false");

    int mixed[] = {2, 4, 5, 8};
    bool result2 = AllConsumer(
        NEW_ARRAY_ITERATOR(mixed),
        sizeof(int),
        IntIsEven);
    printf("mixed are all even: %s\n", result2 ? "true" : "false");

    int empty[1] = {0};
    bool result3 = AllConsumer(
        NewArrayIterator(sizeof(int), empty, 0),
        sizeof(int),
        IntIsEven);
    printf("empty are all even (vacuously true): %s\n", result3 ? "true" : "false");

    return 0;
}