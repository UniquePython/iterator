#include "skip_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Skip Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator skipIt = NewSkipIterator(sizeof(int), intIt, 2);
    printAll(skipIt, sizeof(int), printInt);
    IteratorDestroy(&skipIt);

    return 0;
}
