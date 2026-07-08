#include "array_iterator.h"

#include <stdlib.h>
#include <string.h>

struct array_iterator_t
{
    size_t elemSize;
    void *arr;
    size_t len;
    size_t currIdx;
};

bool ArrayIteratorNext(void *state, void *out)
{
    ArrayIterator *arrIt = (ArrayIterator *)state;

    if (!arrIt || !out || arrIt->currIdx >= arrIt->len)
        return false;

    char *base = (char *)arrIt->arr;
    void *srcElem = base + (arrIt->elemSize * arrIt->currIdx);

    memcpy(out, srcElem, arrIt->elemSize);

    arrIt->currIdx++;
    return true;
}

void ArrayIteratorDestroy(void *state)
{
    free(state);
}

Iterator newArrayIterator(size_t elemSize, void *arr, size_t arrLen)
{
    Iterator iterator = {0};

    ArrayIterator *arrayIterator = malloc(sizeof *arrayIterator);

    if (!arrayIterator)
        return iterator;

    arrayIterator->elemSize = elemSize;
    arrayIterator->arr = arr;
    arrayIterator->len = arrLen;
    arrayIterator->currIdx = 0;

    iterator.state = arrayIterator;
    iterator.next = ArrayIteratorNext;
    iterator.destroy = ArrayIteratorDestroy;

    return iterator;
}