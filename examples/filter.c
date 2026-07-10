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
        FILTER_ARR(intArr, IntIsEven),
        sizeof(int),
        IntPrint);

    return 0;
}
