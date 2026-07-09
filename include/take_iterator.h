#ifndef TAKE_ITERATOR_H_
#define TAKE_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct take_iterator_t TakeIterator;

bool TakeIteratorNext(void *state, void *out);
void TakeIteratorDestroy(void *state);
Iterator NewTakeIterator(size_t inElemSize, Iterator inner, size_t nToYield);

#endif