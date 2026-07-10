#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <stddef.h>
#include <stdbool.h>

#define DEREF(type, ptr) (*(type *)(ptr))

typedef struct iterator_t
{
    void *state;
    bool (*next)(void *restrict state, void *restrict out);
    void (*destroy)(void *state);
} Iterator;

void IteratorDestroy(Iterator *iterator);
bool IteratorIsValid(Iterator iterator);
bool IteratorRejectIfInvalid(Iterator *iterator);
Iterator NewIterator(void *state, bool (*next)(void *restrict state, void *restrict out), void (*destroy)(void *state));

#endif