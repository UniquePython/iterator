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

bool ChainIteratorNext(void *state, void *out)
{
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
    ChainIterator *chainIt = (ChainIterator *)state;
    free(chainIt->buffer);
    free(chainIt);
}

Iterator NewChainIterator(size_t inElemSize, Iterator innerA, Iterator innerB)
{
    Iterator iterator = {0};

    ChainIterator *chainIterator = malloc(sizeof *chainIterator);

    if (!chainIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(chainIterator);
        return iterator;
    }

    chainIterator->elemSize = inElemSize;
    chainIterator->buffer = buffer;
    chainIterator->innerA = innerA;
    chainIterator->innerB = innerB;

    iterator.state = chainIterator;
    iterator.next = ChainIteratorNext;
    iterator.destroy = ChainIteratorDestroy;

    return iterator;
}
