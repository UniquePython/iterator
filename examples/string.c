#include "string_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== String Iterator ===\n");
    char *string = "hello";
    Iterator stringIt = newStringIterator(string);
    printAll(stringIt, sizeof(char), printChar);
    IteratorDestroy(&stringIt);

    return 0;
}
