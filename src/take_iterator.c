#include "take_iterator.h"

#include <stdlib.h>
#include <string.h>

struct take_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    size_t nToYield;
    size_t nYielded;
};

bool TakeIteratorNext(void *state, void *out)
{
    TakeIterator *takeIt = (TakeIterator *)state;

    if (!out)
        return false;

    if (takeIt->nYielded >= takeIt->nToYield)
        return false;

    if (takeIt->inner.next(takeIt->inner.state, takeIt->buffer))
    {
        memcpy(out, takeIt->buffer, takeIt->inElemSize);
        takeIt->nYielded++;
        return true;
    }

    return false;
}

void TakeIteratorDestroy(void *state)
{
    TakeIterator *takeIt = (TakeIterator *)state;
    free(takeIt->buffer);
    free(takeIt);
}

Iterator newTakeIterator(size_t inElemSize, Iterator inner, size_t nToYield)
{
    Iterator iterator = {0};

    TakeIterator *takeIterator = malloc(sizeof *takeIterator);

    if (!takeIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(takeIterator);
        return iterator;
    }

    takeIterator->inElemSize = inElemSize;
    takeIterator->buffer = buffer;
    takeIterator->inner = inner;
    takeIterator->nToYield = nToYield;
    takeIterator->nYielded = 0;

    iterator.state = takeIterator;
    iterator.next = TakeIteratorNext;
    iterator.destroy = TakeIteratorDestroy;

    return iterator;
}
