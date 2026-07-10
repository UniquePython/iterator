#include "range_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Range Iterator: inclusive ===\n");
    ForEachConsumer(
        NewRangeIterator(2, 10, 2, true),
        sizeof(int64_t),
        printI64);

    printf("\n=== Range Iterator: exclusive ===\n");
    ForEachConsumer(
        NewRangeIterator(2, 10, 2, false),
        sizeof(int64_t),
        printI64);

    return 0;
}
