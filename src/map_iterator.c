#include "map_iterator.h"

#include <stdlib.h>
#include <string.h>

struct map_iterator_t
{
    size_t inElemSize;
    void *buffer;
    Iterator inner;
    void (*transform)(const void *restrict in, void *restrict out);
};

bool MapIteratorNext(void *restrict state, void *restrict out)
{
    MapIterator *mapIt = (MapIterator *)state;

    if (!out || !mapIt->transform)
        return false;

    if (mapIt->inner.next(mapIt->inner.state, mapIt->buffer))
    {
        mapIt->transform(mapIt->buffer, out);
        return true;
    }

    return false;
}

void MapIteratorDestroy(void *state)
{
    MapIterator *mapIt = (MapIterator *)state;
    free(mapIt->buffer);
    IteratorDestroy(&mapIt->inner);
    free(mapIt);
}

Iterator NewMapIterator(size_t inElemSize, Iterator inner, void (*transform)(const void *restrict in, void *restrict out))
{
    Iterator iterator = {0};

    MapIterator *mapIterator = malloc(sizeof *mapIterator);

    if (!mapIterator)
        return iterator;

    void *buffer = malloc(inElemSize);

    if (!buffer)
    {
        free(mapIterator);
        return iterator;
    }

    mapIterator->inElemSize = inElemSize;
    mapIterator->buffer = buffer;
    mapIterator->inner = inner;
    mapIterator->transform = transform;

    iterator.state = mapIterator;
    iterator.next = MapIteratorNext;
    iterator.destroy = MapIteratorDestroy;

    return iterator;
}
