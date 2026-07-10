#include "string_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "builtins.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== String Iterator ===\n");
    const char *string = "hello";
    ForEachConsumer(
        NewStringIterator(string),
        sizeof(char),
        CharPrint);

    return 0;
}
