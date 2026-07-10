#include "take_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Take Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    ForEachConsumer(
        NewTakeIterator(
            sizeof(int),
            NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr),
            2),
        sizeof(int),
        printInt);

    return 0;
}
