#include "string_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== String Iterator ===\n");
    char *string = "hello";
    ForEachConsumer(
        NewStringIterator(string),
        sizeof(char),
        printChar);

    return 0;
}
