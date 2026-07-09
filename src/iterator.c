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
