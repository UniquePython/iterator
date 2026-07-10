#ifndef ENUMERATE_ITERATOR_H_
#define ENUMERATE_ITERATOR_H_

#include "iterator.h"
#include "array_iterator.h"

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

/* Build an enumerate iterator directly over a real array, inferring
   inElemSize and array length. `arr` must be an actual array in scope,
   not a decayed pointer (same constraint as NEW_ARRAY_ITERATOR). */
#define ENUMERATE_ARR(arr) NewEnumerateIterator(sizeof(*(arr)), NEW_ARRAY_ITERATOR(arr))

#endif
