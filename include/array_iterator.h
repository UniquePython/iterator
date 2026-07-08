#ifndef ARRAY_ITERATOR_H_
#define ARRAY_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct array_iterator_t ArrayIterator;

bool ArrayIteratorNext(void *state, void *out);
void ArrayIteratorDestroy(void *state);
Iterator newArrayIterator(size_t elemSize, void *arr, size_t arrLen);

#endif