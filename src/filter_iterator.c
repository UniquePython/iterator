#include "filter_iterator.h"

#include <stdlib.h>
#include <string.h>

struct filter_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    bool (*condition)(const void *elem);
};

bool FilterIteratorNext(void *restrict state, void *restrict out)
{
    FilterIterator *filterIt = (FilterIterator *)state;

    if (!out || !filterIt->condition)
        return false;

    while (filterIt->inner.next(filterIt->inner.state, filterIt->buffer))
    {
        if (filterIt->condition(filterIt->buffer))
        {
            memcpy(out, filterIt->buffer, filterIt->inElemSize);
            return true;
        }
    }

    return false;
}

void FilterIteratorDestroy(void *state)
{
    FilterIterator *filterIt = (FilterIterator *)state;
    free(filterIt->buffer);
    free(filterIt);
}

Iterator NewFilterIterator(size_t inElemSize, Iterator inner, bool (*condition)(const void *))
{
    Iterator iterator = {0};

    FilterIterator *filterIterator = malloc(sizeof *filterIterator);

    if (!filterIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(filterIterator);
        return iterator;
    }

    filterIterator->inElemSize = inElemSize;
    filterIterator->buffer = buffer;
    filterIterator->inner = inner;
    filterIterator->condition = condition;

    iterator.state = filterIterator;
    iterator.next = FilterIteratorNext;
    iterator.destroy = FilterIteratorDestroy;

    return iterator;
}
