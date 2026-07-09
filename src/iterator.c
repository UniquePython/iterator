#include "iterator.h"

#include <stdlib.h>

void IteratorDestroy(Iterator *iterator)
{
    if (!iterator || !iterator->destroy)
        return;

    iterator->destroy(iterator->state);

    iterator->state = NULL;
    iterator->next = NULL;
    iterator->destroy = NULL;
}

void printAll(Iterator iterator, size_t elemSize, void (*print)(const void *elem))
{
    void *out = malloc(elemSize);
    if (!out)
        return;

    while (iterator.next(iterator.state, out))
        print(out);

    free(out);
}
