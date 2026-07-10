#ifndef ARRAY_ITERATOR_H_
#define ARRAY_ITERATOR_H_

#include "iterator.h"
#include "builtins.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct array_iterator_t ArrayIterator;

bool ArrayIteratorNext(void *restrict state, void *restrict out);
void ArrayIteratorDestroy(void *state);
Iterator NewArrayIterator(size_t elemSize, const void *arr, size_t arrLen);

#define NEW_ARRAY_ITERATOR(arr) NewArrayIterator(sizeof(*(arr)), (arr), ARRAY_LEN(arr))

#endif