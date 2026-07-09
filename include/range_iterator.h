#ifndef RANGE_ITERATOR_H_
#define RANGE_ITERATOR_H_

#include "iterator.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct range_iterator_t RangeIterator;

bool RangeIteratorNext(void *state, void *out);
void RangeIteratorDestroy(void *state);
Iterator newRangeIterator(int64_t start, int64_t stop, int64_t step, bool inclusive);

#endif