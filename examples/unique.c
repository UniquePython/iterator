#include "unique_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Unique Iterator ===\n");
    int intArr[] = {10, 20, 20, 30, 30, 30, 40, 40, 40, 40};
    ForEachConsumer(
        NewUniqueIterator(
            sizeof(int),
            NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
            IntEqual),
        sizeof(int),
        IntPrint);

    return 0;
}
