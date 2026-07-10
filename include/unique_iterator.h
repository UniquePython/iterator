#ifndef UNIQUE_ITERATOR_H_
#define UNIQUE_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct unique_iterator_t UniqueIterator;

bool UniqueIteratorNext(void *restrict state, void *restrict out);
void UniqueIteratorDestroy(void *state);
Iterator NewUniqueIterator(size_t inElemSize, Iterator inner, bool (*equal)(const void *restrict a, const void *restrict b));

/* Build a unique iterator directly over a real array, inferring inElemSize
   and array length. `arr` must be an actual array in scope, not a decayed
   pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define UNIQUE_ARR(arr, equal) NewUniqueIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr), (equal))

#endif
