#include "range_iterator.h"

#include <stdlib.h>
#include <string.h>

typedef int64_t i64;

struct range_iterator_t
{
    i64 start;
    i64 stop;
    i64 step;
    i64 current;
    bool inclusive;
};

bool RangeIteratorNext(void *state, void *out)
{
    RangeIterator *rangeIt = (RangeIterator *)state;

    bool inBounds;
    if (rangeIt->inclusive)
        inBounds = (rangeIt->step > 0)   ? (rangeIt->current <= rangeIt->stop)
                   : (rangeIt->step < 0) ? (rangeIt->current >= rangeIt->stop)
                                         : true; // step == 0: always in bounds, infinite repeat
    else
        inBounds = (rangeIt->step > 0)   ? (rangeIt->current < rangeIt->stop)
                   : (rangeIt->step < 0) ? (rangeIt->current > rangeIt->stop)
                                         : true; // step == 0: always in bounds, infinite repeat

    if (!inBounds)
        return false;

    *(i64 *)out = rangeIt->current;
    rangeIt->current += rangeIt->step;
    return true;
}

void RangeIteratorDestroy(void *state)
{
    free(state);
}

Iterator newRangeIterator(int64_t start, int64_t stop, int64_t step, bool inclusive)
{
    Iterator iterator = {0};

    RangeIterator *rangeIterator = malloc(sizeof *rangeIterator);

    if (!rangeIterator)
        return iterator;

    rangeIterator->start = start;
    rangeIterator->stop = stop;
    rangeIterator->step = step;
    rangeIterator->current = start;
    rangeIterator->inclusive = inclusive;

    iterator.state = rangeIterator;
    iterator.next = RangeIteratorNext;
    iterator.destroy = RangeIteratorDestroy;

    return iterator;
}
