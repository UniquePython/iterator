#include "chain_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Chain Iterator ===\n");
    int intArrA[] = {10, 20, 30, 40};
    int intArrB[] = {60, 70, 80, 90};
    ForEachConsumer(
        NewChainIterator(
            sizeof(int),
            NewArrayIterator(sizeof(int), intArrA, sizeof intArrA / sizeof *intArrA),
            NewArrayIterator(sizeof(int), intArrB, sizeof intArrB / sizeof *intArrB)),
        sizeof(int),
        IntPrint);

    return 0;
}
