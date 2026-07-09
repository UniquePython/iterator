#include "array_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Array Iterator: int ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = newArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    printAll(intIt, sizeof(int), printInt);
    IteratorDestroy(&intIt);

    printf("\n=== Array Iterator: float ===\n");
    float floatArr[] = {10.5f, 20.5f, 30.5f, 40.5f};
    Iterator floatIt = newArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr);
    printAll(floatIt, sizeof(float), printFloat);
    IteratorDestroy(&floatIt);

    return 0;
}
