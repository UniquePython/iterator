#include "unique_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Unique Iterator ===\n");
    int intArr[] = {10, 20, 20, 30, 30, 30, 40, 40, 40, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator uniqueIt = NewUniqueIterator(sizeof(int), intIt, intEqual);
    printAll(uniqueIt, sizeof(int), printInt);
    IteratorDestroy(&uniqueIt);

    return 0;
}
