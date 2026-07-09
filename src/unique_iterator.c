#include "unique_iterator.h"

#include <stdlib.h>
#include <string.h>

struct unique_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    bool (*equals)(const void *a, const void *b);

    void *seen;
    size_t seenCount;
    size_t seenCapacity;
};

bool UniqueIteratorNext(void *state, void *out)
{
    UniqueIterator *uniqueIt = (UniqueIterator *)state;

    if (!out || !uniqueIt->equals)
        return false;

    while (uniqueIt->inner.next(uniqueIt->inner.state, uniqueIt->buffer))
    {
        bool duplicate = false;

        char *base = (char *)uniqueIt->seen;

        for (size_t i = 0; i < uniqueIt->seenCount; i++)
        {
            void *seenElem = base + (i * uniqueIt->inElemSize);

            if (uniqueIt->equals(uniqueIt->buffer, seenElem))
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
            continue;

        if (uniqueIt->seenCount == uniqueIt->seenCapacity)
        {
            size_t newCapacity = uniqueIt->seenCapacity == 0 ? 8 : uniqueIt->seenCapacity * 2;

            void *newSeen = realloc(uniqueIt->seen, newCapacity * uniqueIt->inElemSize);

            if (!newSeen)
                return false;

            uniqueIt->seen = newSeen;
            uniqueIt->seenCapacity = newCapacity;
            base = (char *)uniqueIt->seen;
        }

        void *dest = base + (uniqueIt->seenCount * uniqueIt->inElemSize);

        memcpy(dest, uniqueIt->buffer, uniqueIt->inElemSize);
        uniqueIt->seenCount++;

        memcpy(out, uniqueIt->buffer, uniqueIt->inElemSize);
        return true;
    }

    return false;
}

void UniqueIteratorDestroy(void *state)
{
    UniqueIterator *uniqueIt = (UniqueIterator *)state;
    free(uniqueIt->buffer);
    free(uniqueIt->seen);
    free(uniqueIt);
}

Iterator NewUniqueIterator(size_t inElemSize, Iterator inner, bool (*equals)(const void *, const void *))
{
    Iterator iterator = {0};

    UniqueIterator *uniqueIterator = malloc(sizeof *uniqueIterator);

    if (!uniqueIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(uniqueIterator);
        return iterator;
    }

    uniqueIterator->inElemSize = inElemSize;
    uniqueIterator->buffer = buffer;
    uniqueIterator->inner = inner;
    uniqueIterator->equals = equals;

    uniqueIterator->seen = NULL;
    uniqueIterator->seenCount = 0;
    uniqueIterator->seenCapacity = 0;

    iterator.state = uniqueIterator;
    iterator.next = UniqueIteratorNext;
    iterator.destroy = UniqueIteratorDestroy;

    return iterator;
}
