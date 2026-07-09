#include "chain_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Chain Iterator ===\n");
    int intArrA[] = {10, 20, 30, 40};
    Iterator intItA = newArrayIterator(sizeof(int), intArrA, sizeof intArrA / sizeof *intArrA);
    int intArrB[] = {60, 70, 80, 90};
    Iterator intItB = newArrayIterator(sizeof(int), intArrB, sizeof intArrB / sizeof *intArrB);
    Iterator chainIt = newChainIterator(sizeof(int), intItA, intItB);
    printAll(chainIt, sizeof(int), printInt);
    IteratorDestroy(&chainIt);
    IteratorDestroy(&intItB);
    IteratorDestroy(&intItA);

    return 0;
}
