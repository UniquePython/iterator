#include "map_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Map Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator mapIt = newMapIterator(sizeof(int), intIt, doubleInt);
    printAll(mapIt, sizeof(int), printInt);
    IteratorDestroy(&mapIt);
    IteratorDestroy(&intIt);

    return 0;
}
