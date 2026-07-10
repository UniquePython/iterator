#include "skip_iterator.h"

#include <stdlib.h>
#include <string.h>

struct skip_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    size_t nToSkip;
    size_t nSkipped;
};

bool SkipIteratorNext(void *restrict state, void *restrict out)
{
    if (!state)
        return false;

    SkipIterator *skipIt = (SkipIterator *)state;

    if (!out)
        return false;

    while (skipIt->nSkipped < skipIt->nToSkip)
    {
        skipIt->nSkipped++;
        if (!skipIt->inner.next(skipIt->inner.state, skipIt->buffer))
            return false;
    }

    if (skipIt->inner.next(skipIt->inner.state, skipIt->buffer))
    {
        memcpy(out, skipIt->buffer, skipIt->inElemSize);
        return true;
    }

    return false;
}

void SkipIteratorDestroy(void *state)
{
    if (!state)
        return;

    SkipIterator *skipIt = (SkipIterator *)state;
    free(skipIt->buffer);
    IteratorDestroy(&skipIt->inner);
    free(skipIt);
}

Iterator NewSkipIterator(size_t inElemSize, Iterator inner, size_t nToSkip)
{
    Iterator iterator = {0};

    if (IteratorRejectIfInvalid(&inner))
        return iterator;

    if (inElemSize == 0)
        return iterator;

    SkipIterator *skipIterator = malloc(sizeof *skipIterator);

    if (!skipIterator)
    {
        IteratorDestroy(&inner);
        return iterator;
    }

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(skipIterator);
        IteratorDestroy(&inner);
        return iterator;
    }

    skipIterator->inElemSize = inElemSize;
    skipIterator->buffer = buffer;
    skipIterator->inner = inner;
    skipIterator->nToSkip = nToSkip;
    skipIterator->nSkipped = 0;

    return NewIterator(skipIterator, SkipIteratorNext, SkipIteratorDestroy);
}
