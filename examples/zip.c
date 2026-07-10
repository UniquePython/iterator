#include "zip_iterator.h"
#include "array_iterator.h"
#include "string_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Zip Iterator ===\n");
    float floatArr[] = {10.37f, 20.37f, 30.37f, 40.37f};
    const char *string = "hello";
    ForEachConsumer(
        NewZipIterator(
            sizeof(char),
            NewStringIterator(string),
            sizeof(float),
            NewArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr)),
        sizeof(ZippedItem),
        printZippedItem);

    return 0;
}
