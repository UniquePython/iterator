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

bool TakeIteratorNext(void *restrict state, void *restrict out)
{
    if (!state)
        return false;

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
    if (!state)
        return;

    TakeIterator *takeIt = (TakeIterator *)state;
    free(takeIt->buffer);
    IteratorDestroy(&takeIt->inner);
    free(takeIt);
}

Iterator NewTakeIterator(size_t inElemSize, Iterator inner, size_t nToYield)
{
    Iterator iterator = {0};

    if (IteratorRejectIfInvalid(&inner))
        return iterator;

    if (inElemSize == 0)
        return iterator;

    TakeIterator *takeIterator = malloc(sizeof *takeIterator);

    if (!takeIterator)
    {
        IteratorDestroy(&inner);
        return iterator;
    }

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(takeIterator);
        IteratorDestroy(&inner);
        return iterator;
    }

    takeIterator->inElemSize = inElemSize;
    takeIterator->buffer = buffer;
    takeIterator->inner = inner;
    takeIterator->nToYield = nToYield;
    takeIterator->nYielded = 0;

    return NewIterator(takeIterator, TakeIteratorNext, TakeIteratorDestroy);
}
