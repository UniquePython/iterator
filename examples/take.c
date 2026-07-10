#include "take_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Take Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        TAKE_ARR(intArr, 2),
        sizeof(int),
        IntPrint);

    return 0;
}
