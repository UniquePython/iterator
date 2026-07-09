#include "consumer.h"

#include <stdlib.h>

size_t CountConsumer(Iterator iterator, size_t elemSize)
{
    size_t count = 0;

    void *out = malloc(elemSize);
    if (!out)
        return count;

    while (iterator.next(iterator.state, out))
        count++;

    free(out);

    return count;
}