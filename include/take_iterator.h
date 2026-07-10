#ifndef TAKE_ITERATOR_H_
#define TAKE_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct take_iterator_t TakeIterator;

bool TakeIteratorNext(void *restrict state, void *restrict out);
void TakeIteratorDestroy(void *state);
Iterator NewTakeIterator(size_t inElemSize, Iterator inner, size_t nToYield);

/* Build a take iterator directly over a real array, inferring inElemSize
   and array length. `arr` must be an actual array in scope, not a decayed
   pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define TAKE_ARR(arr, nToYield) NewTakeIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr), (nToYield))

#endif
