#include "string_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== String Iterator ===\n");
    char *string = "hello";
    Iterator stringIt = NewStringIterator(string);
    ForEachConsumer(stringIt, sizeof(char), printChar);

    return 0;
}
