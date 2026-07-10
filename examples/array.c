#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Array Iterator: int ===\n");
    int intArr[] = {10, 20, 30, 40};
    FOR_EACH_ARR(intArr, IntPrint);

    printf("\n=== Array Iterator: float ===\n");
    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    FOR_EACH_ARR(floatArr, FloatPrint);

    return 0;
}
