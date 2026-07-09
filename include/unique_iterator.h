#ifndef UNIQUE_ITERATOR_H_
#define UNIQUE_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct unique_iterator_t UniqueIterator;

bool UniqueIteratorNext(void *state, void *out);
void UniqueIteratorDestroy(void *state);
Iterator NewUniqueIterator(size_t inElemSize, Iterator inner, bool (*equal)(const void *, const void *));

#endif