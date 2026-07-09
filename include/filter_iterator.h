#ifndef FILTER_ITERATOR_H_
#define FILTER_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct filter_iterator_t FilterIterator;

bool FilterIteratorNext(void *state, void *out);
void FilterIteratorDestroy(void *state);
Iterator NewFilterIterator(size_t inElemSize, Iterator inner, bool (*condition)(void *));

#endif