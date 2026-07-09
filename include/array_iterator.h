#ifndef ARRAY_ITERATOR_H_
#define ARRAY_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct array_iterator_t ArrayIterator;

bool ArrayIteratorNext(void *restrict state, void *restrict out);
void ArrayIteratorDestroy(void *state);
Iterator NewArrayIterator(size_t elemSize, void *arr, size_t arrLen);

#endif