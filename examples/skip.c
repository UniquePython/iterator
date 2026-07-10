#include "skip_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Skip Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        SKIP_ARR(intArr, 2),
        sizeof(int),
        IntPrint);

    return 0;
}
