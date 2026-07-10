#ifndef FILTER_ITERATOR_H_
#define FILTER_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct filter_iterator_t FilterIterator;

bool FilterIteratorNext(void *restrict state, void *restrict out);
void FilterIteratorDestroy(void *state);
Iterator NewFilterIterator(size_t inElemSize, Iterator inner, bool (*condition)(const void *));

/* Build a filter iterator directly over a real array, inferring inElemSize
   and array length. `arr` must be an actual array in scope, not a decayed
   pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define FILTER_ARR(arr, condition) NewFilterIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr), (condition))

#endif
