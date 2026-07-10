#include "filter_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Filter Iterator ===\n");
    int intArr[] = {1, 2, 3, 4};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator filterIt = NewFilterIterator(sizeof(int), intIt, isEven);
    ForEachConsumer(filterIt, sizeof(int), printInt);

    return 0;
}
