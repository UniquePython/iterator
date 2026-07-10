#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Array Iterator: int ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    ForEachConsumer(intIt, sizeof(int), printInt);

    printf("\n=== Array Iterator: float ===\n");
    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    Iterator floatIt = NewArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr);
    ForEachConsumer(floatIt, sizeof(float), printFloat);

    return 0;
}
