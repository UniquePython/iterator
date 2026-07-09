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
void printAll(Iterator iterator, size_t elemSize, void (*print)(const void *elem));

#endif