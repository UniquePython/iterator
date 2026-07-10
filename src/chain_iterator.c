#include "chain_iterator.h"

#include <stdlib.h>
#include <string.h>

struct chain_iterator_t
{
    size_t elemSize;
    void *buffer;
    Iterator innerA;
    Iterator innerB;
};

bool ChainIteratorNext(void *restrict state, void *restrict out)
{
    if (!state)
        return false;

    ChainIterator *chainIt = (ChainIterator *)state;

    if (!out)
        return false;

    if (!chainIt->innerA.next(chainIt->innerA.state, chainIt->buffer))
        if (!chainIt->innerB.next(chainIt->innerB.state, chainIt->buffer))
            return false;

    memcpy(out, chainIt->buffer, chainIt->elemSize);

    return true;
}

void ChainIteratorDestroy(void *state)
{
    if (!state)
        return;

    ChainIterator *chainIt = (ChainIterator *)state;
    free(chainIt->buffer);
    IteratorDestroy(&chainIt->innerA);
    IteratorDestroy(&chainIt->innerB);
    free(chainIt);
}

Iterator NewChainIterator(size_t inElemSize, Iterator innerA, Iterator innerB)
{
    Iterator iterator = {0};

    if (inElemSize == 0)
        return iterator;

    if (IteratorRejectIfInvalid(&innerA))
    {
        IteratorDestroy(&innerB);
        return iterator;
    }

    if (IteratorRejectIfInvalid(&innerB))
    {
        IteratorDestroy(&innerA);
        return iterator;
    }

    ChainIterator *chainIterator = malloc(sizeof *chainIterator);

    if (!chainIterator)
    {
        IteratorDestroy(&innerA);
        IteratorDestroy(&innerB);
        return iterator;
    }

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(chainIterator);
        IteratorDestroy(&innerA);
        IteratorDestroy(&innerB);
        return iterator;
    }

    chainIterator->elemSize = inElemSize;
    chainIterator->buffer = buffer;
    chainIterator->innerA = innerA;
    chainIterator->innerB = innerB;

    return NewIterator(chainIterator, ChainIteratorNext, ChainIteratorDestroy);
}
