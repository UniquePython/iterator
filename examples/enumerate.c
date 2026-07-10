#include "enumerate_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Enumerate Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator enumerateIt = NewEnumerateIterator(sizeof(int), intIt);
    ForEachConsumer(enumerateIt, sizeof(EnumeratedItem), printEnumeratedItem);

    return 0;
}
