#include "range_iterator.h"
#include "iterator.h"
#include "consumers.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Range Iterator: inclusive ===\n");
    Iterator rangeItInc = NewRangeIterator(2, 10, 2, true);
    ForEachConsumer(rangeItInc, sizeof(int64_t), printI64);

    printf("\n=== Range Iterator: exclusive ===\n");
    Iterator rangeItExc = NewRangeIterator(2, 10, 2, false);
    ForEachConsumer(rangeItExc, sizeof(int64_t), printI64);

    return 0;
}
