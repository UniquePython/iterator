#include "filter_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Filter Iterator ===\n");
    int intArr[] = {1, 2, 3, 4};
    ForEachConsumer(
        NewFilterIterator(
            sizeof(int),
            NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
            IntIsEven),
        sizeof(int),
        IntPrint);

    return 0;
}
