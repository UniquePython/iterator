#include "take_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Take Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator takeIt = NewTakeIterator(sizeof(int), intIt, 2);
    printAll(takeIt, sizeof(int), printInt);
    IteratorDestroy(&takeIt);

    return 0;
}
