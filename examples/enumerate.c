#include "enumerate_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Enumerate Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        ENUMERATE_ARR(intArr),
        sizeof(EnumeratedItem),
        printEnumeratedItem);

    return 0;
}
