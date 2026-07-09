#include "zip_iterator.h"
#include "array_iterator.h"
#include "string_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Zip Iterator ===\n");
    float floatArr[] = {10.37f, 20.37f, 30.37f, 40.37f};
    Iterator floatIt = NewArrayIterator(sizeof(float), floatArr, sizeof floatArr / sizeof *floatArr);
    char *string = "hello";
    Iterator stringIt = NewStringIterator(string);
    Iterator zipIt = NewZipIterator(sizeof(char), stringIt, sizeof(float), floatIt);
    printAll(zipIt, sizeof(ZippedItem), printZippedItem);
    IteratorDestroy(&zipIt);
    IteratorDestroy(&stringIt);
    IteratorDestroy(&floatIt);

    return 0;
}
