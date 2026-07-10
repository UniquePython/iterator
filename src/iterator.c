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

bool IteratorIsValid(Iterator iterator)
{
    return iterator.next != NULL;
}

bool IteratorRejectIfInvalid(Iterator *iterator)
{
    if (!iterator || IteratorIsValid(*iterator))
        return false;

    IteratorDestroy(iterator);
    return true;
}

Iterator NewIterator(void *state, bool (*next)(void *restrict state, void *restrict out), void (*destroy)(void *state))
{
    Iterator iterator = {0};

    if (!next)
    {
        if (destroy)
            destroy(state);
        return iterator;
    }

    iterator.state = state;
    iterator.next = next;
    iterator.destroy = destroy;

    return iterator;
}
