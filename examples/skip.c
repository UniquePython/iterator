#include "skip_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Skip Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator skipIt = newSkipIterator(sizeof(int), intIt, 2);
    printAll(skipIt, sizeof(int), printInt);
    IteratorDestroy(&skipIt);
    IteratorDestroy(&intIt);

    return 0;
}
