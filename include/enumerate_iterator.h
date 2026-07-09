#ifndef ENUMERATE_ITERATOR_H_
#define ENUMERATE_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct enumerate_iterator_t EnumerateIterator;

typedef struct enumerated_item_t
{
    size_t index;
    void *value;

} EnumeratedItem;

bool EnumerateIteratorNext(void *restrict state, void *restrict out);
void EnumerateIteratorDestroy(void *state);
Iterator NewEnumerateIterator(size_t inElemSize, Iterator inner);

#endif