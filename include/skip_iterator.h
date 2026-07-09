#ifndef SKIP_ITERATOR_H_
#define SKIP_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct skip_iterator_t SkipIterator;

bool SkipIteratorNext(void *restrict state, void *restrict out);
void SkipIteratorDestroy(void *state);
Iterator NewSkipIterator(size_t inElemSize, Iterator inner, size_t nToSkip);

#endif