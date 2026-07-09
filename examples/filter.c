#include "filter_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Filter Iterator ===\n");
    int intArr[] = {1, 2, 3, 4};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator filterIt = newFilterIterator(sizeof(int), intIt, isEven);
    printAll(filterIt, sizeof(int), printInt);
    IteratorDestroy(&filterIt);
    IteratorDestroy(&intIt);

    return 0;
}
