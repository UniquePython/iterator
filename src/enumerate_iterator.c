#include "enumerate_iterator.h"

#include <stdlib.h>
#include <string.h>

struct enumerate_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    size_t index;
};

bool EnumerateIteratorNext(void *restrict state, void *restrict out)
{
    EnumerateIterator *enumerateIt = (EnumerateIterator *)state;

    if (!out)
        return false;

    EnumeratedItem *item = (EnumeratedItem *)out;

    if (!enumerateIt->inner.next(enumerateIt->inner.state, enumerateIt->buffer))
        return false;

    item->index = enumerateIt->index++;
    item->value = enumerateIt->buffer;

    return true;
}

void EnumerateIteratorDestroy(void *state)
{
    EnumerateIterator *enumerateIt = (EnumerateIterator *)state;
    free(enumerateIt->buffer);
    IteratorDestroy(&enumerateIt->inner);
    free(enumerateIt);
}

Iterator NewEnumerateIterator(size_t inElemSize, Iterator inner)
{
    Iterator iterator = {0};

    EnumerateIterator *enumerateIterator = malloc(sizeof *enumerateIterator);

    if (!enumerateIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(enumerateIterator);
        return iterator;
    }

    enumerateIterator->inElemSize = inElemSize;
    enumerateIterator->buffer = buffer;
    enumerateIterator->inner = inner;
    enumerateIterator->index = 0;

    iterator.state = enumerateIterator;
    iterator.next = EnumerateIteratorNext;
    iterator.destroy = EnumerateIteratorDestroy;

    return iterator;
}
