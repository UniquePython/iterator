#include "map_iterator.h"
#include "array_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Map Iterator ===\n");
    int intArr[] = {10, 20, 30, 40};
    Iterator intIt = NewArrayIterator(sizeof(int), intArr, sizeof intArr / sizeof *intArr);
    Iterator mapIt = NewMapIterator(sizeof(int), intIt, doubleInt);
    ForEachConsumer(mapIt, sizeof(int), printInt);

    return 0;
}
