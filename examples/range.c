#include "range_iterator.h"
#include "iterator.h"
#include "common/helpers.h"

int main(void)
{
    printf("\n=== Range Iterator: inclusive ===\n");
    Iterator rangeItInc = NewRangeIterator(2, 10, 2, true);
    printAll(rangeItInc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItInc);

    printf("\n=== Range Iterator: exclusive ===\n");
    Iterator rangeItExc = NewRangeIterator(2, 10, 2, false);
    printAll(rangeItExc, sizeof(int64_t), printI64);
    IteratorDestroy(&rangeItExc);

    return 0;
}
