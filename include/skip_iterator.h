#ifndef SKIP_ITERATOR_H_
#define SKIP_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct skip_iterator_t SkipIterator;

bool SkipIteratorNext(void *restrict state, void *restrict out);
void SkipIteratorDestroy(void *state);
Iterator NewSkipIterator(size_t inElemSize, Iterator inner, size_t nToSkip);

/* Build a skip iterator directly over a real array, inferring inElemSize
   and array length. `arr` must be an actual array in scope, not a decayed
   pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define SKIP_ARR(arr, nToSkip) NewSkipIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr), (nToSkip))

#endif
