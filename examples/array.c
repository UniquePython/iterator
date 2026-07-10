#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Array Iterator: int ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        NEW_ARRAY_ITERATOR(intArr),
        sizeof(int),
        IntPrint);

    printf("\n=== Array Iterator: float ===\n");
    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    ForEachConsumer(
        NEW_ARRAY_ITERATOR(floatArr),
        sizeof(float),
        FloatPrint);

    return 0;
}
