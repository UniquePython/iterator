#include "consumers.h"

#include <stdlib.h>
#include <string.h>

size_t CountConsumer(Iterator iterator, size_t elemSize)
{
    size_t count = 0;

    void *out = malloc(elemSize);
    if (!out)
    {
        IteratorDestroy(&iterator);
        return count;
    }

    while (iterator.next(iterator.state, out))
        count++;

    free(out);

    return count;
}

bool FindConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem), void *out)
{
    void *buffer = malloc(elemSize);
    if (!buffer)
    {
        IteratorDestroy(&iterator);
        return false;
    }

    while (iterator.next(iterator.state, buffer))
    {
        if (condition(buffer))
        {
            memcpy(out, buffer, elemSize);
            IteratorDestroy(&iterator);
            free(buffer);
            return true;
        }
    }

    IteratorDestroy(&iterator);
    free(buffer);

    return false;
}

bool AnyConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem))
{
    void *buffer = malloc(elemSize);
    if (!buffer)
    {
        IteratorDestroy(&iterator);
        return false;
    }

    while (iterator.next(iterator.state, buffer))
    {
        if (condition(buffer))
        {
            IteratorDestroy(&iterator);
            free(buffer);
            return true;
        }
    }

    IteratorDestroy(&iterator);
    free(buffer);

    return false;
}

bool AllConsumer(Iterator iterator, size_t elemSize, bool (*condition)(const void *elem))
{
    void *buffer = malloc(elemSize);
    if (!buffer)
    {
        IteratorDestroy(&iterator);
        return false;
    }

    while (iterator.next(iterator.state, buffer))
    {
        if (!condition(buffer))
        {
            IteratorDestroy(&iterator);
            free(buffer);
            return false;
        }
    }

    IteratorDestroy(&iterator);
    free(buffer);

    return true;
}