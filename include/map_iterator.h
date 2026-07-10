#ifndef MAP_ITERATOR_H_
#define MAP_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct map_iterator_t MapIterator;

bool MapIteratorNext(void *restrict state, void *restrict out);
void MapIteratorDestroy(void *state);
Iterator NewMapIterator(size_t inElemSize, Iterator inner, void (*transform)(const void *restrict in, void *restrict out));

/* Build a map iterator directly over a real array, inferring inElemSize
   and array length. `arr` must be an actual array in scope, not a decayed
   pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define MAP_ARR(arr, transform) NewMapIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr), (transform))

#endif
