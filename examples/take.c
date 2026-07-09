#include "take_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Take Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator takeIt = newTakeIterator(sizeof(int), intIt, 2);
    printAll(takeIt, sizeof(int), printInt);
    IteratorDestroy(&takeIt);
    IteratorDestroy(&intIt);

    return 0;
}
