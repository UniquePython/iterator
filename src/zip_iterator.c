#include "zip_iterator.h"

#include <stdlib.h>
#include <string.h>

struct zip_iterator_t
{
    size_t elemSizeA;
    void *bufferA;
    Iterator innerA;

    size_t elemSizeB;
    void *bufferB;
    Iterator innerB;
};

bool ZipIteratorNext(void *restrict state, void *restrict out)
{
    if (!state)
        return false;

    ZipIterator *zipIt = (ZipIterator *)state;

    if (!out)
        return false;

    ZippedItem *item = (ZippedItem *)out;

    if (!zipIt->innerA.next(zipIt->innerA.state, zipIt->bufferA))
        return false;

    if (!zipIt->innerB.next(zipIt->innerB.state, zipIt->bufferB))
        return false;

    item->a = zipIt->bufferA;
    item->b = zipIt->bufferB;

    return true;
}

void ZipIteratorDestroy(void *state)
{
    if (!state)
        return;

    ZipIterator *zipIt = (ZipIterator *)state;
    free(zipIt->bufferA);
    free(zipIt->bufferB);
    IteratorDestroy(&zipIt->innerA);
    IteratorDestroy(&zipIt->innerB);
    free(zipIt);
}

Iterator NewZipIterator(size_t elemSizeA, Iterator innerA, size_t elemSizeB, Iterator innerB)
{
    Iterator iterator = {0};

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

    if (elemSizeA == 0 || elemSizeB == 0)
        return iterator;

    ZipIterator *zipIterator = malloc(sizeof *zipIterator);

    if (!zipIterator)
    {
        IteratorDestroy(&innerA);
        IteratorDestroy(&innerB);
        return iterator;
    }

    void *bufferA = malloc(elemSizeA);

    if (!bufferA)
    {
        free(zipIterator);
        IteratorDestroy(&innerA);
        IteratorDestroy(&innerB);
        return iterator;
    }

    void *bufferB = malloc(elemSizeB);

    if (!bufferB)
    {
        free(bufferA);
        free(zipIterator);
        IteratorDestroy(&innerA);
        IteratorDestroy(&innerB);
        return iterator;
    }

    zipIterator->elemSizeA = elemSizeA;
    zipIterator->bufferA = bufferA;
    zipIterator->innerA = innerA;

    zipIterator->elemSizeB = elemSizeB;
    zipIterator->bufferB = bufferB;
    zipIterator->innerB = innerB;

    return NewIterator(zipIterator, ZipIteratorNext, ZipIteratorDestroy);
}
