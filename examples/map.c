#include "map_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Map Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        NewMapIterator(
            sizeof(int),
            NEW_ARRAY_ITERATOR(intArr),
            doubleInt),
        sizeof(int),
        IntPrint);

    return 0;
}
